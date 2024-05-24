// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcEd/AcEdSSGetFilter.h"

/** _ */
class BRX_IMPORTEXPORT AcEdSSGetFilter2: public AcEdSSGetFilter
{
public:
//BRX START
    AcEdSSGetFilter2();
    virtual ~AcEdSSGetFilter2();
//BRX_END    
public:
    virtual void ssgetRolloverFilter(const AcDbFullSubentPath&,AcDbFullSubentPath&) {}
};