// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGs/AcGsGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcGsConfigReactor
{
    virtual ~AcGsConfigReactor() {}

    virtual void configWasModified() {};
    virtual void deviceSwitchHasEnded() {};
    virtual void deviceSwitchToBegin() {};
    virtual void hardwareAccelerationWasModified(bool) {};
};