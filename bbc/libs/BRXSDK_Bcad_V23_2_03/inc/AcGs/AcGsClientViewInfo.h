// Copyright (C) Menhirs NV. All rights reserved.
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