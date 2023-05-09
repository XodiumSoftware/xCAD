// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbFilter: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbFilter);

    AcDbFilter();
    virtual ~AcDbFilter();

    virtual AcRxClass* indexClass() const;
};
