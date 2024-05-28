// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiNonEntityTraits.h"

/** _ */
class AcGiSolidBackgroundTraits: public AcGiNonEntityTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiSolidBackgroundTraits);

    virtual AcCmEntityColor colorSolid() const = 0;
    virtual void setColorSolid(const AcCmEntityColor&) = 0;
};
