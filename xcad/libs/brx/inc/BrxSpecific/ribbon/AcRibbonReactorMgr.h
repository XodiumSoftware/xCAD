// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRibbonBase.h"

class AcRibbonReactor;

class BRX_EXPORT AcRibbonReactorMgr
{
public:
    void addReactor(AcRibbonReactor*);
    void removeReactor(AcRibbonReactor*);
};