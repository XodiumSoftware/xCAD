// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiDialog.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiDialog: public CAdUiDialog
{
    DECLARE_DYNAMIC(CAcUiDialog);
public:
    CAcUiDialog(UINT,CWnd* = NULL,HINSTANCE = NULL);
    enum{IDD=0};
    virtual CWnd* AppMainWindow();
    virtual HINSTANCE AppResourceInstance();
    virtual int EnableMultiDocumentActivation(BOOL);
    virtual int IsMultiDocumentActivationEnabled();
    virtual LPCTSTR AppRootKey();
    virtual void EnableFloatingWindows(BOOL);
    virtual void OnDialogHelp();
    virtual ~CAcUiDialog();
protected:
    virtual BOOL FindContextHelpFullPath(LPCTSTR,CString&);
    virtual void DoDataExchange(CDataExchange*);
    virtual void OnCancel();
    virtual void OnOK();

    DECLARE_MESSAGE_MAP()
};
