// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

class AcDbTextStyleTable;

/** _ */
class BRX_IMPORTEXPORT AcDbTextStyleTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend AcDbTextStyleTable;
    AcDbTextStyleTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbTextStyleTableRecord*&, AcDb::OpenMode = AcDb::kForRead, bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbTextStyleTableRecord*);
};
