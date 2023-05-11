// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiStandardLightTraits.h"

class AcGePoint3d;
class AcGiLightAttenuation;

/** _ */
class BRX_IMPORTEXPORT AcGiSpotLightTraits: public AcGiStandardLightTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiSpotLightTraits);

    virtual AcGePoint3d position() const = 0;
    virtual AcGePoint3d targetLocation() const = 0;
    virtual bool setHotspotAndFalloff(double,double) = 0;
    virtual double falloff() const = 0;
    virtual double hotspot() const = 0;
    virtual void lightAttenuation(AcGiLightAttenuation&) const = 0;
    virtual void setAttenuation(const AcGiLightAttenuation&) = 0;
    virtual void setPosition(const AcGePoint3d&) = 0;
    virtual void setTargetLocation(const AcGePoint3d&) = 0;
};
