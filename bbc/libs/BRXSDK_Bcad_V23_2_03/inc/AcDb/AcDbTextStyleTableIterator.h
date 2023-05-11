// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcDbTextStyleTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend class AcDbTextStyleTable;
    AcDbTextStyleTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbTextStyleTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbTextStyleTableRecord*);
};
