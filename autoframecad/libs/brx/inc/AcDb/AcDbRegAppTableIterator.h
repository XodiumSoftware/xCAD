// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

class AcDbRegAppTable;

/** _ */
class BRX_IMPORTEXPORT AcDbRegAppTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend AcDbRegAppTable;
    AcDbRegAppTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbRegAppTableRecord*&, AcDb::OpenMode = AcDb::kForRead, bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbRegAppTableRecord*);
};
