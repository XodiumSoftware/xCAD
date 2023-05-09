// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcDbUCSTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend class AcDbUCSTable;
    AcDbUCSTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbUCSTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbUCSTableRecord*);
};
