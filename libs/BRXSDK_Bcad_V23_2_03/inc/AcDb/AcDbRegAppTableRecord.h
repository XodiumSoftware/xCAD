// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableRecord.h"

/** _ */
class BRX_EXPORT AcDbRegAppTableRecord: public AcDbSymbolTableRecord
{
public:
    typedef AcDbRegAppTable TableType;

    ACDB_DECLARE_MEMBERS(AcDbRegAppTableRecord);

    AcDbRegAppTableRecord();
    virtual ~AcDbRegAppTableRecord();
};
