// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbAbstractViewTable.h"

/** _ */
class BRX_EXPORT AcDbViewportTable: public AcDbAbstractViewTable
{
public:
    typedef AcDbViewportTableRecord RecordType;

    ACDB_DECLARE_MEMBERS(AcDbViewportTable);

    AcDbViewportTable();
    virtual ~AcDbViewportTable();

    Acad::ErrorStatus add(AcDbObjectId&,AcDbViewportTableRecord*);
    Acad::ErrorStatus add(AcDbViewportTableRecord*);
    Acad::ErrorStatus getAt(const ACHAR*,AcDbObjectId&,bool = false) const;
    Acad::ErrorStatus getAt(const ACHAR*,AcDbViewportTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus newIterator(AcDbViewportTableIterator*&,bool = true,bool = true) const;
    bool has(AcDbObjectId) const;
    bool has(const ACHAR*) const;
};
