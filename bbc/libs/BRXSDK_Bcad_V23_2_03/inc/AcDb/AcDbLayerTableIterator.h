// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcDbLayerTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend class AcDbLayerTable;
    AcDbLayerTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbLayerTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbLayerTableRecord*);
    bool getSkipHidden() const;
    void setSkipHidden(bool);
};
