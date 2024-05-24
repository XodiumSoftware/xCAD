// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"

class BrxDbSymbolTableIteratorImp;

/** _ */
class BRX_IMPORTEXPORT AcDbSymbolTableIterator
{
    friend BrxDbSymbolTableIteratorImp;
    BrxDbSymbolTableIteratorImp* m_pBrxImp;

protected:
    AcDbSymbolTableIterator();
public:
    virtual ~AcDbSymbolTableIterator();

    Acad::ErrorStatus getRecord(AcDbSymbolTableRecord*&, AcDb::OpenMode = AcDb::kForRead, bool = false) const;
    Acad::ErrorStatus getRecordId(AcDbObjectId&) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbSymbolTableRecord*);
    bool done() const;
    void start(bool = true,bool = true);
    void step(bool = true,bool = true);
};
