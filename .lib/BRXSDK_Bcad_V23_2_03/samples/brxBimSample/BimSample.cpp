// Copyright (C) Menhirs NV. All rights reserved.

#include "StdAfx.h"
#include <afxdllx.h>

AC_IMPLEMENT_EXTENSION_MODULE(BimSampleDLL)

extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	UNREFERENCED_PARAMETER(lpReserved) ;

	if (DLL_PROCESS_ATTACH == dwReason)
    {
        _hdllInstance = hInstance;
		BimSampleDLL.AttachInstance(hInstance);
	}
    else if (DLL_PROCESS_DETACH == dwReason)
    {
		BimSampleDLL.DetachInstance();
	}
	return TRUE;
}
