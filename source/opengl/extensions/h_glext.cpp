
#if defined(_WIN32)
	#define WIN32_LEAN_AND_MEAN
	#define NOMINMAX
	#include <windows.h>
#elif defined(__linux__)
	#define GL_GLEXT_LEGACY 1
	#include <GL/glx.h>
#endif

#include <GL/gl.h>
#include <cstring>

#include "h_glext.h"

// Define empty EXTPTR macro to insert definitions of extension function pointers
//=====================================================================
#undef  EXTPTR
#define EXTPTR
#if defined(_WIN32)
	#include "glext_windows_ptrs.h"
	#include "wglext_ptrs.h"
#elif defined(__linux__)
	#include "glext_linux_ptrs.h"
	#include "glxext_ptrs.h"
#endif
//=====================================================================



#define INIT_FUNC_PTR(func)\
		if(!InitFuncPtr(func, #func)) return false


template <class _FUNCT>
inline
bool InitFuncPtr(_FUNCT& func_ptr, const char* func_name)
{
#if defined(_WIN32)
	func_ptr = (_FUNCT)wglGetProcAddress(func_name);
#elif defined(__linux__)
	func_ptr = (_FUNCT)glXGetProcAddressARB((const GLubyte*)func_name);
#endif
	return func_ptr != 0;
}

// include extension loading function definitions
//=====================================================================

#if defined(_WIN32)
	#include "glext_windows_ptrs.inc"
	#include "glext_windows_load.inc"
	#include "wglext_ptrs.inc"
	#include "wglext_load.inc"
#elif defined(__linux__)
	#include "glext_linux_ptrs.inc"
	#include "glext_linux_load.inc"
	#include "glxext_ptrs.inc"
	#include "glxext_load.inc"
#endif
