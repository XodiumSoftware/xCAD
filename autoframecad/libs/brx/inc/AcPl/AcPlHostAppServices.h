// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

class AcPlPlotLogger;

/** _ */
class __declspec(novtable) AcPlHostAppServices
{
public:
    enum PlotStatus
    {
        kSheetIdxAndName = -5,
        kDisableCancelSheet,
        kDwfFilePlotted,
        kPlottingMsg,
        kNoPlotYet,
        kPlotStart,
        kViewPlotLog,
        kPlotSuccessful,
        kPlotHadErrors,
        kPlotHadSystemError
    };

    virtual AcPlPlotLogger* getPlotLogger() = 0;
    virtual void updatePlotJobStatus(PlotStatus,const ACHAR*) = 0;
};
