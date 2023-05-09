// Copyright (C) 2006-2014 Menhirs NV. All rights reserved.
#pragma once

#if !defined(BRX_IMPORTEXPORT) || !defined(BRXM_IMPORTEXPORT)

  #ifdef _WIN32 // Windows

    #ifdef BRX_API
      #define BRX_IMPORTEXPORT  __declspec(dllexport)
      #define BRX_EXPORT        __declspec(dllexport)
    #else
      #define BRX_IMPORTEXPORT  __declspec(dllimport)
      #define BRX_EXPORT
    #endif
    #pragma warning(disable:4273)

    #ifdef BRXMGD_MODULE
      #define BRXM_IMPORTEXPORT __declspec(dllexport)
      #define BRXM_EXPORT       __declspec(dllexport)
    #else
      #define BRXM_IMPORTEXPORT __declspec(dllimport)
      #define BRXM_EXPORT
    #endif
    #pragma warning(disable:4273)

  #else  // Linux/Mac

    #ifdef BRX_API
      #define BRX_IMPORTEXPORT  __attribute__((visibility("default")))
      #define BRX_EXPORT        __attribute__((visibility("default")))
    #else
      #define BRX_IMPORTEXPORT
      #define BRX_EXPORT
    #endif

  #endif // Linux/Mac

#endif // BRX_IMPORTEXPORT
