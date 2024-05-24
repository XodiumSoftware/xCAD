// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef BRX_64BIT_HELPER
#define BRX_64BIT_HELPER

#include "ac_tcslen.h" // strlen, wcslen, _tcslen restricted to 32 bit unsigned int return

inline int AcIntPtrToInt (ULONG_PTR value, ULONG_PTR maxNum = 0x7FFFFFFF) //32 bit range
{
    Size6432_Assert(value <= maxNum);
    Size6432_Assert((LONG_PTR)value >= -(LONG_PTR)maxNum);
    const int value32 = static_cast<int>(value);
    Size6432_Assert((ULONG_PTR)value32 == value);
    ++(--maxNum); // dummy to get rid of compiler warnings ("unused")
    return value32;
}

inline unsigned int AcUIntPtrToUInt (ULONG_PTR value, ULONG_PTR maxNum = 0xFFFFFFFF) //32 bit range
{
    Size6432_Assert(value <= maxNum);
    const unsigned int value32 = static_cast<unsigned int>(value);
    Size6432_Assert((ULONG_PTR)value32 == value);
    ++(--maxNum); // dummy to get rid of compiler warnings ("unused")
    return value32;
}

// provide a generic "string to integer (atoi)" function for all 32 + 64 bit platforms
inline INT_PTR __stdcall AcStrToIntPtr (const wchar_t * str)
{
#ifdef __SYS_32_BIT__   // for 32 bit platforms
    return (int)wcstol(str, NULL, 10);
#else
  #ifdef _WIN32
    return _ttoi64(str);
  #else
    return wcstol(str, NULL, 10);
  #endif
#endif
}

#endif // BRX_64BIT_HELPER
