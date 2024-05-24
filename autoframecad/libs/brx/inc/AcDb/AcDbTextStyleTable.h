// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTable.h"

/** _ */
class BRX_EXPORT AcDbTextStyleTable: public AcDbSymbolTable
{
public:
    typedef AcDbTextStyleTableRecord RecordType;

    ACDB_DECLARE_MEMBERS(AcDbTextStyleTable);

    AcDbTextStyleTable();
    virtual ~AcDbTextStyleTable();

    Acad::ErrorStatus add(AcDbObjectId&,AcDbTextStyleTableRecord*);
    Acad::ErrorStatus add(AcDbTextStyleTableRecord*);
    Acad::ErrorStatus getAt(const ACHAR*,AcDbObjectId&,bool = false) const;
    Acad::ErrorStatus getAt(const ACHAR*,AcDbTextStyleTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus newIterator(AcDbTextStyleTableIterator*&,bool = true,bool = true) const;
    bool has(AcDbObjectId) const;
    bool has(const ACHAR*) const;
};
