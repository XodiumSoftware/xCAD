// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbAbstractViewTableIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcDbViewportTableIterator: public AcDbAbstractViewTableIterator
{
protected:
    friend class AcDbViewportTable;
    AcDbViewportTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbViewportTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbViewportTableRecord*);
};
