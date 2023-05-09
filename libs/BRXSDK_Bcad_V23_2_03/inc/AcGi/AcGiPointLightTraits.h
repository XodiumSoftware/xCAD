// Copyright (C) Menhirs NV. All rights reserved.
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
