// Copyright (C) Menhirs NV. All rights reserved.

#include "StdAfx.h"
#include "cmdGui.h"

#include "../gui/MyWxApp.h"
#include "../gui/MyWxDialog.h"
#include "../gui/MyWxDialogXrc.h"

void cmdWxString()
{
    wxString str = _T("\nThis is a wxString");
    acutPrintf(str);
}

void cmdWxAppLbl()
{
    wxWindow* pMainWindow = MyWxApp::mainWindow();
    if (pMainWindow != nullptr)
    {
        pMainWindow->SetLabel(_T("bxrWxSample - using WxWidgets"));
    }
}

void cmdWxDialog()
{
    acutPrintf(_T("\nYou should now see a sample modal dialog."));

    wxWindow* pMainWindow = MyWxApp::mainWindow();
    if (pMainWindow != nullptr)
    {
        TestMessageBoxDialog dlg(pMainWindow);
        dlg.Create();
        dlg.ShowModal();
    }
}

void cmdWxDlgXrc()
{
    wxWindow* pMainWindow = MyWxApp::mainWindow();
    static MyWxDialogXrc* pDialog = nullptr;
    if (pDialog == nullptr && pMainWindow != nullptr)
        pDialog = new MyWxDialogXrc(pMainWindow);
    if (pDialog != nullptr && !pDialog->IsShown())
        pDialog->Show(true);
}
