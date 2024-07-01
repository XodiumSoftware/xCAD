#include "rxregsvc.h"
#include "acutads.h"
// Simple acrxEntryPoint code. Normally intialization and cleanup
// (such as registering and removing commands) should be done here.
//

// Define constants for application messages
const AcRx::AppMsgCode INIT_APP_MSG = AcRx::kInitAppMsg;
const AcRx::AppMsgCode UNLOAD_APP_MSG = AcRx::kUnloadAppMsg;

// Define constants for return values
const AcRx::AppRetCode SUCCESS_RET_CODE = AcRx::kRetOK;

// Define prefix constant
#define PREFIX L"Dardanium"

// Define constants for strings
const wchar_t *LOADED_MSG = PREFIX L" Loaded";
const wchar_t *UNLOADED_MSG = PREFIX L" Unloaded";

extern "C" AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg, void *appId)
{
    switch (msg)
    {
    case INIT_APP_MSG:
        // Allow application to be unloaded
        // Without this statement, AutoCAD will
        // not allow the application to be unloaded
        // except on AutoCAD exit.
        //
        acrxUnlockApplication(appId);
        // Register application as MDI aware.
        // Without this statement, AutoCAD will
        // switch to SDI mode when loading the
        // application.
        //
        acrxRegisterAppMDIAware(appId);
        acutPrintf(LOADED_MSG);
        break;
    case UNLOAD_APP_MSG:
        acutPrintf(UNLOADED_MSG);
        break;
    }
    return SUCCESS_RET_CODE;
}