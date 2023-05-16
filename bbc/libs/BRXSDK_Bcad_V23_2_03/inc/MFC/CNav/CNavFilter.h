// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

/** _ */
class CNavFilter: public CStringArray
{
public:
    BOOL IsAllowed(LPCTSTR);
    CNavFilter();
    int     Find(LPCTSTR);
    int     GetCount();
    INT_PTR GetTagIndex();
    LPCTSTR GetDescription();
    LPTSTR SetFrom(LPTSTR,BOOL = FALSE);
    virtual ~CNavFilter();
    void GetFullDescription(CString&);
    void SetDescription(LPCTSTR);
    void SetFullDescription(LPCTSTR);
    void SetTagIndex(INT_PTR);
protected:
    CString m_description;
    INT_PTR m_tagIndex;
};