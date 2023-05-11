// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiNonEntityTraits.h"

/** _ */
class BRX_IMPORTEXPORT AcGiLightTraits : public AcGiNonEntityTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiLightTraits);

    virtual bool isOn() const = 0;
    virtual void setOn(bool) = 0;
};
