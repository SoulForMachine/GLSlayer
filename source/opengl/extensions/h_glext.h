
#ifndef _H_GLEXT_H_
#define _H_GLEXT_H_

#include <cassert>
#include "glext.h"

#if defined(_WIN32)
	#include "wglext.h"
#elif defined(__linux__)
	#include "glxext.h"
#endif


// include all headers with declarations of extension function pointers
//=====================================================================

#ifdef __cplusplus
	#define EXTPTR extern "C"
#else
	#define EXTPTR extern
#endif

struct GLContextInfo;

#if defined(_WIN32)
	#include "glext_windows_ptrs.h"
	#include "glext_windows_funcs.h"
	#include "wglext_ptrs.h"
	#include "wglext_funcs.h"
#elif defined(__linux__)
	#include "glext_linux_ptrs.h"
	#include "glext_linux_funcs.h"
	#include "glxext_ptrs.h"
	#include "glxext_funcs.h"
#endif

//=====================================================================

#endif // _H_GLEXT_H_
