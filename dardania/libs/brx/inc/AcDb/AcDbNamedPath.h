// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
