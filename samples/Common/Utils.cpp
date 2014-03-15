
#include "Utils.h"
#include <cstring>
#include <memory>
#if defined (_WIN32)
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
#elif defined (__linux__)
	#include <unistd.h>
#endif

using namespace std;

#if defined (_WIN32)
string GetFullPath(const char* file_name)
{
	char path[MAX_PATH];
	GetModuleFileNameA(NULL, path, MAX_PATH);
	const char* bslash = strrchr(path, '\\');
	return bslash ? string(path, bslash + 1) + file_name : string(file_name);
}
#elif defined (__linux__)
string GetFullPath(const char* file_name)
{
	char path[256];
	readlink("/proc/self/exe", path, sizeof(path));
	const char* slash = strrchr(path, '/');
	return slash ? string(path, slash - path + 1) + file_name : string(file_name);
}
#endif

string LoadShaderSource(const char* file_name)
{
	string fn = GetFullPath(file_name);
	FILE* file = fopen(fn.c_str(), "rb");
	if(!file)
		return string();

	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	unique_ptr<char[]> source(new char[size + 1]);
	fseek(file, 0, SEEK_SET);
	fread(source.get(), size, 1, file);
	source[size] = '\0';
	fclose(file);
	return string(source.get());
}
