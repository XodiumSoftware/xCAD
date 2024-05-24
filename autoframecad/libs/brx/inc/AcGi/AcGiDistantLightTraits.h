// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
