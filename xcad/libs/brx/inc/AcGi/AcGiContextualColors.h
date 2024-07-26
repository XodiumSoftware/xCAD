// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class AcGiContextualColors: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcGiContextualColors);

    virtual Adesk::UInt32 cameraClipping() const = 0;
    virtual Adesk::UInt32 cameraFrustrum() const = 0;
    virtual Adesk::UInt32 cameraGlyphs() const = 0;
    virtual Adesk::UInt32 gridAxisLines() const = 0;
    virtual Adesk::UInt32 gridMajorLines() const = 0;
    virtual Adesk::UInt32 gridMinorLines() const = 0;
    virtual Adesk::UInt32 lightEndLimit() const = 0;
    virtual Adesk::UInt32 lightFalloff() const = 0;
    virtual Adesk::UInt32 lightGlyphs() const = 0;
    virtual Adesk::UInt32 lightHotspot() const = 0;
    virtual Adesk::UInt32 lightStartLimit() const = 0;
    virtual bool flagsSet(Adesk::UInt32) const = 0;
    virtual int gridAxisLineTintXYZ() const = 0;
    virtual int gridMajorLineTintXYZ() const = 0;
    virtual int gridMinorLineTintXYZ() const = 0;
    virtual void setContextFlags(Adesk::UInt32,bool = true) = 0;
};
