// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbUnderlayReference.h"

/** _ */
class BRX_EXPORT AcDbDgnReference: public AcDbUnderlayReference
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDgnReference);

    AcDbDgnReference();
    virtual ~AcDbDgnReference();
};
