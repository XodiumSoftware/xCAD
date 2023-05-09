// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbUnderlayReference.h"

/** _ */
class BRX_EXPORT AcDbDwfReference: public AcDbUnderlayReference
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDwfReference);

    AcDbDwfReference();
    virtual ~AcDbDwfReference();
};
