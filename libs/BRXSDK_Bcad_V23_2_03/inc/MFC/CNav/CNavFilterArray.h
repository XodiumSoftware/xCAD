// Copyright (C) Menhirs NV. All rights reserved.
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
