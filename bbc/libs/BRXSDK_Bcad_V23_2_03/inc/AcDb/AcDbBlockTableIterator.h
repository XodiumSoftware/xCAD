// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcDbBlockTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend class AcDbBlockTable;
    AcDbBlockTableIterator();

public:
    Acad::ErrorStatus getRecord(AcDbBlockTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbBlockTableRecord*);
};
