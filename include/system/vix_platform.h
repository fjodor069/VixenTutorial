#ifndef VIX_PLATFORM_H
#define VIX_PLATFORM_H

//
// NOTE:
//
// Define preporocessor macros for DLL export import, and
// system macros
//

#ifdef _WIN32

#define VIX_SYS_WINDOWS
	// defined to disable <window.h> from defining the min and max macros
	#ifndef NOMINMAX
	#define NOMINMAX
	#endif // !NOMINMAX

#elif defined (__linux__)
#define VIX_SYS_LINUX
#elif defined (__APPLE__)
#define VIX_SYS_MACOS

#endif

#ifndef VIX_STATIC_BUILD

	#ifdef VIX_SYS_WINDOWS

		#ifdef VIX_NONCLIENT_BUILD
			#define VIX_API __declspec(dllexport)
		#else
			#define VIX_API __declspec(dllimport)
		#endif

		//Visual C++ compiler warning C4251 disable
		#ifdef _MSC_VER
			#pragma warning(disable: 4251)
		#endif

	#elif defined(VIX_SYS_LINUX) || defined(VIX_SYS_MACOS)
		#ifdef __GNUC__ >= 4
			#define VIX_API __attribute__ ((__visibility__("default")))
		#else
			#define VIX_API VIX_API
		#endif
	#endif
#else
		#define VIX_API VIX_API
	

#endif //VIX_STATIC_BUILD


#endif //VIX_PLATFORM_H