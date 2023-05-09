// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiBaseDialog.h"
#include "BrxSpecific/BcUiThemeHelperWin.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiDialog: public CAdUiBaseDialog, public BcUiThemeHelperWin
{
    DECLARE_DYNAMIC(CAdUiDialog);
public:
    enum{IDD=0};
    BOOL AddControl(CWnd*);
    BOOL AutoLoadControl(CWnd*);
    BOOL ForceControlRepaint(CWnd*,BOOL);
    BOOL ForceControlResize(CWnd*,LPRECT);
    BOOL GetColumnSizes(CListCtrl*);
    BOOL GetDialogData(LPCTSTR,CString&);
    BOOL GetDialogData(LPCTSTR,DWORD&);
    BOOL GetDialogKey(CString&);
    BOOL GetDialogName(CString&);
    BOOL GetPixelData(CRect&);
    BOOL MoveControlX(UINT,LONG);
    BOOL MoveControlXY(UINT,LONG,LONG);
    BOOL MoveControlY(UINT,LONG);
    BOOL ReloadControl(CWnd*,LPCTSTR);
    BOOL RemoveControl(CWnd*);
    BOOL SaveColumnSizes(CListCtrl*);
    BOOL SetControlProperty(PDLGCTLINFO,DWORD);
    BOOL SetDialogData(LPCTSTR,DWORD);
    BOOL SetDialogData(LPCTSTR,LPCTSTR);
    BOOL StorePixelData();
    BOOL StretchControlX(UINT,LONG);
    BOOL StretchControlXY(UINT,LONG,LONG);
    BOOL StretchControlY(UINT,LONG);
    CAdUiDialog(UINT,CWnd* = NULL,HINSTANCE = NULL);
    CSize* GetCurrentDelta();
    LPVOID GetElasticPointer();
    virtual ~CAdUiDialog();
    void GetDialogHelpTag(CString&);
    void GetElasticMinMaxInfo(MINMAXINFO&);
    void LockDialogHeight();
    void LockDialogWidth();
    void SetDialogHelpTag(LPCTSTR);
    void SetDialogMaxExtents(int,int);
    void SetDialogMinExtents(int,int);
    void SetDialogName(LPCTSTR);
    void SetElasticSize(CSize&,BOOL);
    void SetPersistency(BOOL);
    void SetRootKey(LPCTSTR);
    void SetTabSize(LPARAM,BOOL);

protected:
    virtual bool IsThemingEnabled() const override { return false; }

protected:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg LRESULT OnColorThemeChanged(WPARAM, LPARAM);
    afx_msg void OnGetMinMaxInfo(MINMAXINFO*);
    afx_msg void OnSize(UINT,int,int);
    BOOL m_bEnableElasticMessageMap;
    UINT m_templateid;
    virtual BOOL DoDialogHelp();
    virtual void DoDataExchange(CDataExchange*);
    virtual void OnDialogHelp();
    virtual void OnInitDialogBegin();
    virtual void OnInitDialogFinish();
    virtual void OnOK();

    DECLARE_MESSAGE_MAP()
};
