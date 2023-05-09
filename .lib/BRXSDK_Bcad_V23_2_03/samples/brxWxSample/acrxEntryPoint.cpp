// Copyright (C) Menhirs NV. All rights reserved.

#include "StdAfx.h"
#include "cmd/cmdGui.h"
#include "gui/MyWxApp.h"

class CSampleApp: public AcRxArxApp
{
public:
    CSampleApp(): AcRxArxApp() {}

    virtual void RegisterServerComponents()
    {
    }

    virtual AcRx::AppRetCode On_kInitAppMsg(void* pAppData)
    {
        AcRx::AppRetCode result = AcRxArxApp::On_kInitAppMsg(pAppData);

        //Place your init code here
        acutPrintf(_T("\nAvailable commands:"));
        acutPrintf(_T("\nWXSTRING : print a WxString to the command line"));
        acutPrintf(_T("\nWXAPPLBL : changes CAD application's main window label"));
        acutPrintf(_T("\nWXDIALOG : create a WxWidgets based modal dialog"));
        acutPrintf(_T("\nWXDLGXRC : create a WxWidgets modeless dialog which loads resources from xrc"));
        acutPrintf(_T("\n"));

        if (!MyWxApp::initWxApp())
            acutPrintf(_T("\nError in initializing wxWidgets\n"));

        return result;
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pAppData)
    {
        //Place your cleanup code here
        MyWxApp::uninitWxApp();

        return AcRxArxApp::On_kUnloadAppMsg(pAppData);
    }

    static void BrxSampleWxString(void)
    {
        cmdWxString();
    }

    static void BrxSampleWxAppLbl(void)
    {
        cmdWxAppLbl();
    }

    static void BrxSampleWxDialog(void)
    {
        cmdWxDialog();
    }

    static void BrxSampleWxDlgXrc(void)
    {
        cmdWxDlgXrc();
    }
};

IMPLEMENT_ARX_ENTRYPOINT(CSampleApp)

ACED_ARXCOMMAND_ENTRY_AUTO(CSampleApp, BrxSample, WxString, WxString, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CSampleApp, BrxSample, WxAppLbl, WxAppLbl, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CSampleApp, BrxSample, WxDialog, WxDialog, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CSampleApp, BrxSample, WxDlgXrc, WxDlgXrc, ACRX_CMD_TRANSPARENT, NULL)
