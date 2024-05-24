// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcCm/AcCmColor.h"
#include "AcDb/AcDbSymbolTableRecord.h"

/** _ */
class BRX_EXPORT AcDbDimStyleTableRecord: public AcDbSymbolTableRecord
{
public:
    typedef AcDbDimStyleTable TableType;

    ACDB_DECLARE_MEMBERS(AcDbDimStyleTableRecord);

    AcDbDimStyleTableRecord();
    virtual ~AcDbDimStyleTableRecord();

    #include "AcDb/AcDbDimensioningVariables.h"

    Acad::ErrorStatus getDimapost(ACHAR*&) const;
    Acad::ErrorStatus getDimblk(ACHAR*&) const;
    Acad::ErrorStatus getDimblk1(ACHAR*&) const;
    Acad::ErrorStatus getDimblk2(ACHAR*&) const;
    Acad::ErrorStatus getDimpost(ACHAR*&) const;
    Acad::ErrorStatus setDimfit(int);
    Acad::ErrorStatus setDimunit(int);
    AcDbObjectId arrowId(AcDb::DimArrowFlags) const;
    bool isModifiedForRecompute() const;
    int dimfit() const;
    int dimunit() const;
};
