// Copyright (C) Menhirs NV. All rights reserved.

#include "StdAfx.h"



extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	UNREFERENCED_PARAMETER(lpReserved) ;

	if (DLL_PROCESS_ATTACH == dwReason)
    {
        _hdllInstance = hInstance;
#ifdef __WXMSW__
        wxSetInstance(hInstance);
#endif // __WXMSW__
    }
    else if (DLL_PROCESS_DETACH == dwReason)
    {
	}
	return TRUE;
}
