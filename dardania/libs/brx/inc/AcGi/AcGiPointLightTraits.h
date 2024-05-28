// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiStandardLightTraits.h"

class AcGePoint3d;
class AcGiLightAttenuation;

/** _ */
class BRX_IMPORTEXPORT AcGiPointLightTraits: public AcGiStandardLightTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiPointLightTraits);

    virtual AcGePoint3d position() const = 0;
    virtual void lightAttenuation(AcGiLightAttenuation&) const = 0;
    virtual void setAttenuation(const AcGiLightAttenuation&) = 0;
    virtual void setPosition(const AcGePoint3d&) = 0;
};
