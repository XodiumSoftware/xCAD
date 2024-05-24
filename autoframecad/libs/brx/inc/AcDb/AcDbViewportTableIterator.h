// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbAbstractViewTableIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcDbViewportTableIterator: public AcDbAbstractViewTableIterator
{
protected:
    friend class AcDbViewportTable;
    AcDbViewportTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbViewportTableRecord*&, AcDb::OpenMode = AcDb::kForRead, bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbViewportTableRecord*);
};
