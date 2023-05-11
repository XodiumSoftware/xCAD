// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbNamedPath: public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbNamedPath);

    virtual ~AcDbNamedPath();

    virtual Acad::ErrorStatus getGeometry(AcGeCurve3d*&) const = 0;
};
