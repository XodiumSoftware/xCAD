// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiStandardLightTraits.h"

/** _ */
class BRX_IMPORTEXPORT AcGiDistantLightTraits : public AcGiStandardLightTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiDistantLightTraits);

    virtual AcGeVector3d lightDirection() const = 0;
    virtual bool isSunlight() const = 0;
    virtual void setIsSunlight(bool) = 0;
    virtual void setLightDirection(const AcGeVector3d&) = 0;
};
