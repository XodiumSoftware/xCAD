// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTable.h"

/** _ */
class BRX_EXPORT AcDbBlockTable: public AcDbSymbolTable
{
public:
    typedef AcDbBlockTableRecord RecordType;

    ACDB_DECLARE_MEMBERS(AcDbBlockTable);

    AcDbBlockTable();
    virtual ~AcDbBlockTable();

    Acad::ErrorStatus add(AcDbBlockTableRecord*);
    Acad::ErrorStatus add(AcDbObjectId&,AcDbBlockTableRecord*);
    Acad::ErrorStatus getAt(const ACHAR*,AcDbBlockTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus getAt(const ACHAR*,AcDbObjectId&,bool = false) const;
    Acad::ErrorStatus newIterator(AcDbBlockTableIterator*&,bool = true,bool = true) const;
    bool has(AcDbObjectId) const;
    bool has(const ACHAR*) const;
};
