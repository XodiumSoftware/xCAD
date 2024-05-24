// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcDbBlockTableRecordIterator
{
protected:
    class BrxDbBlockTableRecordIteratorImp* m_pBrxImp;
private:
    friend class BrxDbBlockTableRecordImp;
    AcDbBlockTableRecordIterator();
public:
    virtual ~AcDbBlockTableRecordIterator();

    Acad::ErrorStatus getEntity(AcDbEntity*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus getEntityId(AcDbObjectId&) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbEntity*);
    AcDbBlockTableRecord* blockTableRecord() const;
    bool done() const;
    void start(bool = true,bool = true);
    void step(bool = true,bool = true);
};
