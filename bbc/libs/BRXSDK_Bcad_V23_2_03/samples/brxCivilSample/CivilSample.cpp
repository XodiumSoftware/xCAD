// Copyright (C) Menhirs NV. All rights reserved.

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
