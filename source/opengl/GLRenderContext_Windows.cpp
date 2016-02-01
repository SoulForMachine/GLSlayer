
#include <cassert>
#include "GLSlayer/RenderContextInit.h"
#include "GLRenderContext.h"


using namespace gls;


static
LRESULT CALLBACK TmpWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_CREATE:
		return 0;
	case WM_DESTROY:
		return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


IRenderContext* gls::CreateRenderContext(const CreateContextInfo& info)
{
	GLRenderContext* render_context = new GLRenderContext(info.logger);
	bool result = render_context->Create(info.version, info.instanceHandle, info.windowHandle, *info.format, info.debugContext);
	if(!result)
	{
		delete render_context;
		render_context = 0;
	}
	return render_context;
}

void gls::DestroyRenderContext(IRenderContext* render_context)
{
	if(render_context)
	{
		static_cast<GLRenderContext*>(render_context)->Destroy();
		delete render_context;
	}
}


bool GLRenderContext::Create(uint version, HINSTANCE instance_handle, HWND window_handle, const FramebufferFormat& format, bool debug_context)
{
	if(_initialized)
		return false;

	if(version < 330)
	{
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_UNSUPPORTED_VERSION);
		return false;
	}

	_instanceHandle = instance_handle;
	_hwnd = window_handle;

	BOOL result;
	TCHAR tmp_wnd_class[] = TEXT("GLSlayer_init_TempWndClass");

	// create temporary window
	WNDCLASS wc;
	memset(&wc, 0, sizeof(wc));
	wc.hInstance = _instanceHandle;
	wc.lpfnWndProc = TmpWindowProc;
	wc.lpszClassName = tmp_wnd_class;
	wc.style = CS_OWNDC;

	result = RegisterClass(&wc);
	if(!result)
	{
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_TEMPORARY_CONTEXT, "could not register window class");
		return false;
	}

	HWND tmp_hwnd =	CreateWindow(	tmp_wnd_class, TEXT(""),
		WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		0, 0, _instanceHandle, 0	);

	if(!tmp_hwnd)
	{
		UnregisterClass(tmp_wnd_class, _instanceHandle);
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_TEMPORARY_CONTEXT, "could not create window");
		return false;
	}

	// create temporary OpenGL context
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(pfd));
	pfd.nVersion = 1;
	pfd.nSize = sizeof(pfd);
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 16;

	HDC tmp_dc = GetDC(tmp_hwnd);
	if(!tmp_dc)
	{
		DestroyWindow(tmp_hwnd);
		UnregisterClass(tmp_wnd_class, _instanceHandle);
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_TEMPORARY_CONTEXT, "could not get window DC");
		return false;
	}

	int pixel_format = ChoosePixelFormat(tmp_dc, &pfd);
	if(!pixel_format)
	{
		DestroyWindow(tmp_hwnd);
		UnregisterClass(tmp_wnd_class, _instanceHandle);
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_TEMPORARY_CONTEXT, "ChoosePixelFormat");
		return false;
	}

	result = SetPixelFormat(tmp_dc, pixel_format, &pfd);
	if(!result)
	{
		DestroyWindow(tmp_hwnd);
		UnregisterClass(tmp_wnd_class, _instanceHandle);
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_TEMPORARY_CONTEXT, "SetPixelFormat");
		return false;
	}

	HGLRC tmp_rc = wglCreateContext(tmp_dc);
	if(!tmp_rc)
	{
		DestroyWindow(tmp_hwnd);
		UnregisterClass(tmp_wnd_class, _instanceHandle);
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_TEMPORARY_CONTEXT, "wglCreateContext");
		return false;
	}

	result = wglMakeCurrent(tmp_dc, tmp_rc);
	if(!result)
	{
		wglDeleteContext(tmp_rc);
		DestroyWindow(tmp_hwnd);
		UnregisterClass(tmp_wnd_class, _instanceHandle);
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_TEMPORARY_CONTEXT, "wglMakeCurrent");
		return false;
	}

	result = CreateContext(version, format, debug_context);

	// destroy temporary rendering context and window
	wglMakeCurrent(0, 0);
	wglDeleteContext(tmp_rc);
	DestroyWindow(tmp_hwnd);
	UnregisterClass(tmp_wnd_class, _instanceHandle);

	if(!result)
	{
		return false;
	}

	result = wglMakeCurrent(_hdc, _hglrc);
	if(!result)
	{
		Destroy();
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version, "wglMakeCurrent");
		return false;
	}

	return InitCommon(version);
}

bool GLRenderContext::CreateContext(uint version, const FramebufferFormat& format, bool debug_context)
{
	BOOL result;
	HDC hdc = GetDC(_hwnd);
	if(!hdc)
	{
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version, "could not get window DC");
		return false;
	}

	// create rendering context with WGL_ARB_pixel_format extension
	if(!IsExtSupported("WGL_ARB_pixel_format"))
	{
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version, "WGL_ARB_pixel_format not supported.");
		return false;
	}

	if(!glextLoad_WGL_ARB_pixel_format())
	{
		DebugMessage(
			DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version,
			"the driver does not have all function entries for WGL_ARB_pixel_format");
		return false;
	}

	// check if WGL_EXT_framebuffer_sRGB is supported
	bool sRGB = IsExtSupported("WGL_EXT_framebuffer_sRGB");

	UINT num_formats;
	int pixel_format;
	int int_atribs[] =
	{
		WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
		WGL_DRAW_TO_WINDOW_ARB, TRUE,
		WGL_SUPPORT_OPENGL_ARB, TRUE,
		WGL_DOUBLE_BUFFER_ARB, format.doubleBuffer? 1 : 0,
		WGL_SWAP_METHOD_ARB, (int)GetGLEnum(format.swapMethod),
		WGL_PIXEL_TYPE_ARB, (int)GetGLEnum(format.colorBufferType),
		WGL_COLOR_BITS_ARB, format.colorBits,
		WGL_DEPTH_BITS_ARB, format.depthBits,
		WGL_STENCIL_BITS_ARB, format.stencilBits,
		WGL_SAMPLE_BUFFERS_ARB, format.multisampleSamples? 1 : 0,
		WGL_SAMPLES_ARB, format.multisampleSamples,
		(sRGB? WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT: 0), (sRGB? (format.sRGB? GL_TRUE: GL_FALSE): 0),
		0, 0
	};
	result = wglChoosePixelFormatARB(hdc, int_atribs, 0, 1, &pixel_format, &num_formats);
	if(!result || num_formats < 1)
	{
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version, "wglChoosePixelFormatARB");
		return false;
	}

	PIXELFORMATDESCRIPTOR pfd;
	result = DescribePixelFormat(hdc, pixel_format, sizeof(pfd), &pfd);
	if(!result)
	{
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version, "DescribePixelFormat");
		return false;
	}

	result = SetPixelFormat(hdc, pixel_format, &pfd);
	if(!result)
	{
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version, "SetPixelFormat");
		return false;
	}

	HGLRC hglrc = 0;
	if(	IsExtSupported("WGL_ARB_create_context") &&
		glextLoad_WGL_ARB_create_context() &&
		wglCreateContextAttribsARB != 0 )
	{
		int context_flags = (version >= 300) ? WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB : 0;
		if(debug_context)
			context_flags |= WGL_CONTEXT_DEBUG_BIT_ARB;
		int attribs[] =
		{
			WGL_CONTEXT_MAJOR_VERSION_ARB, (int)version / 100,
			WGL_CONTEXT_MINOR_VERSION_ARB, (int)version % 100 / 10,
			WGL_CONTEXT_FLAGS_ARB, context_flags,
			0
		};
		hglrc = wglCreateContextAttribsARB(hdc, 0, attribs);
	}
	else
	{
		DebugMessage(
			DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version,
			"extension WGL_ARB_create_context not supported, cannot create forward compatible context");
	}

	if(hglrc)
	{
		_hglrc = hglrc;
		_hdc = hdc;
		_info.framebufferFormat = format;
		return true;
	}
	else
	{
		_hglrc = 0;
		_hdc = 0;
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version, "wglCreateContextAttribsARB");
		return false;
	}
}

void GLRenderContext::Destroy()
{
	if(_hglrc)
	{
		if(wglGetCurrentContext() == _hglrc)
		{
			wglMakeCurrent(0, 0);
		}
		wglDeleteContext(_hglrc);

		DeinitCommon();
	}
}

bool GLRenderContext::LoadPlatformOpenGLExtensions()
{
	bool result = true;

	// wgl extensions
	LOAD_EXTENSION_REQ(WGL_ARB_extensions_string);
	LOAD_EXTENSION_REQ(WGL_ARB_pixel_format);
	LOAD_EXTENSION(WGL_ARB_pixel_format_float);
	LOAD_EXTENSION_REQ(WGL_ARB_multisample);
	LOAD_EXTENSION_REQ(WGL_EXT_swap_control);
	LOAD_EXTENSION(WGL_EXT_framebuffer_sRGB);
	LOAD_EXTENSION(WGL_ARB_create_context);

	return result;
}

bool GLRenderContext::IsExtSupported(const char* extension)
{
	if(!extension || !extension[0])
		return false;

	PFNGLGETSTRINGIPROC ptr_glGetStringi = (PFNGLGETSTRINGIPROC)wglGetProcAddress("glGetStringi");
	if(ptr_glGetStringi)
	{
		GLint count = 0;
		glGetIntegerv(GL_NUM_EXTENSIONS, &count);
		for(int i = 0; i < count; ++i)
		{
			const char* ext_string = (const char*)ptr_glGetStringi(GL_EXTENSIONS, i);

			if(ext_string && !strcmp(ext_string, extension))
				return true;
		}
	}

	PFNWGLGETEXTENSIONSSTRINGARBPROC ptr_wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)wglGetProcAddress("wglGetExtensionsStringARB");
	if(ptr_wglGetExtensionsStringARB)
	{
		const char* ext_string = (const char*)ptr_wglGetExtensionsStringARB(wglGetCurrentDC());
		if(ext_string && strstr(ext_string, extension))
			return true;
	}

	return false;
}

bool GLRenderContext::SetCurrentContext()
{
	BOOL result = wglMakeCurrent(_hdc, _hglrc);
	return (result == TRUE);
}

void GLRenderContext::SwapBuffers()
{
	assert(_hdc && _hglrc);
	::SwapBuffers(_hdc);
}

void GLRenderContext::SwapInterval(int interval)
{
	wglSwapIntervalEXT(interval);
}
