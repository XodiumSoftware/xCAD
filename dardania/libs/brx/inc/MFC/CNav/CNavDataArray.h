// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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