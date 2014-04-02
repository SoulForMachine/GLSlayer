
#ifndef _GL_CONTEXT_INFO_H_
#define _GL_CONTEXT_INFO_H_

#if defined(_WIN32)
	#include "extensions/glext_windows_flags.h"
	#include "extensions/wglext_flags.h"
#elif defined(__linux__)
	#include "extensions/glext_linux_flags.h"
	#include "extensions/glxext_flags.h"
#endif

struct GLContextInfo : gls::ContextInfo
{
	FeaturesGL		featuresGL;
#if defined(_WIN32)
	FeaturesWGL		featuresWGL;
#elif defined(__linux__)
	FeaturesGLX		featuresGLX;
#endif
};


#endif // _GL_CONTEXT_INFO_H_
