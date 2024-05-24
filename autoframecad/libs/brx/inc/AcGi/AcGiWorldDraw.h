// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiCommonDraw.h"

/** _ */
class BRX_IMPORTEXPORT AcGiWorldDraw: public AcGiCommonDraw
{
public:
    ACRX_DECLARE_MEMBERS(AcGiWorldDraw);

    virtual AcGiWorldGeometry& geometry() const = 0;
};
