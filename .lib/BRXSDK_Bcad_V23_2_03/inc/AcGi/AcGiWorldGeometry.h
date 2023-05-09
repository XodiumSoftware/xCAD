// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiGeometry.h"

/** _ */
class BRX_IMPORTEXPORT AcGiWorldGeometry: public AcGiGeometry
{
public:
    ACRX_DECLARE_MEMBERS(AcGiWorldGeometry);

    virtual void setExtents(AcGePoint3d*) const = 0;
    virtual void startAttributesSegment();
};
