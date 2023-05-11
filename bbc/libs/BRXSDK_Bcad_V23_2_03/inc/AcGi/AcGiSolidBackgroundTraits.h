// Copyright (C) Menhirs NV. All rights reserved.
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
