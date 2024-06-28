// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiDrawableTraits.h"
#include "AcGi/AcGiVisualStyle.h"

/** _ */
class AcGiVisualStyleTraits: public AcGiDrawableTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiVisualStyleTraits);

    virtual const AcGiVisualStyle& acgiVisualStyle() const = 0;
    virtual void setAcGiVisualStyle(const AcGiVisualStyle&) = 0;
};