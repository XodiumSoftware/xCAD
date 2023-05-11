// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// OS standard headers

#pragma once

#ifndef _BS_SYS_HEADERS_INCLUDED_
#define _BS_SYS_HEADERS_INCLUDED_


// Incldues for Windows platform
#ifdef _WIN32

  #include <fcntl.h>
  #include <io.h>
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <stdio.h>
  #include <stdarg.h>
  #include <direct.h>
  #include <stdlib.h>
  #include <wtypes.h>
  #include <process.h>
  #include <math.h>
  #include <string.h>
  #include <malloc.h>
  #include <memory.h>
  #include <assert.h>
  #include <tchar.h>

  #define  _stnprintf    _sntprintf

#endif // _WIN32

// Includes for Non-Windows platform
#ifndef _WIN32

  // Linux standard headers
  #include <unistd.h>
  #include <fcntl.h>
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <sys/time.h>
  #include <sys/timeb.h>
  #include <sys/file.h>
  #include <sys/ioctl.h>
  #ifdef __APPLE__
    #include <sys/sysctl.h>
  #else
    #include <sys/sysinfo.h>
  #endif
  #include <stdio.h>
  #include <stdarg.h>
  #include <stdlib.h>
  #include <stdint.h>
  #include <math.h>
  #include <string.h>
  #ifdef __APPLE__
    #include <malloc/malloc.h>
  #else
    #include <malloc.h>
  #endif
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
  #ifndef __APPLE__
    #include <link.h>
  #endif
  #include <signal.h>
  #include <assert.h>

  #ifndef __APPLE__
    #ifndef _GNU_SOURCE
    #define _GNU_SOURCE
    #endif
  #endif
  #include <dlfcn.h>  
  #include <wordexp.h>

  #ifndef __APPLE__
    #include <linux/kd.h>
    #include <linux/input.h>
  #endif

#endif // !_WIN32


#endif // _BS_SYS_HEADERS_INCLUDED_
