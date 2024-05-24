// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbBreakPointRef : public AcDbObject
{
  public:
    ACDB_DECLARE_MEMBERS(AcDbBreakPointRef);

    AcDbBreakPointRef();
    ~AcDbBreakPointRef();

    enum BreakPointType
    {
        kDynamic = 0,
        kStatic = 1,
        kStatic2Point = 2
    };

    Acad::ErrorStatus intersectWith(const AcDbEntity*, AcGePoint3dArray&, AcGePoint3dArray&);
    Adesk::Int32 lineIndex() const;
    Acad::ErrorStatus setLineIndex(Adesk::Int32);
    Acad::ErrorStatus getBreakPointId(AcDbFullSubentPath&) const;
    Acad::ErrorStatus setBreakPoint(const AcGePoint3d&);
    Acad::ErrorStatus setBreakPoint2(const AcGePoint3d&);
    Acad::ErrorStatus setBreakPointId(const AcDbFullSubentPath&);
    AcGePoint3d breakPoint() const;
    AcGePoint3d breakPoint2() const;
    AcDbBreakPointRef::BreakPointType pointType() const;
    Acad::ErrorStatus setPointType(AcDbBreakPointRef::BreakPointType);
    AcDbEntity* subentPtr() const;
    Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
    Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
    Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
};
