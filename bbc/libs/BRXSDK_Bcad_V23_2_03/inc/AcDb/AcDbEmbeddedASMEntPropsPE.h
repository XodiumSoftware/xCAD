// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbEmbeddedASMEntPropsPE : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbEmbeddedASMEntPropsPE);

    virtual void setIsEmbeddedEnt(AcDbObject*, bool = true);
};
