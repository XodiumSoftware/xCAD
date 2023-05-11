// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcDbDimStyleTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend class AcDbDimStyleTable;
    AcDbDimStyleTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbDimStyleTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbDimStyleTableRecord*);
};
