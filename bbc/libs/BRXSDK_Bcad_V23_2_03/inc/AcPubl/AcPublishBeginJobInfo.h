// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcPl/AcPlDSDData.h"
#include "AcPl/AcPlPlotLogger.h"
#include "Misc/AcNameValuePair.h"

/** _ */
class BRX_IMPORTEXPORT AcPublishBeginJobInfo
{
public:
    AcPublishBeginJobInfo() {}
    virtual ~AcPublishBeginJobInfo() {}

    virtual AcPlPlotLogger* GetPlotLogger() = 0;
    virtual bool JobWillPublishInBackground() = 0;
    virtual bool WritePrivateSection(const ACHAR*,const AcNameValuePairVec) = 0;
    virtual const AcNameValuePairVec GetPrivateData(const ACHAR*) = 0;
    virtual const AcPlDSDData* GetDSDData() = 0;
};