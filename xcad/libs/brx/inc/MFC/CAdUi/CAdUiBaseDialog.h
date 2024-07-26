// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiTextTip.h"

class CAdUiDialog;
class CAdUiDialogImp;

#define kDialogOptionNone                   ((int)0)
#define kDialogOptionUseTips                ((int)1)
#define kDialogOptionUseTipsForContextHelp  ((int)2)

/** _ */
class BRX_IMPORTEXPORT CAdUiBaseDialog: public CDialog
{
    DECLARE_DYNAMIC(CAdUiBaseDialog);
public:
    enum{IDD=0};
    CAdUiBaseDialog(UINT,CWnd* = NULL,HINSTANCE = NULL);
    BOOL Create(LPCTSTR,CWnd* = NULL);
    BOOL Create(UINT,CWnd* = NULL);
    BOOL DisplayData();
    BOOL EditorCommandCancelled();
    int  GetUseTips();
    BOOL ValidateData();
    CToolTipCtrl* GetToolTipCtrl();
    HICON GetDialogIcon();
    LPCTSTR GetContextHelpFileName();
    LPCTSTR GetContextHelpFullPathName();
    LPCTSTR GetContextHelpPrefix();
    virtual BOOL DoDialogHelp();
    virtual BOOL ExchangeData(BOOL);
    virtual BOOL PreTranslateMessage(MSG*);
    virtual CWnd* AppMainWindow();
    virtual HINSTANCE AppResourceInstance();
    virtual INT_PTR DoModal();
    virtual int EnableMultiDocumentActivation(BOOL);
    virtual int IsMultiDocumentActivationEnabled();
    virtual LPCTSTR AppRootKey();
    virtual void EnableFloatingWindows(BOOL);
    virtual ~CAdUiBaseDialog();
    void SetAppRootKey(LPCTSTR);
    void SetContextHelpFileName(LPCTSTR);
    void SetContextHelpFullPathName(LPCTSTR);
    void SetContextHelpPrefix(LPCTSTR);
    void SetDialogIcon(HICON);
    void SetUseTips(int);

protected:
    ADUI_COMMAND_STATE m_commandState;
    afx_msg BOOL OnHelpInfo(HELPINFO*);
    afx_msg BOOL OnNotify_ToolTipText(UINT,NMHDR*,LRESULT*);
    afx_msg HBRUSH OnCtlColor(CDC*,CWnd*,UINT);
    afx_msg LRESULT OnAdUiMessage(WPARAM,LPARAM);
    afx_msg void OnActivate(UINT,CWnd*,BOOL);
    afx_msg void OnAdUiTimer(UINT);
    int m_bUseTips;
    CAdUiTextTip* m_pTextTip;
    CString m_contextHelpFileName;
    CString m_contextHelpFullPathName;
    CString m_contextHelpPrefix;
    CString m_rootKey;
    friend class CAdUiAssist;
    HICON m_hIcon;
    HINSTANCE m_hDialogResource;
    static CAdUiAssist* m_pUIAssist;
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

private:
    //BRX START
    friend CAdUiDialog;
    CAdUiDialogImp* m_pDlgImp;
    //BRX END
};
