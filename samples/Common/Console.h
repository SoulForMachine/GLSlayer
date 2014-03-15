
#ifndef _SAMPLES_COMMON_CONSOLE_H_
#define _SAMPLES_COMMON_CONSOLE_H_

#include <cstdio>
#include <cstdarg>
#include "GLSlayer/RenderContext.h"

using namespace gls;


class Console : public IDebugLogger
{
public:
	void DebugMessage(DebugMessageSource source, DebugMessageType type, uint id, DebugMessageSeverity severity, const char* message)
	{
		if(type != DEBUG_TYPE_OTHER)
			printf("%s\n", message);
	}

	void PrintLn(const char* str, ...)
	{
		va_list args;
		va_start(args, str);

		vprintf(str, args);
		printf("\n");

		va_end(args);
	}

	void Print(const char* str, ...)
	{
		va_list args;
		va_start(args, str);

		vprintf(str, args);

		va_end(args);
	}
};

#endif // _SAMPLES_COMMON_CONSOLE_H_
