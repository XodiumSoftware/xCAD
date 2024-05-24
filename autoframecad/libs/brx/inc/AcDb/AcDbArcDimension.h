// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbDimension.h"

/** _ */
class BRX_EXPORT AcDbArcDimension: public AcDbDimension
{
public:
    ACDB_DECLARE_MEMBERS(AcDbArcDimension);

    AcDbArcDimension();
    AcDbArcDimension(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const ACHAR* = NULL,AcDbObjectId = AcDbObjectId::kNull);
    ~AcDbArcDimension();

    AcGePoint3d arcPoint() const;
    AcGePoint3d centerPoint() const;
    AcGePoint3d leader1Point() const;
    AcGePoint3d leader2Point() const;
    AcGePoint3d xLine1Point() const;
    AcGePoint3d xLine2Point() const;
    Acad::ErrorStatus setArcEndParam(const double&);
    Acad::ErrorStatus setArcPoint(const AcGePoint3d&);
    Acad::ErrorStatus setArcStartParam(const double&);
    Acad::ErrorStatus setArcSymbolType(const int);
    Acad::ErrorStatus setCenterPoint(const AcGePoint3d&);
    Acad::ErrorStatus setHasLeader(const bool&);
    Acad::ErrorStatus setIsPartial(const bool&);
    Acad::ErrorStatus setLeader1Point(const AcGePoint3d&);
    Acad::ErrorStatus setLeader2Point(const AcGePoint3d&);
    Acad::ErrorStatus setXLine1Point(const AcGePoint3d&);
    Acad::ErrorStatus setXLine2Point(const AcGePoint3d&);
    bool hasLeader() const;
    bool isPartial() const;
    double arcEndParam() const;
    double arcStartParam() const;
    int arcSymbolType() const;
};
