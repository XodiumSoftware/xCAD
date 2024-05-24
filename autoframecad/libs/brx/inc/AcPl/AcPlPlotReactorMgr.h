// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
