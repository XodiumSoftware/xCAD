// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

// Command registration

#include "stdafx.h"

#if (__BRXVER < 23)
#error "This sample requires BricsCAD/BRX V23"
#endif

namespace BrxMechComponentsSample {
    extern void cmdBmSetCustomProperties();
}

class BrxMechComponentsApp : public AcRxArxApp
{
public:
    BrxMechComponentsApp() : AcRxArxApp() {}

    void RegisterServerComponents() override
    {
    }

    AcRx::AppRetCode On_kInitAppMsg(void* pAppData) override
    {
        AcRx::AppRetCode result = AcRxArxApp::On_kInitAppMsg(pAppData);
        acrxRegisterAppMDIAware(pAppData); // is able to work in MDI context
        acrxUnlockApplication(pAppData);   // allows to unload the module during session
        acutPrintf(_T("\nAvailable commands:"));
        acutPrintf(
            _T("\nBmSetCustomProperties : sets custom properties values for ")
            _T("some components by data loaded from CSV file\n"));
        return result;
    }

    AcRx::AppRetCode On_kUnloadAppMsg(void* pAppData)  override
    {
        return AcRxArxApp::On_kUnloadAppMsg(pAppData);
    }

    static void brxBmSetCustomProperties(void)
    {
        BrxMechComponentsSample::cmdBmSetCustomProperties();
    }
};

IMPLEMENT_ARX_ENTRYPOINT(BrxMechComponentsApp)

ACED_ARXCOMMAND_ENTRY_AUTO(BrxMechComponentsApp, brx, BmSetCustomProperties, BmSetCustomProperties, ACRX_CMD_TRANSPARENT, NULL)
