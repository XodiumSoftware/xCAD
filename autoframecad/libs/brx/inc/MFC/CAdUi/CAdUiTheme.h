// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiGlobal.h"

class CAdUiThemeModifiedReactor;

/** _ */
class BRX_IMPORTEXPORT CAdUiTheme
{
private:
    //BRX START
    void* m_pBrxImp;
    //BRX End

    CAdUiTheme();
    virtual ~CAdUiTheme();

public:
    BOOL GetData(int,CString&) const;
    BOOL GetData(int,DWORD&) const;
    BOOL GetFont(AdUiThemeElement,CFont*&) const;
    BOOL GetFont(AdUiThemeElement,LOGFONT*) const;
    BOOL RegisterReactor(CAdUiThemeModifiedReactor*);
    BOOL SetColor(AdUiThemeElement,COLORREF);
    BOOL SetFont(AdUiThemeElement,LOGFONT* = NULL);
    BOOL UnregisterReactor(CAdUiThemeModifiedReactor*);
    COLORREF GetColor(AdUiThemeElement) const;
    void IncrementRefCount();
    void ResumeModifiedNotifications();
    void SendModifiedNotification() const;
    void SetData(int,const CString&);
    void SetData(int,const DWORD&);
    void SetDataPtr(int,void*);
    void SuspendModifiedNotifications();
    void* GetDataPtr(int) const;

    CAdUiTheme& operator=(const CAdUiTheme*);
};