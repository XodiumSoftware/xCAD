// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
