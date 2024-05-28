// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiDialog.h"
#include "MFC/CAdUi/CAdUiTabExtensionManager.h"

class CAdUiTabMainDialogImp;

/** _ */
class BRX_IMPORTEXPORT CAdUiTabMainDialog: public CAdUiDialog
{
    friend class CAdUiTab;

    DECLARE_DYNAMIC(CAdUiTabMainDialog);
public:
    CAdUiTabMainDialog(UINT,CWnd* = NULL,HINSTANCE = NULL);
    ~CAdUiTabMainDialog();

    enum{IDD=0};

    BOOL AddTab(int,LPCTSTR,UINT,CAdUiTabChildDialog*);
    BOOL AddTab(int,UINT,UINT,CAdUiTabChildDialog*);
    BOOL RemoveTab(int);
    CAdUiTab* GetTabControl();
    CAdUiTabExtensionManager* GetXtabPointer();
    int AddExtendedTabs();
    int GetDefaultButton();
    int GetInitialRequestedTabIndex();
    int GetTabIndex(CAdUiTabChildDialog*);
    LPCTSTR GetInitialTabIndex();
    virtual BOOL AddApplicationTabs(LPCTSTR);
    virtual BOOL PreTranslateMessage(MSG*);
    void SetDefaultButton(int);
    void SetInitialTabIndex(LPCTSTR);
    void UpdateDefaultButton(HWND,HWND);
protected:
    afx_msg void OnSize(UINT,int,int);
    virtual void DoDataExchange(CDataExchange*);
    virtual void OnCancel();
    virtual void OnInitDialogBegin();
    virtual void OnInitDialogFinish();
    virtual void OnOK();
    void RaiseApplyEvent();
    void SetAcadTabPointer(CAdUiTab*);

    DECLARE_MESSAGE_MAP()

protected:
    CAdUiTabExtensionManager m_xtabManager;

private:
    //BRX START
    CAdUiTabMainDialogImp* m_pTabMainDlgImp;
    //BRX END
};
