// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTable.h"

/** _ */
class BRX_EXPORT AcDbDimStyleTable: public AcDbSymbolTable
{
public:
    typedef AcDbDimStyleTableRecord RecordType;

    ACDB_DECLARE_MEMBERS(AcDbDimStyleTable);

    AcDbDimStyleTable();
    virtual ~AcDbDimStyleTable();

    Acad::ErrorStatus add(AcDbDimStyleTableRecord*);
    Acad::ErrorStatus add(AcDbObjectId&,AcDbDimStyleTableRecord*);
    Acad::ErrorStatus getAt(const ACHAR*,AcDbDimStyleTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus getAt(const ACHAR*,AcDbObjectId&,bool = false) const;
    Acad::ErrorStatus newIterator(AcDbDimStyleTableIterator*&,bool = true,bool = true) const;
    bool has(AcDbObjectId) const;
    bool has(const ACHAR*) const;
};
