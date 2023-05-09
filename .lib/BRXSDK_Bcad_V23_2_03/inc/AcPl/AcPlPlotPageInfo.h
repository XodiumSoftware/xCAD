// Copyright (C) Menhirs NV. All rights reserved.
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
