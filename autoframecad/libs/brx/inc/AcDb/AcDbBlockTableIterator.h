// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

class AcDbBlockTable;

/** _ */
class BRX_IMPORTEXPORT AcDbBlockTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend AcDbBlockTable;
    AcDbBlockTableIterator();

public:
    Acad::ErrorStatus getRecord(AcDbBlockTableRecord*&, AcDb::OpenMode = AcDb::kForRead, bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbBlockTableRecord*);
};
