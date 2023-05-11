// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbSymbolTable: public AcDbObject
{
public:
    typedef AcDbSymbolTableRecord RecordType;

    ACDB_DECLARE_MEMBERS(AcDbSymbolTable);

    AcDbSymbolTable();
    virtual ~AcDbSymbolTable();

    Acad::ErrorStatus add(AcDbObjectId&,AcDbSymbolTableRecord*);
    Acad::ErrorStatus add(AcDbSymbolTableRecord*);
    Acad::ErrorStatus getAt(const ACHAR*,AcDbObjectId&,bool = false) const;
    Acad::ErrorStatus getAt(const ACHAR*,AcDbSymbolTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus newIterator(AcDbSymbolTableIterator*&,bool = true,bool = true) const;
    bool has(AcDbObjectId) const;
    bool has(const ACHAR*) const;

    Acad::ErrorStatus getIdAt(const ACHAR*,AcDbObjectId&,bool = false) const;
};
