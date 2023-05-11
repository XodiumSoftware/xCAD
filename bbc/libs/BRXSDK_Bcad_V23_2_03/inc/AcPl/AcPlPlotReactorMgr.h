// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

class AcPlPlotReactor;

/** _ */
class BRX_IMPORTEXPORT AcPlPlotReactorMgr
{
public:
    void addReactor(AcPlPlotReactor*);
    void removeReactor(AcPlPlotReactor*);
};
