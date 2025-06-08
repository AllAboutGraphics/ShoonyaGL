#pragma once

#ifdef SGL_PLATFORM_WINDOWS
	#ifdef SGL_BUILD_DLL
		#define SGL_API __declspec(dllexport)
	#else
		#define SGL_API __declspec(dllimport)
	#endif // SGL_BUILD_DLL
#else
	#error SGL only supports Windows
#endif //SGL_PLATFORM_WINDOWS

#ifdef SGL_ENABLE_ASSERTS
	#define SGL_ASSERT(x, ...) { if((!x)) { SGL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SGL_CORE_ASSERT(x, ...) { if((!x)) { SGL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SGL_ASSERT(x, ...)
	#define SGL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)