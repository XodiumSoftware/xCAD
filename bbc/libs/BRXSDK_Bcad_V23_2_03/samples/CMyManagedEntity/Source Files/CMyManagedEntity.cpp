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
