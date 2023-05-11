// sds_brx_helper.h : API used by BRX to customize the application status bar

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#ifdef _WIN32
  #ifdef SDSAPI_PRJ
    #define	SDSBRXHELPER_API __declspec(dllexport)
  #else
    #define	SDSBRXHELPER_API
  #endif
#else
  #ifdef SDSAPI_PRJ
    #define	SDSBRXHELPER_API __attribute__((visibility("default")))
  #else
    #define	SDSBRXHELPER_API
  #endif
#endif

// functions for status bar customization used by BRX API

SDSBRXHELPER_API 
int sds_getIntCheckRange(const TCHAR* szIntMsg, int *pnInteger, int min, int max);
