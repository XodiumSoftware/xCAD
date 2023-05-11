
// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// Windows platform emulation for Linux + Mac

#pragma once

#ifndef _BS_BRX_PLATFORM_LINUX_INCLUDED_
#define _BS_BRX_PLATFORM_LINUX_INCLUDED_

#include "brx_platform_3264.h" // 32/64 bit detection

#ifndef _WIN32  // on Linux/Mac

  // Linux standard headers
  #include <unistd.h>
  #include <fcntl.h>
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <sys/time.h>
  #include <sys/timeb.h>
  #include <sys/file.h>
  #include <sys/ioctl.h>

  #include <stdio.h>
  #include <stdarg.h>
  #include <stdlib.h>
  #include <stdint.h>
  #include <math.h>
  #include <string.h>
  #include <memory.h>
  #include <sstream>
  #include <ctype.h>
  #include <wchar.h>
  #include <wctype.h>
  #include <dirent.h>
  #include <inttypes.h>
  #include <time.h>
  #include <limits.h>
  #include <errno.h>
  #include <signal.h>

  #ifndef _GNU_SOURCE
  #define _GNU_SOURCE
  #endif
  #include <dlfcn.h>  

#ifndef __APPLE__   // Linux specifics
  #include <sys/sysinfo.h>
  #include <malloc.h>
  #include <link.h>
  #include <linux/kd.h>
  #include <linux/input.h>
#else               // Apple specifics
  #include <sys/sysctl.h>
#endif //!__APPLE__

#endif // !_WIN32


// Windows platform encapsulation for Linux, and cross-platform generics

// generics for all platforms
#include "brx_platform_utils.h"

// WIN
#include "Platform/win/win_defs.h"
#include "Platform/win/c-runtime.h"
#include "Platform/win/winsdk.h"
#include "Platform/win/win_registry.h"

// COM
#include "Platform/com/com_defs.h"
#include "Platform/com/com_errors.h"
#include "Platform/com/com_utils.h"
#include "Platform/com/com_maps.h"
#include "Platform/com/com_classes.h"

// ATL
#include "Platform/atl/atl_defs.h"
#include "Platform/atl/atl_classes.h"

// MFC
#include "Platform/mfc/mfc_defs.h"
#include "Platform/mfc/mfc_classes.h"


// cleanup & preparations
#define _TCHAR_DEFINED  // otherwise, ut_string_ops gets confused


#endif // _BS_BRX_PLATFORM_LINUX_INCLUDED_
