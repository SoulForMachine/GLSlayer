
#include <cassert>
#include <cstring>
#include "GLSlayer/RenderContextInit.h"
#include "GLRenderContext.h"


using namespace gls;


static bool ctxErrorOccurred = false;
static int ctxErrorHandler( Display *dpy, XErrorEvent *ev )
{
	ctxErrorOccurred = true;
	return 0;
}

static
bool IsExtSupported(const char* extension, Display* display)
{
	if(!extension || !extension[0])
		return false;

	PFNGLGETSTRINGIPROC ptr_glGetStringi = (PFNGLGETSTRINGIPROC)glXGetProcAddressARB((const GLubyte*)"glGetStringi");
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

	const char* ext_string = (const char*)glXQueryExtensionsString(display, DefaultScreen(display));
	if(ext_string && strstr(ext_string, extension))
		return true;

	return false;
}

static
GLXFBConfig GetFBConfig(Display* display, const FramebufferFormat& format)
{
	// check if sRGB framebuffer is supported
	bool sRGB = IsExtSupported("GLX_EXT_framebuffer_sRGB", display);

	int fb_attribs[] =
	{
		GLX_X_RENDERABLE    , True,
		GLX_DRAWABLE_TYPE   , GLX_WINDOW_BIT,
		GLX_RENDER_TYPE     , (int)GetGLEnum(format.colorBufferType),
		GLX_X_VISUAL_TYPE   , GLX_TRUE_COLOR,
		GLX_TRANSPARENT_TYPE, GLX_NONE,
		GLX_CONFIG_CAVEAT	, GLX_NONE,
		GLX_LEVEL			, 0,
		GLX_RED_SIZE        , format.colorBits / 4,
		GLX_GREEN_SIZE      , format.colorBits / 4,
		GLX_BLUE_SIZE       , format.colorBits / 4,
		GLX_ALPHA_SIZE      , format.colorBits / 4,
		GLX_BUFFER_SIZE		, format.colorBits,
		GLX_DEPTH_SIZE      , format.depthBits,
		GLX_STENCIL_SIZE    , format.stencilBits,
		GLX_DOUBLEBUFFER    , format.doubleBuffer ? True : False,
		GLX_SAMPLE_BUFFERS  , format.multisampleSamples ? 1 : 0,
		GLX_SAMPLES         , format.multisampleSamples,
		((sRGB && format.sRGB) ? GLX_FRAMEBUFFER_SRGB_CAPABLE_ARB : 0)	, ((sRGB && format.sRGB) ? 1 : 0),
		None
	};

	int fb_count;
	GLXFBConfig* configs = glXChooseFBConfig(display, DefaultScreen(display), fb_attribs, &fb_count);
	if(!configs)
		return 0;

	GLXFBConfig best_fbc = 0;
	for(int i = 0; i < fb_count; ++i)
	{
		XVisualInfo* vi = glXGetVisualFromFBConfig(display, configs[i]);
		if(vi)
		{
			int depth = vi->depth;
			XFree(vi);
			if(depth == 24)
			{
				best_fbc = configs[i];
				break;
			}
		}
	}

	XFree(configs);

	return best_fbc;
}


IRenderContext* gls::CreateRenderContext(const CreateContextInfo& info)
{
	GLRenderContext* render_context = new GLRenderContext(info.logger);
	bool result = render_context->Create(info.version, info.display, info.window, *info.format, info.debugContext);
	if(!result)
	{
		delete render_context;
		render_context = 0;
	}
	return render_context;
}

bool gls::XGetVisualInfo(Display* display, const FramebufferFormat& format, XVisualInfo& visual_info)
{
	GLXFBConfig fbc = GetFBConfig(display, format);
	if(!fbc)
		return false;

	XVisualInfo* vi = glXGetVisualFromFBConfig(display, fbc);
	if(!vi)
		return false;

	visual_info = *vi;
	XFree(vi);

	return true;
}

void gls::DestroyRenderContext(IRenderContext* render_context)
{
	if(render_context)
	{
		static_cast<GLRenderContext*>(render_context)->Destroy();
		delete render_context;
	}
}

Window gls::SetContextWindow(IRenderContext* render_context, Window window)
{
	auto rcImpl = static_cast<GLRenderContext*>(render_context);
	return rcImpl->SetContextWindow(window);
}

Window GLRenderContext::SetContextWindow(Window window)
{
	Window old = _window;
	_window = window;
	return old;
}

bool GLRenderContext::Create(uint version, Display* display, Window window, const FramebufferFormat& format, bool debug_context)
{
	if(_initialized)
		return false;

	if(version < 330)
	{
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_UNSUPPORTED_VERSION);
		return false;
	}

	_window = window;
	_display = display;

	if(!CreateContext(version, format, debug_context))
	{
		return false;
	}

	Bool result = glXMakeCurrent(_display, _window, _context);
	if(!result)
	{
		Destroy();
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version, "glXMakeCurrent");
		return false;
	}

	return InitCommon(version);
}

bool GLRenderContext::CreateContext(uint version, const FramebufferFormat& format, bool debug_context)
{
	ctxErrorOccurred = false;
	int (*oldHandler)(Display*, XErrorEvent*) = XSetErrorHandler(&ctxErrorHandler);

	GLXFBConfig fb_config = GetFBConfig(_display, format);
	if(!fb_config)
	{
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version, "failed to get GLXFBConfig.");
		return false;
	}

	GLXContext context = 0;
	if( IsExtSupported("GLX_ARB_create_context") &&
		glextLoad_GLX_ARB_create_context() &&
		glXCreateContextAttribsARB )
	{
		int context_flags = (version >= 300) ? GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB : 0;
		if(debug_context)
			context_flags |= GLX_CONTEXT_DEBUG_BIT_ARB;
		int attribs[] =
		{
			GLX_CONTEXT_MAJOR_VERSION_ARB, (int)version / 100,
			GLX_CONTEXT_MINOR_VERSION_ARB, (int)version % 100 / 10,
			GLX_CONTEXT_FLAGS_ARB, context_flags,
			None
		};

		context = glXCreateContextAttribsARB(_display, fb_config, 0, True, attribs);
	}
	else
	{
		DebugMessage(
			DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version,
			"extension GLX_ARB_create_context not supported, cannot create forward compatible context");
	}

	XSync(_display, False);
	XSetErrorHandler(oldHandler);

	if(!ctxErrorOccurred && context)
	{
		_context = context;
		_info.framebufferFormat = format;
		return true;
	}
	else
	{
		_context = 0;
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_HIGH, MESSAGE_ERROR_CREATE_CONTEXT, version, "glXCreateContextAttribsARB");
		return false;
	}
}

void GLRenderContext::Destroy()
{
	if(_context)
	{
		if(glXGetCurrentContext() == _context)
		{
			glXMakeCurrent(_display, 0, 0);
		}
		glXDestroyContext(_display, _context);

		DeinitCommon();
	}
}

bool GLRenderContext::LoadPlatformOpenGLExtensions()
{
	bool result = true;

	// GLX extensions
	LOAD_EXTENSION_REQ(GLX_ARB_multisample);
	LOAD_EXTENSION_REQ(GLX_EXT_swap_control);
	LOAD_EXTENSION(GLX_OML_swap_method);
	LOAD_EXTENSION(GLX_EXT_framebuffer_sRGB);
	LOAD_EXTENSION_REQ(GLX_ARB_create_context);
	LOAD_EXTENSION(GLX_ARB_fbconfig_float);

	return result;
}

bool GLRenderContext::IsExtSupported(const char* extension)
{
	return ::IsExtSupported(extension, _display);
}

bool GLRenderContext::SetCurrentContext()
{
	Bool result = glXMakeCurrent(_display, _window, _context);
	return (result == True);
}

void GLRenderContext::SwapBuffers()
{
	assert(_display && _window);
	glXSwapBuffers(_display, _window);
}

void GLRenderContext::SwapInterval(int interval)
{
	glXSwapIntervalEXT(_display, _window, interval);
}
