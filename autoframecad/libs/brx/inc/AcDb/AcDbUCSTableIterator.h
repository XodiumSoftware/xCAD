// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

class AcDbUCSTable;

/** _ */
class BRX_IMPORTEXPORT AcDbUCSTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend AcDbUCSTable;
    AcDbUCSTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbUCSTableRecord*&, AcDb::OpenMode = AcDb::kForRead, bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbUCSTableRecord*);
};
