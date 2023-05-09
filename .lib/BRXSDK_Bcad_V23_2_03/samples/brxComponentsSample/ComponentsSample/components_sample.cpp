// dllmain.cpp : Defines the entry point for the DLL application.

// Property of Bricsys NV. All rights reserved.
// This file is part of the source code of Bricsys NV. The source code
// is subject to copyright, is a trade secret of Bricsys NV, and contains
// embodiments of inventions disclosed in patent applications and patents
// of Bricsys NV.

/////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <afxdllx.h>

AC_IMPLEMENT_EXTENSION_MODULE(ComponentsSampleDLL)

BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    UNREFERENCED_PARAMETER(lpReserved);

    if (DLL_PROCESS_ATTACH == dwReason)
    {
        _hdllInstance = hInstance;
        ComponentsSampleDLL.AttachInstance(hInstance);
    }
    else if (DLL_PROCESS_DETACH == dwReason)
    {
        ComponentsSampleDLL.DetachInstance();
    }
    return TRUE;
}

