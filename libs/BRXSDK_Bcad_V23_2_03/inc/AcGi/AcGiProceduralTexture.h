// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiMaterialTexture.h"

/** _ */
class AcGiProceduralTexture: public AcGiMaterialTexture
{
public:
    enum Type
    {
        kWood = 0,
        kMarble
    };

    ACRX_DECLARE_MEMBERS(AcGiProceduralTexture);
};