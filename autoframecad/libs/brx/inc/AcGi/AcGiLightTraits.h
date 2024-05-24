// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
