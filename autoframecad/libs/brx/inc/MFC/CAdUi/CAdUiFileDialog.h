// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiGlobal.h"
class CAdUiTextTip;
class CToolTipCtrl;

/** _ */
class BRX_IMPORTEXPORT CAdUiFileDialog: public CFileDialog
{
    DECLARE_DYNAMIC(CAdUiFileDialog);
public:
    BOOL EditorCommandCancelled();
    int  GetUseTips();
    CAdUiFileDialog(BOOL,LPCTSTR = NULL,LPCTSTR = NULL,DWORD = OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,LPCTSTR = NULL,CWnd* = NULL,HINSTANCE = NULL);
    enum{IDD=0};
    HICON GetDialogIcon();
    LPCTSTR GetContextHelpFileName();
    LPCTSTR GetContextHelpFullPathName();
    LPCTSTR GetContextHelpPrefix();
    virtual BOOL DoDialogHelp();
    virtual BOOL PreTranslateMessage(MSG*);
    virtual CWnd* AppMainWindow();
    virtual HINSTANCE AppResourceInstance();
    virtual INT_PTR DoModal();
    virtual LPCTSTR AppRootKey();
    virtual void EnableFloatingWindows(BOOL);
    virtual void OnDialogHelp();
    virtual ~CAdUiFileDialog();
    void GetDialogHelpTag(CString&);
    void GetDialogName(CString&);
    void SetContextHelpFileName(LPCTSTR);
    void SetContextHelpFullPathName(LPCTSTR);
    void SetContextHelpPrefix(LPCTSTR);
    void SetDialogHelpTag(LPCTSTR);
    void SetDialogIcon(HICON);
    void SetDialogName(LPCTSTR);
    void SetUseTips(int);
protected:
    ADUI_COMMAND_STATE m_commandState;
    afx_msg BOOL OnHelpInfo(HELPINFO*);
    afx_msg BOOL OnNotify_ToolTipText(UINT,NMHDR*,LRESULT*);
    afx_msg HBRUSH OnCtlColor(CDC*,CWnd*,UINT);
    afx_msg LRESULT OnAdUiMessage(WPARAM,LPARAM);
    int m_bUseTips;
    CAdUiTextTip* m_pTextTip;
    CString m_contextHelpFileName;
    CString m_contextHelpFullPathName;
    CString m_contextHelpPrefix;
    CString m_rootKey;
    CToolTipCtrl* m_pToolTip;
    CWnd* m_pParent;
    HICON m_hIcon;
    HINSTANCE m_hDialogResource;
    virtual ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY,UINT,LPARAM);
    virtual ADUI_REPLY OnNotifyControlChange(UINT,LPARAM);
    virtual ADUI_REPLY OnNotifyControlValid(UINT,BOOL);
    virtual ADUI_REPLY OnNotifyGeneric(UINT,LPARAM);
    virtual ADUI_REPLY OnNotifyUpdateTip(CWnd*);
    virtual BOOL FindContextHelpFullPath(LPCTSTR,CString&);
    virtual BOOL OnInitDialog();
    virtual BOOL PreCreateWindow(CREATESTRUCT&);
    virtual void DoDataExchange(CDataExchange*);
    virtual void OnInitDialogBegin();
    virtual void OnInitDialogFinish();
    virtual void PostNcDestroy();
    void BeginEditorCommand();
    void CancelEditorCommand();
    void CompleteEditorCommand(BOOL = TRUE);
    void MakeDialogsVisible(BOOL);

    DECLARE_MESSAGE_MAP()
};
