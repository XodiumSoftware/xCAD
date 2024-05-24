// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
