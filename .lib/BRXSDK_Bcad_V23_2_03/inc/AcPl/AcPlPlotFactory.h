// Copyright (C) Menhirs NV. All rights reserved.
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
