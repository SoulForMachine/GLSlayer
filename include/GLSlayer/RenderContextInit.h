
#ifndef _GLSLAYER_RENDER_CONTEXT_INIT_H_
#define _GLSLAYER_RENDER_CONTEXT_INIT_H_

#if defined (_WIN32)
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
#elif defined (__linux__)
	#include <X11/Xlib.h>
	#include <X11/Xutil.h>
#endif

#include "Common.h"

namespace gls
{
	class IRenderContext;

	struct CreateContextInfo
	{
		uint version;

	#if defined (_WIN32)
		HINSTANCE instanceHandle;
		HWND windowHandle;
	#elif defined (__linux__)
		Display* display;
		Window window;
	#endif
		const FramebufferFormat* format;
		bool debugContext;
		IDebugLogger* logger;
	};

	extern "C"
	{
	#if defined (_WIN32)
		GLSLAYER_API IRenderContext* CreateRenderContext(const CreateContextInfo& info);
	#elif defined (__linux__)
		GLSLAYER_API IRenderContext* CreateRenderContext(const CreateContextInfo& info);
		GLSLAYER_API bool XGetVisualInfo(Display* display, const FramebufferFormat& format, XVisualInfo& visual_info);
	#endif
		GLSLAYER_API void DestroyRenderContext(IRenderContext* render_context);
	}

	#if defined (_WIN32)
		typedef IRenderContext* (*CreateRenderContextFuncPtr)(const CreateContextInfo& info);
	#elif defined (__linux__)
		typedef IRenderContext* (*CreateRenderContextFuncPtr)(const CreateContextInfo& info);
		typedef bool (*XGetVisualInfoFuncPtr)(Display* display, const FramebufferFormat& format, XVisualInfo& visual_info);
	#endif
	typedef void (*DestroyRenderContextFuncPtr)(IRenderContext* render_context);
}


#endif // _GLSLAYER_RENDER_CONTEXT_INIT_H_
