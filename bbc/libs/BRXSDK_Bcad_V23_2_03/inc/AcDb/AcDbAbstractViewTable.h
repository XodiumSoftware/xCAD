// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTable.h"

/** _ */
class BRX_EXPORT AcDbAbstractViewTable: public AcDbSymbolTable
{
public:
    ACDB_DECLARE_MEMBERS(AcDbAbstractViewTable);

    AcDbAbstractViewTable();
    virtual ~AcDbAbstractViewTable();

    Acad::ErrorStatus add(AcDbAbstractViewTableRecord*);
    Acad::ErrorStatus add(AcDbObjectId&,AcDbAbstractViewTableRecord*);
    Acad::ErrorStatus getAt(const ACHAR*,AcDbAbstractViewTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus getAt(const ACHAR*,AcDbObjectId&,bool = false) const;
    Acad::ErrorStatus newIterator(AcDbAbstractViewTableIterator*&,bool = true,bool = true) const;
    bool has(AcDbObjectId) const;
    bool has(const ACHAR*) const;
};