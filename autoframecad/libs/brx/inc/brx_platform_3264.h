// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef BRX_PLATFORM_3264
#define BRX_PLATFORM_3264

  #include "brx_version.h"

  #ifdef _WIN32  // Windows 32+64 bit
    #include "BaseTsd.h"
  #endif

  #ifndef _BS_WIN_DEFS_INCLUDED_

    // Linux,Mac : minimum portable data types
    #ifndef _WIN32
      #include <stdint.h>
    
      typedef int32_t         INT32;
      typedef int32_t         LONG32;
      typedef uint32_t        UINT32;
      typedef uint32_t        ULONG32;
    
      typedef int64_t         INT64;
      typedef int64_t         LONG64;
      typedef uint64_t        UINT64;
      typedef uint64_t        ULONG64;
    
      #ifdef __SYS_32_BIT__   // 32 bit
        typedef int32_t       INT_PTR;
        typedef int32_t*      PINT_PTR;
        typedef uint32_t      UINT_PTR;
        typedef uint32_t*     PUINT_PTR;
        typedef int32_t       LONG_PTR;
        typedef int32_t*      PLONG_PTR;
        typedef uint32_t      ULONG_PTR;
        typedef uint32_t*     PULONG_PTR;
        typedef int32_t       __int3264;
        typedef uint32_t      DWORD_PTR;
        typedef uint32_t*     PDWORD_PTR;
      #else                   // 64 bit
        typedef int64_t       INT_PTR;
        typedef int64_t*      PINT_PTR;
        typedef uint64_t      UINT_PTR;
        typedef uint64_t*     PUINT_PTR;
        typedef int64_t       LONG_PTR;
        typedef int64_t*      PLONG_PTR;
        typedef uint64_t      ULONG_PTR;
        typedef uint64_t*     PULONG_PTR;
        typedef int64_t       __int3264;
        typedef uint64_t      DWORD_PTR;
        typedef uint64_t*     PDWORD_PTR;
      #endif  // !__SYS_32_BIT__

    #endif // _WIN32

  #endif // _BS_WIN_DEFS_INCLUDED_

#endif // BRX_PLATFORM_3264
