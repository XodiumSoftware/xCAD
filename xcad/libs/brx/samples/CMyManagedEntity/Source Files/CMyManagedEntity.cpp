// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "resource.h"

//-----------------------------------------------------------------------------
//- DLL Entry Point
#pragma unmanaged
extern "C"
BOOL WINAPI DllMain (HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    UNREFERENCED_PARAMETER(lpReserved) ;

    if ( dwReason == DLL_PROCESS_ATTACH )
    {
        //_hdllInstance =hInstance ; // Disabled to remove loader-lock contention during managed loads...
    }
    else if( dwReason == DLL_PROCESS_DETACH )
    {
    }

    return (TRUE) ;
}
#pragma managed
