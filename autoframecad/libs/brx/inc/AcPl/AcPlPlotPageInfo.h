// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcPl/AcPlObject.h"

/** _ */
class AcPlPlotPageInfo: public AcPlObject
{
public:
    ACRX_DECLARE_MEMBERS(AcPlPlotPageInfo);

    AcPlPlotPageInfo();
    virtual ~AcPlPlotPageInfo();

    long entityCount() const;
    long gradientCount() const;
    long oleObjectCount() const;
    long rasterCount() const;
    long shadedViewportType() const;
};
