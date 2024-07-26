// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGePoint3d.h"
#include "Misc/AcHeapOperators.h"

/** _ */
class BRX_IMPORTEXPORT AcDbExtents: public AcHeapOperators
{
private:
    AcGePoint3d m_min;
    AcGePoint3d m_max;

public:
    AcDbExtents();
    AcDbExtents(const AcGePoint3d&,const AcGePoint3d&);
    AcDbExtents(const AcDbExtents&);

    bool operator==(const AcDbExtents&);

    Acad::ErrorStatus addBlockExt(AcDbBlockTableRecord*);
    Acad::ErrorStatus set(const AcGePoint3d&,const AcGePoint3d&);
    AcGePoint3d maxPoint() const;
    AcGePoint3d minPoint() const;
    void addExt(const AcDbExtents&);
    void addPoint(const AcGePoint3d&);
    void expandBy(const AcGeVector3d&);
    void transformBy(const AcGeMatrix3d&);
};
