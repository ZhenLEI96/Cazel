#pragma once

#ifdef  CZ_PLATFORM_WINDOWS
	#ifdef CZ_BUILD_DLL
		#define	CAZEL_API __declspec(dllexport)
	#else
		#define	CAZEL_API __declspec(dllimport)
	#endif // CZ_BUILD_DLL
#else
	#error Cazel only supports Windows!
#endif //  CZ_PLATFORM_WINDOWS

#define BIT(x) (1 << x)