// This source file is only to check include depencies of our BRX SDK headers.
// It is excluded from the build.

#ifndef __cplusplus
#error File is not compiled as C++ code !
#endif

#undef BRX_API

//enable these includes to simulate MFC extension dlls
//#include <afxwin.h>
//#include <afxext.h>
//#include <afxcmn.h>
//#include <shtypes.h>
//#include <afxole.h>

#ifdef _WINBASE_
#pragma message ("_WINBASE_ defined")
#endif

#ifdef _WINDOWS_
#pragma message ("_WINDOWS_ defined")
#endif

//some headers require these as well:
//#include <afxole.h>
//#include <ShTypes.h>

//#include "./../inc_sdk/acui.h"

#define BRX_API
