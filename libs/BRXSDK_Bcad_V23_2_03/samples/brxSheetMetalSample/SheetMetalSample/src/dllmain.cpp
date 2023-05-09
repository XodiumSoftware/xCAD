// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <afxdllx.h>

#include "MFC\CAcModuleResourceOverride.h"

AC_IMPLEMENT_EXTENSION_MODULE(SheetMetalSampleDLL)

BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    UNREFERENCED_PARAMETER(lpReserved);

    if (DLL_PROCESS_ATTACH == dwReason)
    {
        _hdllInstance = hInstance;
        SheetMetalSampleDLL.AttachInstance(hInstance);
        acdbInitSheetMetal();
    }
    else if (DLL_PROCESS_DETACH == dwReason)
    {
        SheetMetalSampleDLL.DetachInstance();
        acdbUninitSheetMetal();
    }
    return TRUE;
}

