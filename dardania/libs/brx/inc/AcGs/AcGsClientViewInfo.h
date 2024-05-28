// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiGlobal.h"

/** _ */
struct AcGsClientViewInfo
{
    AcGiContextualColors* contextColors;
    LONG_PTR acadWindowId;
    LONG_PTR viewportId;
    LONG_PTR viewportObjectId;

    AcGsClientViewInfo()
    {
        contextColors = NULL;
        acadWindowId = 0L;
        viewportId = 0L;
        viewportObjectId = 0L;
    }
};