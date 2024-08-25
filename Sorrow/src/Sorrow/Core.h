#pragma once

#ifdef SORROW_PLATFORM_WINDOWS
	
	#ifdef SORROW_BUILD_DLL
		#define SORROW_API __declspec(dllexport)
	#else
		#define SORROW_API __declspec(dllimport)
	#endif // SORROW
#else
	#error Sorrow only support Windows! 
#endif // SORROW_PLATFORM_WINDOWS

#ifdef SW_ENABLE_ASSERTS
#define SW_ASSERT(x, ...) { if(!(x)) { SW_Client_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define SW_CORE_ASSERT(x, ...) { if(!(x)) { SW_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define SW_ASSERT(x, ...)
#define SW_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define SW_BIND_EVENT_FN(fn)	std::bind(&fn, this, std::placeholders::_1)
 