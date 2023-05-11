// Copyright (C) Menhirs NV. All rights reserved.
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