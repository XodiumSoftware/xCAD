// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef BRX_PLATFORM_STRLEN32
#define BRX_PLATFORM_STRLEN32

#include "brx_platform_3264.h"
#include "Platform/win/win_defs.h"
#include "brx_platform_utils.h"

#if defined(assert)
  #define Size6432_Assert assert
#elif defined ASSERT
  #define Size6432_Assert ASSERT
#elif defined(_ASSERTE)
  #define Size6432_Assert _ASSERTE
#elif defined ATLASSERT
  #define Size6432_Assert ATLASSERT
#else
  #define Size6432_Assert(x)
#endif

// some useful tools for 64 bit platforms
#ifdef __SYS_64_BIT__

  // restrict strlen, wcslen, _tcslen to 32 bit integer
  //#undef strlen
  //#undef wcslen
  //#undef _tcslen

  //#define strlen  _strlen6432
  //#define wcslen  _wcslen6432
  //#define _tcslen _wcslen6432

  inline unsigned int __stdcall _wcslen6432 (const wchar_t* str)
  {
      size_t len = 0;
      while (*str)
      {
          ++len;
          ++str;
      }
      if (len <= 0xFFFFFFFF)  //32 bit range
      {
          return (unsigned int)len;
      }
      Size6432_Assert(len < 0xFFFFFFFF);  //32 bit range
      return (unsigned int)0xFFFFFFFF;
  }

  inline unsigned int __stdcall _strlen6432 (const char* str)
  {
      size_t len = 0;
      while (*str)
      {
          ++len;
          ++str;
      }
      if (len <= 0xFFFFFFFF)  //32 bit range
      {
          return (unsigned int)len;
      }
      Size6432_Assert(len < 0xFFFFFFFF);  //32 bit range
      return (unsigned int)0xFFFFFFFF;
  }
#endif  // __SYS_64_BIT__

#endif  // BRX_PLATFORM_STRLEN32
