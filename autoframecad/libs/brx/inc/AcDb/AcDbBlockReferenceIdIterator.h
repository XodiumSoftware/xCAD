// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObjectId.h"

class AcDbBlockReference;

/** _ */
class BRX_IMPORTEXPORT AcDbBlockReferenceIdIterator
{
private:
    AcDbObjectIdArray m_array;
    int m_pos;
    friend class AcDbBlockTableRecord;

    AcDbBlockReferenceIdIterator();
public:
    ~AcDbBlockReferenceIdIterator();

    Acad::ErrorStatus getBlockReference(AcDbBlockReference*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus getBlockReferenceId(AcDbObjectId&) const;
    Acad::ErrorStatus getDatabase(AcDbDatabase*&) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    bool done() const;
    void start();
    void step();
};
