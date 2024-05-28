// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbFace: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbFace);

    AcDbFace();
    AcDbFace(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kTrue);
    AcDbFace(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kTrue);
    ~AcDbFace();

    Acad::ErrorStatus getVertexAt(Adesk::UInt16,AcGePoint3d&) const;
    Acad::ErrorStatus isEdgeVisibleAt(Adesk::UInt16,Adesk::Boolean&) const;
    Acad::ErrorStatus makeEdgeInvisibleAt(Adesk::UInt16);
    Acad::ErrorStatus makeEdgeVisibleAt(Adesk::UInt16);
    Acad::ErrorStatus setVertexAt(Adesk::UInt16,const AcGePoint3d&);
};
