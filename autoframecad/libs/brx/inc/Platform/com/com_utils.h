// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// COM utilities definitions

#ifndef _BS_COM_UTILS_INCLUDED_
#define _BS_COM_UTILS_INCLUDED_

#include "com_defs.h"


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


#ifndef _WIN32  // on Linux/Mac

  // ----- COM Utility Functions and Handlers -----

  BRXEXPORT HINSTANCE CoLoadLibrary           (LPOLESTR lpszLibName, BOOL bAutoFree);
  BRXEXPORT void      CoFreeLibrary           (HINSTANCE hInst);
  BRXEXPORT void      CoFreeAllLibraries      ();
  BRXEXPORT void      CoFreeUnusedLibraries   ();
  BRXEXPORT void      CoFreeUnusedLibrariesEx (DWORD dwUnloadDelay, DWORD dwReserved);

  BRXEXPORT LPVOID CoTaskMemAlloc   (ULONG sizeMemAlloc);
  BRXEXPORT LPVOID CoTaskMemRealloc (LPVOID memBlock, ULONG sizeMemReAlloc);
  BRXEXPORT VOID   CoTaskMemFree    (LPVOID memBlock);


  BRXEXPORT BOOL InlineIsEqualUnknown  (REFGUID rguid);
  BRXEXPORT BOOL InlineIsEqualDispatch (REFGUID rguid);
  BRXEXPORT BOOL InlineIsEqualGUID     (REFGUID rguid1, REFGUID rguid2);

  BRXEXPORT BOOL IsEqualGUID  (REFGUID rguid1, REFGUID rguid2);
  BRXEXPORT BOOL IsEqualIID   (REFIID  riid1,  REFIID riid2);
  BRXEXPORT BOOL IsEqualCLSID (REFCLSID rclsid1, REFCLSID rclsid2);

  inline BOOL operator==(REFGUID rguid1, REFGUID rguid2)
  {
      return IsEqualGUID(rguid1, rguid2);
  };
  inline BOOL operator!=(REFGUID rguid1, REFGUID rguid2)
  {
      return !IsEqualGUID(rguid1, rguid2);
  };


#endif // !_WIN32

#endif // _BS_COM_UTILS_INCLUDED_
