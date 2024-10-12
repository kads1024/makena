#pragma once
#ifdef MKN_PLATFORM_WINDOWS
	#ifdef MKN_BUILD_DLL
		#define  MAKENA_API __declspec(dllexport)
	#else
		#define MAKENA_API __declspec(dllimport)
	#endif // MKN_BUILD_DLL
#else
	#error SA WINDOWS LANG PWEDE GAMITIN ANG MAKENA!
#endif // MKN_PLATFORM_WINDOWS
