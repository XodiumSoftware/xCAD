// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CNav/CNavArray.h"
#include "MFC/CNav/CNavData.h"

/** _ */
class CNavDataArray: public CNavArray<CNavData>
{
public:
    CNavDataArray();
    virtual ~CNavDataArray();
};