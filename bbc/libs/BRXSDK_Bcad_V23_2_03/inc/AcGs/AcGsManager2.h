// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGs/AcGsManager.h"

/** _ */
class BRX_IMPORTEXPORT AcGsManager2 : public AcGsManager
{
public:
    AcGsManager2() {}
    virtual ~AcGsManager2() {}

    virtual AcGsDevice* getOffScreenDevice(AcGsGraphicsKernel&) = 0;
    virtual AcGsView* getOffScreenView(AcGsGraphicsKernel&, AcGsClientViewInfo&) = 0;
};
