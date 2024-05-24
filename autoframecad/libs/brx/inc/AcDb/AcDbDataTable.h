// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbDataColumn.h"
#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbDataTable: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDataTable);

    AcDbDataTable();
    virtual ~AcDbDataTable();

    virtual Acad::ErrorStatus appendColumn(AcDbDataCell::CellType,const ACHAR* = NULL);
    virtual Acad::ErrorStatus appendRow(const AcDbDataCellArray&,bool = true);
    virtual Acad::ErrorStatus audit(AcDbAuditInfo*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus getCellAt(Adesk::UInt32,Adesk::UInt32,AcDbDataCell&) const;
    virtual Acad::ErrorStatus getColumnAt(Adesk::UInt32,const AcDbDataColumn*&) const;
    virtual Acad::ErrorStatus getColumnIndexAtName(const ACHAR*,Adesk::UInt32&) const;
    virtual Acad::ErrorStatus getColumnNameAt(Adesk::UInt32,ACHAR*&) const;
    virtual Acad::ErrorStatus getColumnTypeAt(Adesk::UInt32,AcDbDataCell::CellType&) const;
    virtual Acad::ErrorStatus getRowAt(Adesk::UInt32,AcDbDataCellArray&) const;
    virtual Acad::ErrorStatus insertColumnAt(Adesk::UInt32,AcDbDataCell::CellType,const ACHAR* = NULL);
    virtual Acad::ErrorStatus insertRowAt(Adesk::UInt32,const AcDbDataCellArray&,bool = true);
    virtual Acad::ErrorStatus removeColumnAt(Adesk::UInt32);
    virtual Acad::ErrorStatus removeRowAt(Adesk::UInt32);
    virtual Acad::ErrorStatus setCellAt(Adesk::UInt32,Adesk::UInt32,const AcDbDataCell&);
    virtual Acad::ErrorStatus setNumColsGrowSize(Adesk::UInt32);
    virtual Acad::ErrorStatus setNumColsPhysicalSize(Adesk::UInt32);
    virtual Acad::ErrorStatus setNumRowsGrowSize(Adesk::UInt32);
    virtual Acad::ErrorStatus setNumRowsPhysicalSize(Adesk::UInt32);
    virtual Acad::ErrorStatus setRowAt(Adesk::UInt32,const AcDbDataCellArray&,bool = true);
    virtual Acad::ErrorStatus setTableName(const ACHAR*);
    virtual AcDbDataTable& operator=(const AcDbDataTable&);
    virtual Adesk::UInt32 numColsGrowSize() const;
    virtual Adesk::UInt32 numColsPhysicalSize() const;
    virtual Adesk::UInt32 numColumns() const;
    virtual Adesk::UInt32 numRows() const;
    virtual Adesk::UInt32 numRowsGrowSize() const;
    virtual Adesk::UInt32 numRowsPhysicalSize() const;
    virtual const ACHAR* tableName() const;
};
