// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

class AcDbDimStyleTable;

/** _ */
class BRX_IMPORTEXPORT AcDbDimStyleTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend AcDbDimStyleTable;
    AcDbDimStyleTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbDimStyleTableRecord*&, AcDb::OpenMode = AcDb::kForRead, bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbDimStyleTableRecord*);
};
