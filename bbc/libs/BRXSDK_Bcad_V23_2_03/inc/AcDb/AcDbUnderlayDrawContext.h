// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
struct AcDbUnderlayDrawContext
{
    Adesk::UInt8 contrast;
    Adesk::UInt8 fade;
    bool adjustColorForBackground;
    bool monochrome;
};
