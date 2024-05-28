// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

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
