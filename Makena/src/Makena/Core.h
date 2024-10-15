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

#ifdef MKN_ENABLE_ASSERTS
	#define MKN_ASSERT(x, ...) { if(!(x)) { MKN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MKN_CORE_ASSERT(x, ...) { if(!(x)) { MKN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MKN_ASSERT(x, ...)
	#define MKN_CORE_ASSERT(x, ...)
#endif // MKN_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define MKN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)