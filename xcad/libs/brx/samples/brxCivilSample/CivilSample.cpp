// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include <afxdllx.h>

AC_IMPLEMENT_EXTENSION_MODULE(CivilSampleDLL)

extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    UNREFERENCED_PARAMETER(lpReserved) ;

    if (DLL_PROCESS_ATTACH == dwReason)
    {
        _hdllInstance = hInstance;
        CivilSampleDLL.AttachInstance(hInstance);
    }
    else if (DLL_PROCESS_DETACH == dwReason)
    {
        CivilSampleDLL.DetachInstance();
    }
    return TRUE;
}
