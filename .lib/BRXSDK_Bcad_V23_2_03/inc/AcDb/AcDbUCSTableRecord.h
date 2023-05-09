// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableRecord.h"

/** _ */
class BRX_EXPORT AcDbUCSTableRecord: public AcDbSymbolTableRecord
{
public:
    typedef AcDbUCSTable TableType;

    ACDB_DECLARE_MEMBERS(AcDbUCSTableRecord);

    AcDbUCSTableRecord();
    virtual ~AcDbUCSTableRecord();

    Acad::ErrorStatus setUcsBaseOrigin(const AcGePoint3d&,AcDb::OrthographicView);
    AcGePoint3d origin() const;
    AcGePoint3d ucsBaseOrigin(AcDb::OrthographicView) const;
    AcGeVector3d xAxis() const;
    AcGeVector3d yAxis() const;
    void setOrigin(const AcGePoint3d&);
    void setXAxis(const AcGeVector3d&);
    void setYAxis(const AcGeVector3d&);
};
