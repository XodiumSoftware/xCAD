// Copyright (C) Menhirs NV. All rights reserved.
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
