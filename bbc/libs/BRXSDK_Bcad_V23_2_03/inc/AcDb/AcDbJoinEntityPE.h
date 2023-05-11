// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbJoinEntityPE : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbJoinEntityPE);

    virtual Acad::ErrorStatus joinEntity(AcDbEntity*, AcDbEntity*) const = 0;
    virtual Acad::ErrorStatus joinEntities(AcDbEntity*, const AcArray<AcDbEntity*>&, AcGeIntArray&) const = 0;
};
