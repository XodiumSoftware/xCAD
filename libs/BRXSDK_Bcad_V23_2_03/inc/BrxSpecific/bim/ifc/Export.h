/*
 * Copyright (c) 2019 Bricsys NV
 * All rights reserved.
 */

#pragma once

#ifdef _WIN32

#ifdef Ice_EXPORTS // CMake define
#define IFCAPI_EXPORTS
#endif

#ifdef IFCAPI_EXPORTS
#define IFCAPI_EXPORT             __declspec(dllexport)
#else
#define IFCAPI_EXPORT             __declspec(dllimport)
#endif

 // Disable Compiler Warning C4275: non dll-interface class 'identifier' used as base for dll-interface class 'identifier'
#pragma warning( disable: 4275 )

#else
#define IFCAPI_EXPORT
#endif
