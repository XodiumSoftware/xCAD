// Copyright (C) Menhirs NV. All rights reserved.

#include "StdAfx.h"
#include "BimClassification.h"
#include "BimIfcExport.h"
#include "BimIfcImport.h"


class BrxBimSample: public AcRxArxApp
{
public:
    BrxBimSample(): AcRxArxApp() {}

    virtual void RegisterServerComponents()
    {
    }

    virtual AcRx::AppRetCode On_kInitAppMsg(void* pAppData)
    {
        AcRx::AppRetCode result = AcRxArxApp::On_kInitAppMsg(pAppData);

        acrxRegisterAppMDIAware(pAppData); // is able to work in MDI context
        acrxUnlockApplication(pAppData);   // allows to unload the module during session

        //Place your init code here
        acutPrintf(_T("\n* Available commands:"));
        acutPrintf(_T("\n* BClassify   : classification for buildings, stories, objects"));
        acutPrintf(_T("\n* BIfcExport1 : IFC export example #1"));
        acutPrintf(_T("\n* BIfcExport2 : IFC export example #2"));
        acutPrintf(_T("\n* BIfcImport  : IFC import example"));
        acutPrintf(_T("\n"));

        return result;
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pAppData)
    {

        return AcRxArxApp::On_kUnloadAppMsg(pAppData);
    }

    virtual AcRx::AppRetCode On_kLoadDwgMsg(void* pAppData)
    {
        return AcRxArxApp::On_kLoadDwgMsg(pAppData);
    }

    virtual AcRx::AppRetCode On_kUnloadDwgMsg(void* pAppData)
    {
        return AcRxArxApp::On_kUnloadDwgMsg(pAppData);
    }

    virtual AcRx::AppRetCode On_kQuitMsg(void* pAppData)
    {
        return AcRxArxApp::On_kQuitMsg(pAppData);
    }

    static void BrxBimSampleBClassify(void)
    {
        cmdMyBimClassify();
    }

#if __BRXTARGET >= 23
    static void BrxBimSampleBIfcExport1(void)
    {
        cmdMyBimIfcExport1();
    }

    static void BrxBimSampleBIfcExport2(void)
    {
        cmdMyBimIfcExport2();
    }

    static void BrxBimSampleBIfcImport(void)
    {
        cmdMyBimIfcImport();
    }
#endif
};

IMPLEMENT_ARX_ENTRYPOINT(BrxBimSample)

ACED_ARXCOMMAND_ENTRY_AUTO(BrxBimSample, BrxBimSample, BClassify,   BClassify,   ACRX_CMD_TRANSPARENT, NULL)
#if __BRXTARGET >= 23
ACED_ARXCOMMAND_ENTRY_AUTO(BrxBimSample, BrxBimSample, BIfcExport1, BIfcExport1, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxBimSample, BrxBimSample, BIfcExport2, BIfcExport2, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxBimSample, BrxBimSample, BIfcImport,  BIfcImport,  ACRX_CMD_TRANSPARENT, NULL)
#endif
