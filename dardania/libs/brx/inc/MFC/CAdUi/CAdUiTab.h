// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiGlobal.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiTab: public CTabCtrl
{
    friend class CAdUiTabChildDialog;
    friend class CAdUiTabMainDialog;

    DECLARE_DYNAMIC(CAdUiTab);
public:
    BOOL AddTab(int,const CString&,UINT,CAdUiTabChildDialog*);
    BOOL AddTab(int,UINT,UINT,CAdUiTabChildDialog*);
    BOOL DeleteItem(int);
    BOOL DestroyTab(int,BOOL = FALSE);
    BOOL DisplayData();
    BOOL ExchangeData(BOOL);
    BOOL IsDirty();
    BOOL RemoveTab(int);
    BOOL ValidateData();
    CAdUiTab();
    CAdUiTabChildDialog* GetDialogPointer(int);
    CAdUiTabMainDialog* GetMainDialog();
    int GetActiveTab();
    int GetTabIndex(CAdUiTabChildDialog*);
    int SetActiveTab(int);
    virtual ~CAdUiTab();
    void SetApplyButtonID(UINT);
    void SetChildFocus();
    void SetDirty(BOOL = TRUE);
    void SetValidationInfo(CDataExchange*);
protected:
    afx_msg BOOL OnSelChange(NMHDR*,LRESULT*);
    afx_msg BOOL OnSelChanging(NMHDR*,LRESULT*);
    virtual void PreSubclassWindow();

    DECLARE_MESSAGE_MAP()
//BRX START
private:
    void * m_pImp;
//BRX END
};
