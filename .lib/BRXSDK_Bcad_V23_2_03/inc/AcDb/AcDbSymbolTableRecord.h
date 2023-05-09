// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbSymbolTableRecord: public AcDbObject
{
public:
    typedef AcDbSymbolTable TableType;

    ACDB_DECLARE_MEMBERS(AcDbSymbolTableRecord);

    AcDbSymbolTableRecord();
    virtual ~AcDbSymbolTableRecord();

    Acad::ErrorStatus getName(ACHAR*&) const;
    Acad::ErrorStatus getName(AcString&) const;
    Acad::ErrorStatus getName(const ACHAR*&) const;
    Acad::ErrorStatus setName(const ACHAR*);
    bool isDependent() const;
    bool isResolved() const;
};
