// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcDbRegAppTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend class AcDbRegAppTable;
    AcDbRegAppTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbRegAppTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbRegAppTableRecord*);
};
