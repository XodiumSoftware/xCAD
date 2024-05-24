// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

class AcDbLinetypeTable;

/** _ */
class BRX_IMPORTEXPORT AcDbLinetypeTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend AcDbLinetypeTable;
    AcDbLinetypeTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbLinetypeTableRecord*&, AcDb::OpenMode = AcDb::kForRead, bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbLinetypeTableRecord*);
};
