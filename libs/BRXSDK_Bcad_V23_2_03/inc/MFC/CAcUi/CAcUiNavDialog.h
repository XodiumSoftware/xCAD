// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CNav/CNavDialog.h"
#include "MFC/CNav/CNavListCtrl.h"

enum AcUiOpenNoTemplateFlag
{
    acUiOpenNoTemplateNone = 0,
    acUiOpenNoTemplateImperail,
    acUiOpenNoTemplateMetric
};

/** _ */
class BRX_IMPORTEXPORT CAcUiNavDialog: public CNavDialog
{
    DECLARE_DYNAMIC(CAcUiNavDialog)
public:
    AcUiOpenNoTemplateFlag GetOpenNoTemplateSelection();
    BOOL GetInitialViewButtonChecked();
    BOOL GetPreviewPresent();
    BOOL GetPreviewVisible();
    CAcUiNavDialog(CNavDataArray&,CNavFilterArray&,UINT = 0,CWnd* = NULL,HINSTANCE = NULL);
    short GetUpdateThumbnailOverride();
    virtual BOOL BeginDownloadFiles(CStringArray&,CDWordArray&);
    virtual BOOL FindInSearchPath(LPCTSTR,CString*);
    virtual BOOL GetProductName(CString&);
    virtual BOOL GetRecentDirectory(CString&);
    virtual BOOL LaunchBrowserDialog(CString&,LPCTSTR,LPCTSTR,LPCTSTR);
    virtual BOOL OnInitDialog();
    virtual DWORD GetDownloadActionCodes(CString&);
    virtual void DisplaySearchError(LPCTSTR);
    virtual void GetDefaultBrowserStartURL(CString&);
    virtual void OnDialogHelp();
    virtual void OnDialogHelp(LPCTSTR);
    virtual void OnDoLocate();
    virtual void OnPaintPreview(LPCTSTR,CWnd*);
    virtual ~CAcUiNavDialog();
    void SetPreviewPresent(BOOL);
    void SetPreviewVisible(BOOL);
protected:
    afx_msg void OnDestroy();
    afx_msg void OnOpenMenuPartialOpen();
    afx_msg void OnOpenMenuPartialOpenReadOnly();
    afx_msg void OnOpenNoTemplateImperial();
    afx_msg void OnOpenNoTemplateMetric();
    afx_msg void OnToolsMenuOptions();
    afx_msg void OnToolsMenuSecurity();
    afx_msg void OnUpdateThumbnailCheck();
    afx_msg void OnViewsMenuPreview();
    afx_msg void OnShowReferenceFiles();
    afx_msg void OnOnlineOptions();
    afx_msg void OnPlacesChanged();
    virtual BOOL GetOptionsState();
    virtual BOOL OnFileNameOK();
    virtual void OnCancel();
    virtual void OnFileNameChange();
    virtual void OnFilterChange();
    virtual void OnFolderItemChange();
    virtual void OnURLDownloadSuccess(CString&);
    virtual void PrepareOkMenu(CMenu*);
    virtual void PrepareToolsMenu(CMenu*);
    virtual void PrepareViewsMenu(CMenu*);
    void Do3DDwfOptionsDialog();
    void InitPreviewState();

    DECLARE_MESSAGE_MAP()
};
