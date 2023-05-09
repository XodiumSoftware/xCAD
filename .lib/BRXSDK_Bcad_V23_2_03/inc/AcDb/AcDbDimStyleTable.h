// Copyright (C) Menhirs NV. All rights reserved.
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
