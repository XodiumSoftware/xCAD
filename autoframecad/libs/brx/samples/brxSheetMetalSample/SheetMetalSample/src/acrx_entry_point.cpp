// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#if (__BRXVER < 21)
#error "This sample requires BricsCAD/BRX V21"
#endif

namespace BrxSheetMetalSample {
extern void cmdSmFlatten();
extern void cmdSmRebuildBends();
extern void cmdSmSeparateLoftedBends();
}

class BrxSheetMetalApp: public AcRxArxApp
{
public:
    BrxSheetMetalApp() : AcRxArxApp() {}

    virtual void RegisterServerComponents()
    {
    }

    virtual AcRx::AppRetCode On_kInitAppMsg(void* pAppData)
    {
        AcRx::AppRetCode result = AcRxArxApp::On_kInitAppMsg(pAppData);
        acutPrintf(_T("\nAvailable commands:"));
        acutPrintf(_T("\nSmFlatten : simplifies geometry for entire model, dissolves all sheet metal features, \
recognizes sheet metal features for all solids in modelspace, repairs all solids, creates bends, switches \
reliefs to smooth and unfolds given solids\n"));
        acutPrintf(_T("\nSmRebuildBends : rebuilds bends and assigns new bend radius to bends with specific angles\n"));
        acutPrintf(_T("\nSmSeparateLoftedBends : separates body with lofted bends into several\n"));
        return result;
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pAppData)
    {
        return AcRxArxApp::On_kUnloadAppMsg(pAppData);
    }

    static void brxSmFlatten(void)
    {
        BrxSheetMetalSample::cmdSmFlatten();
    }

    static void brxSmRebuildBends(void)
    {
        BrxSheetMetalSample::cmdSmRebuildBends();
    }

    
    static void brxSmSeparateLoftedBends(void)
    {
        BrxSheetMetalSample::cmdSmSeparateLoftedBends();
    }

};

IMPLEMENT_ARX_ENTRYPOINT(BrxSheetMetalApp)

ACED_ARXCOMMAND_ENTRY_AUTO(BrxSheetMetalApp, brx, SmFlatten, SmFlatten, ACRX_CMD_TRANSPARENT, NULL)

ACED_ARXCOMMAND_ENTRY_AUTO(BrxSheetMetalApp, brx, SmRebuildBends, SmRebuildBends, ACRX_CMD_TRANSPARENT, NULL)

ACED_ARXCOMMAND_ENTRY_AUTO(BrxSheetMetalApp, brx, SmSeparateLoftedBends, SmSplitLoftedBends, ACRX_CMD_TRANSPARENT, NULL)
