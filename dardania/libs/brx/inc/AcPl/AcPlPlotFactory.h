// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

class AcPlPlotEngine;

/** _ */
class BRX_IMPORTEXPORT AcPlPlotFactory
{
public:
    enum PreviewEngineFlags
    {
        kShowPlot = 1,
        kShowNextSheet = 2,
        kShowPreviousSheet = 4
    };

    static Acad::ErrorStatus createPreviewEngine(AcPlPlotEngine*&,long = kShowPlot);
    static Acad::ErrorStatus createPublishEngine(AcPlPlotEngine*&);
};
