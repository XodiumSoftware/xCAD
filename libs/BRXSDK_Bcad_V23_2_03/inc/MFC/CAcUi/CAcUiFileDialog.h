// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiFileDialog.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiFileDialog: public CAdUiFileDialog
{
    DECLARE_DYNAMIC(CAcUiFileDialog);
public:
    enum{IDD=0};
    CAcUiFileDialog(BOOL,LPCTSTR = NULL,LPCTSTR = NULL,DWORD = OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,LPCTSTR = NULL,CWnd* = NULL);
    virtual CWnd* AppMainWindow();
    virtual HINSTANCE AppResourceInstance();
    virtual LPCTSTR AppRootKey();
    virtual void EnableFloatingWindows(BOOL);
    virtual void OnDialogHelp();
    virtual ~CAcUiFileDialog();
protected:
    virtual void DoDataExchange(CDataExchange*);
    virtual void OnCancel();
    virtual void OnOK();

    DECLARE_MESSAGE_MAP()
};
