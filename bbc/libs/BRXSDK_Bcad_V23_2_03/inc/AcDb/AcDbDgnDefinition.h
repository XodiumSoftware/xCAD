// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbUnderlayDefinition.h"

/** _ */
class BRX_EXPORT AcDbDgnDefinition: public AcDbUnderlayDefinition
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDgnDefinition);

    AcDbDgnDefinition();
    virtual ~AcDbDgnDefinition();
};
