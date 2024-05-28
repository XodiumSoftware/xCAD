// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiLightTraits.h"

class AcGiShadowParameters;

/** _ */
class BRX_IMPORTEXPORT AcGiStandardLightTraits : public AcGiLightTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiStandardLightTraits);

    virtual AcCmColor lightColor() const = 0;
    virtual double intensity() const = 0;
    virtual void setIntensity(double) = 0;
    virtual void setLightColor(const AcCmColor&) = 0;
    virtual void setShadowParameters(const AcGiShadowParameters&) = 0;
    virtual void shadowParameters(AcGiShadowParameters&) const = 0;
};
