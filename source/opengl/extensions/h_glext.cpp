
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
