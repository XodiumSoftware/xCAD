// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcPl/AcPlDSDEntry.h"
#include "AcPl/AcPlPlotLogger.h"

/** _ */
class BRX_IMPORTEXPORT AcPublishSheetInfo
{
public:
    AcPublishSheetInfo() {}
    virtual ~AcPublishSheetInfo() {}

    virtual AcPlPlotLogger* GetPlotLogger() = 0;
    virtual const ACHAR* GetUniqueId() = 0;
    virtual const AcPlDSDEntry* GetDSDEntry() = 0;
};