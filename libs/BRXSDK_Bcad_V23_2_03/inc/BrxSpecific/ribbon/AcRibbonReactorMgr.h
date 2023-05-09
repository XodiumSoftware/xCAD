// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRibbonBase.h"

class AcRibbonReactor;

class BRX_EXPORT AcRibbonReactorMgr
{
public:
    void addReactor(AcRibbonReactor*);
    void removeReactor(AcRibbonReactor*);
};