// Copyright (C) Menhirs NV. All rights reserved.
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
