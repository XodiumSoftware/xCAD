// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiTabChildDialog.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiTabChildDialog: public CAdUiTabChildDialog
{
    DECLARE_DYNAMIC(CAcUiTabChildDialog);
public:
    CAcUiTabChildDialog(CWnd* = NULL,HINSTANCE = NULL);
    enum{IDD=0};
    virtual BOOL OnMainDialogHelp();
    virtual CWnd* AppMainWindow();
    virtual HINSTANCE AppResourceInstance();
    virtual LPCTSTR AppRootKey();
    virtual void EnableFloatingWindows(BOOL);
    virtual void OnDialogHelp();
    virtual ~CAcUiTabChildDialog();
protected:
    virtual void DoDataExchange(CDataExchange*);

    DECLARE_MESSAGE_MAP()
};
