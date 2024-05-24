
// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

// Windows platform emulation for Linux + Mac

#pragma once

#ifndef _BS_BRX_PLATFORM_INCLUDED_
#define _BS_BRX_PLATFORM_INCLUDED_

#include "sys_version.h"  // 32/64 bit identification __SYS_64_BIT__ / __SYS_32_BIT__

// Includes for Windows platform
#ifdef _WIN32  // on Windows

  #include "brx_platform_windows.h"

  #if (_MSC_VER >= 1900) //only valid in VC14+
    #define _THROWS noexcept(false)
  #else
    #define _THROWS
  #endif

#endif // _WIN32

#ifndef _WIN32  // on Linux/Mac

  #include "brx_platform_linux.h"

  #define _THROWS noexcept(false)

#endif // !_WIN32

#endif // _BS_BRX_PLATFORM_INCLUDED_
