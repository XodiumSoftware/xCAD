// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGePoint2d.h"
#include "Misc/AcHeapOperators.h"

/** _ */
class BRX_IMPORTEXPORT AcDbExtents2d : public AcHeapOperators
{
private:
    AcGePoint2d m_min;
    AcGePoint2d m_max;

public:
    AcDbExtents2d();                                      
    AcDbExtents2d(const AcGePoint2d&,const AcGePoint2d&);
    AcDbExtents2d(const AcDbExtents2d&);

    bool operator==(const AcDbExtents2d&);

    Acad::ErrorStatus set(const AcGePoint2d&,const AcGePoint2d&);
    AcGePoint2d maxPoint() const;
    AcGePoint2d minPoint() const;
};
