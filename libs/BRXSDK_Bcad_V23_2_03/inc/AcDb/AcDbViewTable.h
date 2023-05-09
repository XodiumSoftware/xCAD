// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbAbstractViewTable.h"

/** _ */
class BRX_EXPORT AcDbViewTable: public AcDbAbstractViewTable
{
public:
    typedef AcDbViewTableRecord RecordType;

    ACDB_DECLARE_MEMBERS(AcDbViewTable);

    AcDbViewTable();
    virtual ~AcDbViewTable();

    Acad::ErrorStatus add(AcDbObjectId&,AcDbViewTableRecord*);
    Acad::ErrorStatus add(AcDbViewTableRecord*);
    Acad::ErrorStatus getAt(const ACHAR*,AcDbObjectId&,bool = false) const;
    Acad::ErrorStatus getAt(const ACHAR*,AcDbViewTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus newIterator(AcDbViewTableIterator*&,bool = true,bool = true) const;
    bool has(AcDbObjectId) const;
    bool has(const ACHAR*) const;
};
