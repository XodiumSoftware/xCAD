// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbUnderlayReference.h"

/** _ */
class BRX_EXPORT AcDbPdfReference: public AcDbUnderlayReference
{
public:
    ACDB_DECLARE_MEMBERS(AcDbPdfReference);

    AcDbPdfReference();
    virtual ~AcDbPdfReference();

    static Adesk::UInt8 contrastDefault();
    static Adesk::UInt8 fadeDefault();
};
