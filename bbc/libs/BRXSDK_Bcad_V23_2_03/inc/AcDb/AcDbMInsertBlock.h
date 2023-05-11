// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbBlockReference.h"

/** _ */
class BRX_EXPORT AcDbMInsertBlock: public AcDbBlockReference
{
public:
    ACDB_DECLARE_MEMBERS(AcDbMInsertBlock);

    AcDbMInsertBlock();
    AcDbMInsertBlock(const AcGePoint3d&,AcDbObjectId,Adesk::UInt16,Adesk::UInt16,double,double);
    ~AcDbMInsertBlock();

    Acad::ErrorStatus setColumns(Adesk::UInt16);
    Acad::ErrorStatus setColumnSpacing(double);
    Acad::ErrorStatus setRows(Adesk::UInt16);
    Acad::ErrorStatus setRowSpacing(double);
    Adesk::UInt16 columns() const;
    Adesk::UInt16 rows() const;
    double columnSpacing() const;
    double rowSpacing() const;
};
