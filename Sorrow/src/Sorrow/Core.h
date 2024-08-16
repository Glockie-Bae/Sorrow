#pragma once
#include<iostream>


#ifdef SORROW_PLATFORM_WINDOWS
	
	#ifdef SORROW_BUILD_DLL
		#define SORROW_API __declspec(dllexport)
	#else
		#define SORROW_API __declspec(dllimport)
	#endif // SORROW
#else
	#error Sorrow only support Windows! 
#endif // SORROW_PLATFORM_WINDOWS


#define BIT(x) (1 << x)
