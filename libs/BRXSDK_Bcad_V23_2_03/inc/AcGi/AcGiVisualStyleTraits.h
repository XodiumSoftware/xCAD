// Copyright (C) Menhirs NV. All rights reserved.
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