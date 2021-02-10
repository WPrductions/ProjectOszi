#pragma once

#ifdef OZ_PLATFORM_WINDOWS
	#ifdef OZ_BUILD_DLL
		#define OSZI_API __declspec(dllexport)
	#else
		#define OSZI_API __declspec(dllimport)
	#endif
#else
	#error The Application currently only supports Windows!
#endif
