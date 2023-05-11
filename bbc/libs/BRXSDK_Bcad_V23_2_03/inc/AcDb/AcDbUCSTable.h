// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTable.h"

/** _ */
class BRX_EXPORT AcDbUCSTable: public AcDbSymbolTable
{
public:
    typedef AcDbUCSTableRecord RecordType;

    ACDB_DECLARE_MEMBERS(AcDbUCSTable);

    AcDbUCSTable();
    virtual ~AcDbUCSTable();

    Acad::ErrorStatus add(AcDbObjectId&,AcDbUCSTableRecord*);
    Acad::ErrorStatus add(AcDbUCSTableRecord*);
    Acad::ErrorStatus getAt(const ACHAR*,AcDbObjectId&,bool = false) const;
    Acad::ErrorStatus getAt(const ACHAR*,AcDbUCSTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus newIterator(AcDbUCSTableIterator*&,bool = true,bool = true) const;
    bool has(AcDbObjectId) const;
    bool has(const ACHAR*) const;
};
