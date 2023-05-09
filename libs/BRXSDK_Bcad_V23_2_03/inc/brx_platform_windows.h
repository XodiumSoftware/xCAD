
// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// Windows platform emulation for Linux + Mac

#pragma once

#ifndef _BS_BRX_PLATFORM_WIN_INCLUDED_
#define _BS_BRX_PLATFORM_WIN_INCLUDED_

#include "brx_platform_3264.h" // 32/64 bit detection

// Includes for Windows platform
#ifdef _WIN32  // on Windows

  #define STRICT

  #ifndef VC_EXTRALEAN
  #define VC_EXTRALEAN // Exclude rarely-used stuff from Windows headers
  #endif

  //- Modify the following defines if you have to target a platform prior to the ones specified below.
  //- Refer to MSDN for the latest info on corresponding values for different platforms.
  #ifndef WINVER                  //- Allow use of features specific to Windows XP or later.
  #define WINVER 0x0501
  #endif

  #ifndef _WIN32_WINNT            //- Allow use of features specific to Windows XP or later.
  #define _WIN32_WINNT 0x0501
  #endif

  #ifndef _WIN32_WINDOWS          //- Allow use of features specific to Windows XP or later.
  #define _WIN32_WINDOWS 0x0501
  #endif

  #ifndef _WIN32_IE               // Allow use of features specific to IE 6.0 or later.
  #define _WIN32_IE 0x0600
  #endif

  //-------------------------------------------------------------------------------------
  // Windows / MFC / STL
  //-------------------------------------------------------------------------------------

  // MFC includes
  #define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS  // some CString constructors will be explicit
  #define _AFX_ALL_WARNINGS // turns off MFC's hiding of some common and often safely ignored warning messages

  #include <afxwin.h>    // MFC core and standard components
  #include <afxext.h>    // MFC extensions
  #include <afxcmn.h>    // MFC support for Windows Common Controls
  #include <afxole.h>    // MFC OLE classes
  #include <afxdisp.h>   // MFC Automation classes
  #include <Commctrl.h>  // MFC CommonControls

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
  #include <tchar.h>


  /* ----- hide / mimic Linux/Mac GCC specifics ----- */

  #ifdef  __attribute__
  #undef  __attribute__
  #endif
  #define __attribute__(x)  // empty define under Windows


#endif // _WIN32


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


#endif // _BS_BRX_PLATFORM_WIN_INCLUDED_
