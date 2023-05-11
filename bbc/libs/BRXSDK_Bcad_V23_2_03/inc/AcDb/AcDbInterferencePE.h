// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class AcDbInterferencePE: public AcRxObject
{
public:
    enum Flags
    {
        kDefault = 0
    };

    ACRX_DECLARE_MEMBERS(AcDbInterferencePE);

    virtual Acad::ErrorStatus createInterferenceObjects(AcArray<AcDbEntity*>&,AcDbEntity*,AcDbEntity*,unsigned int) const = 0;
};
