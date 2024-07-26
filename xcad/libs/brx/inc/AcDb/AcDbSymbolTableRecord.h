// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
