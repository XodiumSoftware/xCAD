// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiTabMainDialog.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiTabMainDialog: public CAdUiTabMainDialog
{
    DECLARE_DYNAMIC(CAcUiTabMainDialog);
public:
    CAcUiTabMainDialog(UINT,CWnd* = NULL,HINSTANCE = NULL);
    enum{IDD=0};
    virtual BOOL AddApplicationTabs(LPCTSTR);
    virtual CWnd* AppMainWindow();
    virtual HINSTANCE AppResourceInstance();
    virtual int EnableMultiDocumentActivation(BOOL);
    virtual int IsMultiDocumentActivationEnabled();
    virtual LPCTSTR AppRootKey();
    virtual void EnableFloatingWindows(BOOL);
    virtual void OnDialogHelp();
    virtual ~CAcUiTabMainDialog();
protected:
    virtual void DoDataExchange(CDataExchange*);
    virtual void OnCancel();
    virtual void OnOK();

    DECLARE_MESSAGE_MAP()
};
