// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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