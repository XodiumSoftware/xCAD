// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcDbSymbolTableIterator
{
protected:
    friend class AcDbSymbolTable;
    class AcDbSymbolTable;

    void* m_pBrxImp;

    AcDbSymbolTableIterator();
public:
    virtual ~AcDbSymbolTableIterator();

    Acad::ErrorStatus getRecord(AcDbSymbolTableRecord*&,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus getRecordId(AcDbObjectId&) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbSymbolTableRecord*);
    bool done() const;
    void start(bool = true,bool = true);
    void step(bool = true,bool = true);
};
