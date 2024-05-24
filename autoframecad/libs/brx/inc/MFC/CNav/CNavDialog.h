// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiDialog.h"
#include "MFC/CNav/CNavDataArray.h"
#include "MFC/CNav/CNavFilterArray.h"

class CNavListCtrl;

enum NavInetTransferActions
{
    NAV_INET_IGNORE_CACHE = 1,
    NAV_INET_STOP_ON_ERROR = 2,
    NAV_INET_KEEP_CACHE = 4
};

enum NavToolsMenuItem
{
    NAV_TOOLS_ITEM_FIND = 1,
    NAV_TOOLS_ITEM_LOCATE = 2,
    NAV_TOOLS_ITEM_FTPMODIFY = 4,
    NAV_TOOLS_ITEM_SIMPLESTORAGE = 8,
    NAV_TOOLS_ITEM_ADDCURRENT = 16,
    NAV_TOOLS_ITEM_ADDFAVORITES = 32
};

enum OkHandlerErr
{
    NAV_OKHANDLER_SUCCESS = 0,
    NAV_OKHANDLER_NONFILESYSTEM,
    NAV_OKHANDLER_FAILURE
};

/** _ */
class CNavDialog: public CAdUiDialog
{
    DECLARE_DYNAMIC(CNavDialog)
public:
    BOOL GetAcceptAnyFileExtension();
    BOOL GetConfirmReplace();
    BOOL GetCreatingFile();
    BOOL GetFoldersOnly();
    BOOL GetMultiSelectAllowed();
    BOOL GetNoExtraExtensions();
    BOOL GetNoExtraExtensionsInPlaces();
    BOOL GetNoFTP();
    BOOL GetNoPlacesList();
    BOOL GetNoURLFileTransfer();
    BOOL GetNoURLsAllowed();
    BOOL GetPersonalFolderPath(CString&);
    BOOL GetReadOnlyAllowed();
    BOOL GetReadOnlyHidden();
    BOOL GetReadOnlySpecified();
    BOOL GetUseRegExtensionFlags();
    BOOL NavigateToFolder(LPCTSTR);
    CNavDataArray& GetDataArray();
    CNavDialog(CNavDataArray&,CNavFilterArray&,UINT = 0,CWnd* = NULL,HINSTANCE = NULL);
    CNavFilter* GetCurrentFileExtension(CString&);
    CNavFilterArray& GetFilterArray();
    CNavListCtrl* GetFolderListCtrl();
    DWORD GetInitialFilterIndex();
    enum{IDD=0};
    int GetDefaultFilterIndex();
    int GetFilterIndex();
    int GetForceFilterIndex();
    int GetToolsMenuItemPosition(NavToolsMenuItem);
    int InsertUserItemInPlaces(int,LPCTSTR,LPCTSTR);
    LPCTSTR GetDefaultFileExtension();
    LPCTSTR GetDefaultInitialFolder();
    LPCTSTR GetDialogCaption();
    LPCTSTR GetForceInitialFolder();
    LPCTSTR GetInitialFileName();
    UINT GetIDD();
    UINT GetToolsMenuItemsPresent();
    UINT GetViewMode();
    virtual BOOL BeginDownloadFiles(CStringArray&,CDWordArray&);
    virtual BOOL GetAllDialogsData(const CString&,CString&);
    virtual BOOL GetAllDialogsData(const CString&,DWORD&);
    virtual BOOL GetProductName(CString&);
    virtual BOOL SetAllDialogsData(const CString&,CString&);
    virtual BOOL SetAllDialogsData(const CString&,DWORD);
    virtual DWORD GetDownloadActionCodes(CString&);
    virtual void LocateFile();
    virtual void OnDialogHelp();
    virtual void OnDialogHelp(LPCTSTR);
    virtual ~CNavDialog();
    void AddDataToHistory();
    void BrowseCurrentObject();
    void GetCurrentFolderForPersistence(CString&);
    void GetOkButtonText(CString&,BOOL = TRUE);
    void GetSingleDataFullPath(CString&);
    void SetAcceptAnyFileExtension(BOOL);
    void SetConfirmReplace(BOOL);
    void SetCreatingFile(BOOL);
    void SetDefaultFileExtension(LPCTSTR);
    void SetDefaultFilterIndex(int);
    void SetDefaultInitialFolder(LPCTSTR);
    void SetDialogCaption(LPCTSTR);
    void SetFilterIndex(int);
    void SetFolderComboCurSel(int);
    void SetFolderListCtrl(CNavListCtrl*);
    void SetFoldersOnly(BOOL);
    void SetForceFilterIndex(int);
    void SetForceInitialFolder(LPCTSTR);
    void SetInitialFileName(LPCTSTR);
    void SetMultiSelectAllowed(BOOL);
    void SetNoExtraExtensions(BOOL);
    void SetNoExtraExtensionsInPlaces(BOOL);
    void SetNoFTP(BOOL);
    void SetNoURLFileTransfer(BOOL);
    void SetNoURLsAllowed(BOOL);
    void SetOkButtonMenuExists(BOOL);
    void SetOkButtonText(LPCTSTR);
    void SetReadOnlyAllowed(BOOL);
    void SetReadOnlyHidden(BOOL);
    void SetReadOnlySpecified(BOOL);
    void SetToolsMenuItemsPresent(UINT);
    void SetUseRegExtensionFlags(BOOL);
    void SetViewMode(UINT);
    void TrimWhiteSpace(CString&,BOOL);
    void* GetImpObject() const;
protected:
    afx_msg BOOL OnHelpInfo(HELPINFO*);
    afx_msg void OnContextMenu(CWnd*,CPoint);
    afx_msg void OnDestroy();
    afx_msg void OnKickIdle();
    afx_msg void OnSysColorChange();
    virtual ADUI_REPLY OnNotifyControlChange(UINT,LPARAM);
    virtual ADUI_REPLY OnNotifyGeneric(UINT,LPARAM);
    virtual BOOL FindInSearchPath(LPCTSTR,CString*);
    virtual BOOL GetRecentDirectory(CString&);
    virtual BOOL LaunchBrowserDialog(CString&,LPCTSTR,LPCTSTR,LPCTSTR);
    virtual BOOL OnCmdMsg(UINT,int,void*,AFX_CMDHANDLERINFO*);
    virtual BOOL OnFileNameOK();
    virtual BOOL OnInitDialog();
    virtual BOOL OnUrlOK();
    virtual BOOL PreTranslateMessage(MSG*);
    virtual BOOL ReportURLTransferStatus(CDWordArray&,CStringArray&,CStringArray&);
    virtual BOOL UpdateFileExtension(CString&,BOOL);
    virtual BOOL VerifyURLSave();
    virtual OkHandlerErr CombineDataTextWithFolderName(CNavData*,CString&);
    virtual OkHandlerErr PreprocessData(CNavDataArray&);
    virtual void DisplaySearchError(LPCTSTR);
    virtual void DoDataExchange(CDataExchange*);
    virtual void GetDefaultBrowserStartURL(CString&);
    virtual void OnCancel();
    virtual void OnDoAddToFavorites(BOOL);
    virtual void OnDoFind();
    virtual void OnDoLocate();
    virtual void OnFileNameChange();
    virtual void OnFileNameSelectionChange();
    virtual void OnFilterChange();
    virtual void OnFolderChange();
    virtual void OnFolderItemChange();
    virtual void OnOK();
    virtual void OnURLDownloadSuccess(CString&);
    virtual void PrepareOkMenu(CMenu*);
    virtual void PrepareToolsMenu(CMenu*);
    virtual void PrepareViewsMenu(CMenu*);
    virtual void Refresh();
    virtual void UpdateUIState();
    virtual void OnPlacesChanged();

    DECLARE_MESSAGE_MAP()
};
