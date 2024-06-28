// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

//---------------------- Support for Linux + Mac ------------------------------
#ifndef _WIN32 // Linux,Mac
  #include "brx_platform_linux.h"
#endif // !_WIN32
//-----------------------------------------------------------------------------


#define STRICT

#ifndef WINVER
#define WINVER 0x0501
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

//-----------------------------------------------------------------------------
//- 'DEBUG workaround' below prevents the MFC or ATL #include-s from pulling
//- in "Afx.h" that would force the debug CRT through #pragma-s.
#if defined(_WIN32) && defined(_DEBUG) && !defined(BRX_BCAD_DEBUG)
  #define _DEBUG_WAS_DEFINED
  #undef _DEBUG
  #define NDEBUG
  #pragma message ("     Compiling MFC / STL / ATL header files in release mode.")
#endif

//-----------------------------------------------------------------------------------
/*
MFC includes

OPTIONAL: remove these lines if your application does not use MFC
*/
#include <afxwin.h>
#include <afxext.h>
#include <afxcmn.h>
#include <memory>

//-----------------------------------------------------------------------------------
/*
ARX or BRX includes

The build configurations "Debug_Acad" and "Release_Acad" target the Acad platform,
the project include and lib paths are set to the original ARX SDK.
The build configurations "Debug_Bcad" and "Release_Bcad" target the BricsCAD platform,
the project include and lib paths are set to the BRX SDK.
*/
#include "arxHeaders.h"

/*
NOTE: in the ARX headers, as well as in the BRX headers, the necessary lib files are
imported by #pragma statements, like "#pragma comment(lib ,"brx13.lib")".
So .lib files do not need to be imported explicitly in your project settings.
*/

//-----------------------------------------------------------------------------
#ifdef _DEBUG_WAS_DEFINED
  #undef NDEBUG
  #define _DEBUG
  #undef _DEBUG_WAS_DEFINED
#endif
//-----------------------------------------------------------------------------

// You must have "BRX_APP" defined for BRX builds (without BRX_APP, it is an ARX build)!
#ifdef BRX_APP  // BRX builds
  #include "brx_version.h"
#endif // BRX_APP
