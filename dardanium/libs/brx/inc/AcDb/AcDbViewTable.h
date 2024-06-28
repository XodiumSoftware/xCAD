// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
