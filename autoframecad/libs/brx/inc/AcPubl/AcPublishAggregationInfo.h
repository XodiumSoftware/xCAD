// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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