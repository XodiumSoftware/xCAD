// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcDbAbstractViewTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend class AcDbAbstractViewTable;
    AcDbAbstractViewTableIterator();

public:
    Acad::ErrorStatus getRecord(AcDbAbstractViewTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbAbstractViewTableRecord*);
};