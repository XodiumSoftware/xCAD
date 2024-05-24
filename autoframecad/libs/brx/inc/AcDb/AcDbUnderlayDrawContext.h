// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
