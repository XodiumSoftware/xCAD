// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTable.h"

/** _ */
class BRX_EXPORT AcDbRegAppTable: public AcDbSymbolTable
{
public:
    typedef AcDbRegAppTableRecord RecordType;

    ACDB_DECLARE_MEMBERS(AcDbRegAppTable);

    AcDbRegAppTable();
    virtual ~AcDbRegAppTable();

    Acad::ErrorStatus add(AcDbObjectId&,AcDbRegAppTableRecord*);
    Acad::ErrorStatus add(AcDbRegAppTableRecord*);
    Acad::ErrorStatus getAt(const ACHAR*,AcDbObjectId&,bool = false) const;
    Acad::ErrorStatus getAt(const ACHAR*,AcDbRegAppTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus newIterator(AcDbRegAppTableIterator*&,bool = true,bool = true) const;
    bool has(AcDbObjectId) const;
    bool has(const ACHAR*) const;
};
