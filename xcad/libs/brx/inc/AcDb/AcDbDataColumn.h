// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbDataCell.h"

/** _ */
class AcDbDataColumn: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbDataColumn);

    AcDbDataColumn();
    AcDbDataColumn(const AcDbDataColumn&);
    AcDbDataColumn(const AcDbDataCell::CellType,const ACHAR* = NULL);
    virtual ~AcDbDataColumn();

    virtual Acad::ErrorStatus appendCell(const AcDbDataCell&);
    virtual Acad::ErrorStatus getCellAt(Adesk::UInt32,AcDbDataCell&) const;
    virtual Acad::ErrorStatus getIndexAtCell(const AcDbDataCell&,Adesk::UInt32&) const;
    virtual Acad::ErrorStatus insertCellAt(Adesk::UInt32,const AcDbDataCell&);
    virtual Acad::ErrorStatus removeCellAt(Adesk::UInt32);
    virtual Acad::ErrorStatus setCellAt(Adesk::UInt32,const AcDbDataCell&);
    virtual Acad::ErrorStatus setColumnName(const ACHAR*);
    virtual Acad::ErrorStatus setColumnType(AcDbDataCell::CellType);
    virtual Acad::ErrorStatus setGrowLength(Adesk::UInt32);
    virtual Acad::ErrorStatus setPhysicalLength(Adesk::UInt32);
    virtual AcDbDataCell::CellType columnType() const;
    virtual AcDbDataColumn& operator=(const AcDbDataColumn&);
    virtual Adesk::UInt32 growLength() const;
    virtual Adesk::UInt32 numCells() const;
    virtual Adesk::UInt32 physicalLength() const;
    virtual const ACHAR* columnName() const;
};
