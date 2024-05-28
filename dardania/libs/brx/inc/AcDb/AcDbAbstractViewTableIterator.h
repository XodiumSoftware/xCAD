// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

class AcDbAbstractViewTable;

/** _ */
class BRX_IMPORTEXPORT AcDbAbstractViewTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend AcDbAbstractViewTable;
    AcDbAbstractViewTableIterator();

public:
    Acad::ErrorStatus getRecord(AcDbAbstractViewTableRecord*&, AcDb::OpenMode = AcDb::kForRead, bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbAbstractViewTableRecord*);
};