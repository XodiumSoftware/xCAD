// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcGsScreenShot
{
public:
    AcGsScreenShot();
    virtual ~AcGsScreenShot() = 0;

    virtual Adesk::Boolean getColorMap(int,Adesk::UInt8&,Adesk::UInt8&,Adesk::UInt8&) const = 0;
    virtual Adesk::Boolean getSize(int&,int&,int&) const = 0;
    virtual const void* getScanline(int,int) const = 0;
};