// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_IMPORTEXPORT AcDbFrame: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbFrame);

protected:
    AcDbFrame();
public:
    virtual ~AcDbFrame();
};
