// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbAbstractViewTableIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcDbViewTableIterator: public AcDbAbstractViewTableIterator
{
protected:
    friend class AcDbViewTable;
    AcDbViewTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbViewTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbViewTableRecord*);
};
