// Copyright (C) Menhirs NV. All rights reserved.

#include "StdAfx.h"

#include "cmd/cmdDbx.h"
#include "dbx/MyOPMExtension.h"
#include "gui/MyQuadExtension.h"
#include "gui/MyRibbonContent.h"

#ifdef _WIN32 // only under Windows
#include "cmd/cmdGui.h"
#include "cmd/cmdCom.h"
#include "gui/MyDialogBar.h"
extern CMyDialogBar* s_pAppDialogBar;
#endif // _WIN32


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

        acrxRegisterAppMDIAware(pAppData); // is able to work in MDI context
        acrxUnlockApplication(pAppData);   // allows to unload the module during session

        //Place your init code here
        acutPrintf(_T("\n* Available commands:"));
        acutPrintf(_T("\n* CUSTENT   : create a custom entity"));
        acutPrintf(_T("\n* GetBlockPreviewIcon : extract block preview icons to file"));
        acutPrintf(_T("\n* MyQuadOn  : enables a custom Quad extension"));
        acutPrintf(_T("\n* MyQuadOff : disables a custom Quad extension"));
        acutPrintf(_T("\n* MYRIBBON  : add and remove ribbon content"));
#ifdef _WIN32 // only under Windows
        acutPrintf(_T("\n* DOCK      : create a dockable dialog bar"));
        acutPrintf(_T("\n* CALLCOM   : call some functions from the COM API"));
#if (__BRXTARGET >= 21)
        acutPrintf(_T("\n* PANEL     : create a native style panel"));
#endif // (__BRXTARGET >= 21)
#endif // _WIN32
        acutPrintf(_T("\n"));

        bool res = registerMyOPMExtension();
        res;  // compiler warning

        return result;
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pAppData)
    {
        //Place your cleanup code here
#if defined(BRX_APP) && (__BRXTARGET >= 17) // only available with BRX 17 and higher
        bool res = unregisterMyOPMExtension();
        res = unregisterMyQuadExtension();
#endif

#ifdef _WIN32 // only under Windows
        // close the dockable dialogbar, if present
        if ((s_pAppDialogBar != NULL) && ::IsWindow(s_pAppDialogBar->m_hWnd))
        {
            s_pAppDialogBar->DestroyWindow();
            //s_pAppDialogBar->SendMessage(WM_CLOSE, 0, 0);
            //delete s_pAppDialogBar; s_pAppDialogBar = NULL;
        }
        cmdPanel(true); //cleanup the panel
#endif

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

    static void BrxSampleCustEnt(void)
    {
        cmdMyEntity();
    }

    static void BrxSampleGetBlockPreviewIcon()
    {
        cmdGetBlockPreviewIcon();
    }

    static void BrxSampleMyQuadOn(void)
    {
#if defined(BRX_APP) && (__BRXTARGET >= 17) // only available with BRX 17 and higher
        registerMyQuadExtension();
#else
        acutPrintf(_T("\n* the Quad sample is available only with BRX"));
#endif
    }
    static void BrxSampleMyQuadOff(void)
    {
#if defined(BRX_APP) && (__BRXTARGET >= 17) // only available with BRX 17 and higher
        unregisterMyQuadExtension();
#else
        acutPrintf(_T("\n* the Quad sample is available only with BRX"));
#endif
    }

    static void BrxSampleMyRibbon(void)
    {
#if defined(BRX_APP) && (__BRXTARGET >= 17) // only available with BRX 17 and higher
        addRibbonContent();
#else
        acutPrintf(_T("\n* the Ribbon sample is available only with BRX"));
#endif
    }

#ifdef _WIN32 // only under Windows
    static void BrxSampleDock(void)
    {
        cmdDock();
    }

    static void BrxSampleCallCom(void)
    {
        cmdCallCom();
    }

    static void BrxSamplePanel(void)
    {
        cmdPanel();
    }
#endif // _WIN32
};

IMPLEMENT_ARX_ENTRYPOINT(CSampleApp)

ACED_ARXCOMMAND_ENTRY_AUTO(CSampleApp, BrxSample, CustEnt,   CustEnt,   ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CSampleApp, BrxSample, GetBlockPreviewIcon, GetBlockPreviewIcon, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CSampleApp, BrxSample, MyQuadOn,  MyQuadOn,  ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CSampleApp, BrxSample, MyQuadOff, MyQuadOff, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CSampleApp, BrxSample, MyRibbon,  MyRibbon,  ACRX_CMD_TRANSPARENT, NULL)

#ifdef _WIN32 // only under Windows
ACED_ARXCOMMAND_ENTRY_AUTO(CSampleApp, BrxSample, Dock,      Dock,      ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CSampleApp, BrxSample, CallCom,   CallCom,   ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CSampleApp, BrxSample, Panel,     Panel,     ACRX_CMD_TRANSPARENT, NULL)
#endif // _WIN32
