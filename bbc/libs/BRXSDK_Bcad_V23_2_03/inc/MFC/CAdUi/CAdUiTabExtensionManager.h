// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiGlobal.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiTabExtensionManager
{
public:
    CAdUiTab* GetTabControl() const;
    CAdUiTabExtensionManager();
    int AddExtendedTabs();
    virtual BOOL AddTab(HINSTANCE,UINT,LPCTSTR,CAdUiTabChildDialog*);
    virtual LPCTSTR GetDialogName();
    virtual ~CAdUiTabExtensionManager();
    void Initialize(CAdUiTab*,CAdUiTabMainDialog*);
//BRX START
private:
    void * m_pImp;
//BRX END
};
