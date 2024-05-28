// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class CNavPathname;

enum NAV_DATA_TYPE
{
    kNavUnknown = 0,
    kNavShellItem,
    kNavURL,
    kNavUNC,
    kNavExtension,
    kNavWebFolders
};

/** _ */
class CNavData: public CObject
{
public:
    BOOL GetURL(CString&);
    BOOL IsExtension();
    BOOL IsRemote();
    CNavData();
    CNavPathname* GetPathname();
    LPCTSTR GetExtensionName();
    LPCTSTR GetPassword();
    LPCTSTR GetText();
    LPCTSTR GetTextInFolder();
    LPCTSTR GetUserName();
    LPITEMIDLIST GetID();
    NAV_DATA_TYPE GetDataType();
    virtual ~CNavData();
    void SetDataType(NAV_DATA_TYPE);
    void SetExtensionName(LPCTSTR);
    void SetID(LPITEMIDLIST);
    void SetPassword(LPCTSTR);
    void SetPathname(CNavPathname*);
    void SetText(LPCTSTR);
    void SetTextInFolder(LPCTSTR);
    void SetUserName(LPCTSTR);
    void* GetUserData();
    void* SetUserData(void*);
protected:
    CNavPathname* m_pathname;
    CString m_extensionName;
    CString m_password;
    CString m_text;
    CString m_textInFolder;
    CString m_userName;
    LPITEMIDLIST m_id;
    NAV_DATA_TYPE m_dataType;
    void* m_userData;
};
