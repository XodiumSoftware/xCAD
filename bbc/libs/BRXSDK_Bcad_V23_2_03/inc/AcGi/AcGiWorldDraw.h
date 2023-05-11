// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiCommonDraw.h"

/** _ */
class BRX_IMPORTEXPORT AcGiWorldDraw: public AcGiCommonDraw
{
public:
    ACRX_DECLARE_MEMBERS(AcGiWorldDraw);

    virtual AcGiWorldGeometry& geometry() const = 0;
};
