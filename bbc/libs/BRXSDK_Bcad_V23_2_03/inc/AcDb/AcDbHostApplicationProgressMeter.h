// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcDbHostApplicationProgressMeter
{
public:
    AcDbHostApplicationProgressMeter();
    virtual ~AcDbHostApplicationProgressMeter();

    virtual void meterProgress();
    virtual void setLimit(int);
    virtual void start(const ACHAR* = NULL);
    virtual void stop();
};
