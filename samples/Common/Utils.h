
#ifndef _SAMPLES_COMMON_SHADING_UTILS_H_
#define _SAMPLES_COMMON_SHADING_UTILS_H_

#include <string>
#include <cstdint>

std::string GetFullPath(const char* file_name);
std::string LoadShaderSource(const char* file_name);

template <typename T, size_t N>
constexpr int CountOf(T(&)[N])
{
	return static_cast<int>(N);
}

#endif // _SAMPLES_COMMON_SHADING_UTILS_H_
