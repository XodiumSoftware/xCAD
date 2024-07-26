// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CNav/CNavArray.h"
#include "MFC/CNav/CNavFilter.h"

/** _ */
class CNavFilterArray: public CNavArray<CNavFilter>
{
public:
    CNavFilterArray();
    int FindExact(LPCTSTR);
    int Find(LPCTSTR);
    virtual ~CNavFilterArray();
    void SetFrom(LPCTSTR,BOOL = FALSE);
};
