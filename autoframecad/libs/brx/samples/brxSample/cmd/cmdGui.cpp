// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "cmdGui.h"

#include "../resource.h"
#include "../gui/MyDialogBar.h"

CMyDialogBar* s_pAppDialogBar = NULL;

void cmdDock()
{
    CAcModuleResourceOverride resSwitch;

    s_pAppDialogBar = new CMyDialogBar(); //instance is deleted in CMyDialogBar::PostNcDestroy

    BOOL isAutoDelete = s_pAppDialogBar->m_bAutoDelete;
    s_pAppDialogBar->m_bAutoDelete = FALSE;

    CMDIFrameWnd* pCadFrame = acedGetAcadFrame();
    pCadFrame->EnableDocking(CBRS_ALIGN_ANY);

    if (!s_pAppDialogBar->Create(pCadFrame, IDD_DIALOGBAR, CBRS_TOP | CBRS_GRIPPER, IDD_DIALOGBAR))
    {
        delete s_pAppDialogBar;
        acedAlert(ACRX_T("Failed to create a dockable dialog"));
        return;
    }

    s_pAppDialogBar->SetWindowText(ACRX_T("BRX Sample dockable dialog"));
    s_pAppDialogBar->EnableDocking(CBRS_ALIGN_ANY);

    pCadFrame->DockControlBar(s_pAppDialogBar);
    pCadFrame->SetFocus();

    acutPrintf(_T("\nYou should now see a docked dialog at the top side."));
}

#if (__BRXTARGET >= 21)
//panels are BRX specific

#include "BrxSpecific/BcUiPanelMFC.h"

void cmdPanel(bool cleanup /*= false*/)
{
    static bool init = false;
    if (cleanup && !init)
        return;
    init = true;
    class MyPanel : public BcUiPanelMFC
    {
        CButton mButton;
    public:
        MyPanel() : BcUiPanelMFC(ACRX_T("My Custom Panel"), ACRX_T("MyPanel"))
        {
        }
        ~MyPanel()
        {
        }
    protected:
        virtual BOOL CreateControlBar(LPCREATESTRUCT lpCreateStruct) override
        {
            if (!BcUiPanelMFC::CreateControlBar(lpCreateStruct))
                return FALSE;
            CRect rcClient;
            GetClientRect(&rcClient);
            rcClient.DeflateRect(30, 30, 30, 30);
            mButton.Create(_T("TEST"), WS_CHILD | WS_VISIBLE, rcClient, this, AFX_IDW_CONTROLBAR_LAST);
            return TRUE;
        }
        virtual void OnSizeChanged(int cx, int cy) override
        {
            BcUiPanelMFC::OnSizeChanged(cx, cy);
            CRect rcClient;
            GetClientRect(&rcClient);
            rcClient.DeflateRect(30, 30, 30, 30);
            mButton.MoveWindow(&rcClient, TRUE);
        }
    };
    static MyPanel panel;
    if (panel.m_hWnd)
    {
        panel.DestroyWindow();
        acutPrintf(_T("\nThe \"My Custom Panel\" panel is now removed."));
    }
    else if (!cleanup)
    {
        panel.Create();
        acutPrintf(_T("\nThe native style panel sample \"My Custom Panel\" is now included in the panel menu and can be shown, docked, etc. like native panels."));
    }
}

#else //(__BRXTARGET >= 21)

void cmdPanel(bool cleanup /*= false*/)
{
    if (cleanup)
        return;
    acutPrintf(_T("\nThe panel sample is not available on other platforms."));
}

#endif //(__BRXTARGET >= 21)
