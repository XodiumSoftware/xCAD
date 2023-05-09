// Copyright (C) Menhirs NV. All rights reserved.
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