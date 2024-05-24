// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiDialog.h"

class CAdUiTabChildDialogImp;

/** _ */
class BRX_IMPORTEXPORT CAdUiTabChildDialog: public CAdUiDialog
{
    friend class CAdUiTab;

    DECLARE_DYNAMIC(CAdUiTabChildDialog);
public:
    BOOL IsDirty();
    CAdUiTab* GetAcadTabPointer();
    CAdUiTabChildDialog(CWnd* = NULL,HINSTANCE = NULL);
    CAdUiTabMainDialog* GetMainDialog();
    enum{IDD=0};
    int GetTabIndex();
    virtual BOOL OnMainDialogHelp();
    virtual BOOL OnTabChanging();
    virtual BOOL PreTranslateMessage(MSG*);
    virtual void OnMainDialogApply();
    virtual void OnMainDialogCancel();
    virtual void OnMainDialogOK();
    virtual void OnTabActivation(BOOL);
    void SetAcadTabChildFocus(HWND);
    void SetDirty(BOOL = TRUE);
    void SetValidationInfo(CDataExchange*);
protected:
    afx_msg LRESULT OnResizePage(WPARAM,LPARAM);
    afx_msg void OnSize(UINT,int,int);
    virtual void DoDataExchange(CDataExchange*);
    virtual void OnCancel();
    virtual void OnInitDialogBegin();
    virtual void OnInitDialogFinish();
    virtual void OnOK();

public:
    virtual ~CAdUiTabChildDialog();

    DECLARE_MESSAGE_MAP()

private:
    //BRX START
    CAdUiTabChildDialogImp* m_pTabChildDlgImp;
    //BRX END
};
