// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTable.h"

/** _ */
class BRX_EXPORT AcDbLinetypeTable: public AcDbSymbolTable
{
public:
    typedef AcDbLinetypeTableRecord RecordType;

    ACDB_DECLARE_MEMBERS(AcDbLinetypeTable);

    AcDbLinetypeTable();
    virtual ~AcDbLinetypeTable();

    Acad::ErrorStatus add(AcDbLinetypeTableRecord*);
    Acad::ErrorStatus add(AcDbObjectId&,AcDbLinetypeTableRecord*);
    Acad::ErrorStatus getAt(const ACHAR*,AcDbLinetypeTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus getAt(const ACHAR*,AcDbObjectId&,bool = false) const;
    Acad::ErrorStatus newIterator(AcDbLinetypeTableIterator*&,bool = true,bool = true) const;
    bool has(AcDbObjectId) const;
    bool has(const ACHAR*) const;
};
