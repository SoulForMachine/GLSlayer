
#ifndef _SAMPLES_COMMON_SAMPLE_FRAMEWORK_H_
#define _SAMPLES_COMMON_SAMPLE_FRAMEWORK_H_


#if defined(_WIN32)
	#include "SampleFramework_Windows.h"
#elif defined(__linux__)
	#include "SampleFramework_Linux.h"
#endif


#endif // _SAMPLES_COMMON_SAMPLE_FRAMEWORK_H_
