// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
