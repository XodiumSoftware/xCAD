// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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