// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class AcGiMaterialTexture: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcGiMaterialTexture);

    virtual bool operator==(const AcGiMaterialTexture&) const;
};