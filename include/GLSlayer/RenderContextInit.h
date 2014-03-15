
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


	extern "C"
	{
	#if defined (_WIN32)
		GLSLAYER_API IRenderContext* CreateRenderContext(uint version, HINSTANCE instance_handle, HWND window_handle, const FramebufferFormat* format, bool debug_context, IDebugLogger* logger);
	#elif defined (__linux__)
		GLSLAYER_API IRenderContext* CreateRenderContext(uint version, Display* display, Window window, const FramebufferFormat* format, bool debug_context, IDebugLogger* logger);
		GLSLAYER_API bool GetVisualInfo(Display* display, const FramebufferFormat& format, XVisualInfo& visual_info);
	#endif
		GLSLAYER_API void DestroyRenderContext(IRenderContext* render_context);
	}

	#if defined (_WIN32)
		typedef IRenderContext* (*CreateRenderContextFuncPtr)(uint version, HINSTANCE instance_handle, HWND window_handle, const FramebufferFormat* format, bool debug_context, IDebugLogger* logger);
	#elif defined (__linux__)
		typedef IRenderContext* (*CreateRenderContextFuncPtr)(uint version, Display* display, Window window, const FramebufferFormat* format, bool debug_context, IDebugLogger* logger);
		typedef bool (*GetVisualInfoFuncPtr)(Display* display, const FramebufferFormat& format, XVisualInfo& visual_info);
	#endif
	typedef void (*DestroyRenderContextFuncPtr)(IRenderContext* render_context);
}


#endif // _GLSLAYER_RENDER_CONTEXT_INIT_H_
