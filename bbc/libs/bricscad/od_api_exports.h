// od_api_exports.h : defines for exported functions (ODAPI_DLL)

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#ifdef _WIN32
    #ifdef ODAPI_DLL
        #define	ODAPI __declspec( dllexport)
    #else
        #define	ODAPI __declspec( dllimport)
    #endif
#else
    #define	ODAPI
#endif
