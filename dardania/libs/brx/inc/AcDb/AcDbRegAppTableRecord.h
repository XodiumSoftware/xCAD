// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
