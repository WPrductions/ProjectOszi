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

#ifdef OZ_ENABLE_ASSERT
	#define OZ_ASSERT(x, ...) {if(!(x)) {OZ_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak()}}
#else
	#define OZ_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define OZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)