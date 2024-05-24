// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbFormattedTableData.h"

class BRX_IMPORTEXPORT AcDbTableContent : public AcDbFormattedTableData
{
public:
    ACDB_DECLARE_MEMBERS(AcDbTableContent);

    AcDbTableContent();
    ~AcDbTableContent();
    
    virtual const ACHAR* cellStyle(int, int) const;
    virtual Acad::ErrorStatus setCellStyle(int, int, const ACHAR*);

    virtual double columnWidth(int) const;
    virtual Acad::ErrorStatus setColumnWidth(int, double);

    virtual double rowHeight(int) const;
    virtual Acad::ErrorStatus setRowHeight(int, double);

    virtual AcDbObjectId tableStyleId() const;
    virtual Acad::ErrorStatus setTableStyleId(const AcDbObjectId&);
};
