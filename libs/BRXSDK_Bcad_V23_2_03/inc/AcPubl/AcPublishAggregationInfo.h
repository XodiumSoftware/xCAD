// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcPl/AcPlPlotLogger.h"
#include "DMM/AcDMMEPlotProperty.h"
#include "DMM/AcDMMResourceInfo.h"

/** _ */
class BRX_IMPORTEXPORT AcPublishAggregationInfo
{
public:
    AcPublishAggregationInfo() {}
    virtual ~AcPublishAggregationInfo() {}

    virtual AcPlPlotLogger* GetPlotLogger() = 0;
    virtual const ACHAR* dwfFileName() = 0;
    virtual const ACHAR* dwfPassword() = 0;
    virtual void AddGlobalProperties(AcDMMEPlotPropertyVec) = 0;
    virtual void AddGlobalResources(AcDMMResourceVec) = 0;
};