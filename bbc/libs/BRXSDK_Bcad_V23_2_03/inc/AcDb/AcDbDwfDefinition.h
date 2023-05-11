// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbUnderlayDefinition.h"

/** _ */
class BRX_EXPORT AcDbDwfDefinition: public AcDbUnderlayDefinition
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDwfDefinition);

    AcDbDwfDefinition();
    virtual ~AcDbDwfDefinition();
};
