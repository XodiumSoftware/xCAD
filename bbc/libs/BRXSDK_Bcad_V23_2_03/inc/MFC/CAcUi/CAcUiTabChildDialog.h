// Copyright (C) Menhirs NV. All rights reserved.
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
