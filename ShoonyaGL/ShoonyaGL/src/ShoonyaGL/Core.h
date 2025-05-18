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

#define BIT(x) (1 << x)