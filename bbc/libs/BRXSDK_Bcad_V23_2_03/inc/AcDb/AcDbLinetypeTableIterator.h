// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcDbLinetypeTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend class AcDbLinetypeTable;
    AcDbLinetypeTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbLinetypeTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbLinetypeTableRecord*);
};
