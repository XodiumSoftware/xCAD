// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbDimension.h"

/** _ */
class BRX_EXPORT AcDbOrdinateDimension: public AcDbDimension
{
public:
    ACDB_DECLARE_MEMBERS(AcDbOrdinateDimension);

    AcDbOrdinateDimension();
    AcDbOrdinateDimension(Adesk::Boolean,const AcGePoint3d&,const AcGePoint3d&,const ACHAR* = NULL,AcDbObjectId = AcDbObjectId::kNull);
    ~AcDbOrdinateDimension();

    Acad::ErrorStatus setDefiningPoint(const AcGePoint3d&);
    Acad::ErrorStatus setLeaderEndPoint(const AcGePoint3d&);
    Acad::ErrorStatus setOrigin(const AcGePoint3d&);
    Acad::ErrorStatus useXAxis();
    Acad::ErrorStatus useYAxis();
    AcGePoint3d definingPoint() const;
    AcGePoint3d leaderEndPoint() const;
    AcGePoint3d origin() const;
    Adesk::Boolean isUsingXAxis() const;
    Adesk::Boolean isUsingYAxis() const;
};
