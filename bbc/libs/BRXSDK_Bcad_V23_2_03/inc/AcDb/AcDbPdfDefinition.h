// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbUnderlayDefinition.h"

/** _ */
class BRX_EXPORT AcDbPdfDefinition: public AcDbUnderlayDefinition
{
public:
    ACDB_DECLARE_MEMBERS(AcDbPdfDefinition);

    AcDbPdfDefinition();
    virtual ~AcDbPdfDefinition();
};
