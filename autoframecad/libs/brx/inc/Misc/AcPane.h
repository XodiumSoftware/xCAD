// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/AcStatusBarItem.h"

/** _ */
class BRX_IMPORTEXPORT AcPane: public AcStatusBarItem
{
public:
    AcPane();
    AcPane(const CString&);
    virtual ~AcPane();

    virtual BOOL GetText(CString&) const;
    virtual BOOL SetIcon(HICON);
    virtual BOOL SetMaxWidth(int);
    virtual BOOL SetMinWidth(int);
    virtual BOOL SetStyle(int);
    virtual BOOL SetText(const CString&);
    virtual HICON GetIcon() const;
    virtual int GetMaxWidth();
    virtual int GetMinWidth();
    virtual int GetStyle() const;
#ifdef _WIN32
    virtual UINT DisplayPopupPaneMenu(CMenu&);
#endif
    virtual BOOL SetPaneName(const CString&);
    virtual BOOL GetPaneName(CString&) const;
    virtual BOOL SetRegistryKey(const CString&);
    virtual BOOL GetRegistryKey(CString&) const;
};

#define ACSB_NOBORDERS 1 //deprecated
#define ACSB_INACTIVE 2
#define ACSB_STRETCH 4 //unsupported
#define ACSB_ACTIVE 8
#define ACSB_COMMAND 16 //unsupported
#define ACSB_POPUP 32 //unsupported
#define ACSB_DIVIDER 64
#define ACSB_SUBDIVIDER 128 //unsupported
#define ACSB_POPOUT ACSB_INACTIVE //deprecated
#define ACSB_NORMAL ACSB_ACTIVE //deprecated
