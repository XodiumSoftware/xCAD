// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbVertex: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbVertex);

    AcDbVertex();
    ~AcDbVertex();

protected:
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
};
