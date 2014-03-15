
#ifndef _H_GLEXT_H_
#define _H_GLEXT_H_

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

#if defined(_WIN32)
	#include "glext_windows_ptrs.h"
	#include "wglext_ptrs.h"
#elif defined(__linux__)
	#include "glext_linux_ptrs.h"
	#include "glxext_ptrs.h"
#endif

//=====================================================================

#ifdef __cplusplus
extern "C"{
#endif

void glextLoadAll();
#if defined(_WIN32)
	void wglextLoadAll();
#elif defined(__linux__)
	void glxextLoadAll();
#endif

#ifdef __cplusplus
} // extern "C"
#endif


#endif // _H_GLEXT_H_
