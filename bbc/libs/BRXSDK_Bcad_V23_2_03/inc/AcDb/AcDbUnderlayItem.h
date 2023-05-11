// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcDb/AcDbUnderlayDrawContext.h"
#include "AcGe/AcGePoint3d.h"

class AcGiViewportDraw;
class AcGiWorldDraw;

/** _ */
class BRX_IMPORTEXPORT AcDbUnderlayItem : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbUnderlayItem);

    virtual ~AcDbUnderlayItem() = 0;

    virtual Acad::ErrorStatus draw(AcGiWorldDraw*,AcGiViewportDraw*,const AcDbUnderlayDrawContext&) const = 0;
    virtual Acad::ErrorStatus getExtents(AcGePoint2d&,AcGePoint2d&) const = 0;
    virtual Acad::ErrorStatus getOsnapPoints(const AcGeMatrix3d&,AcDb::OsnapMode,Adesk::GsMarker,const AcGePoint3d&,const AcGePoint3d&,const AcGeMatrix3d&,AcGePoint3dArray&,AcDbIntArray&) const = 0;
    virtual Acad::ErrorStatus getThumbnail(BITMAPINFO*&) const = 0;
    virtual Acad::ErrorStatus intersectWith(const AcGeMatrix3d&,const AcDbEntity*,AcDb::Intersect,const AcGePlane*,AcGePoint3dArray&,Adesk::GsMarker,Adesk::GsMarker) const = 0;
    virtual AcDb::UnitsValue getUnits() const = 0;
    virtual AcDbEntity* getSubEntityAtGsMarker(const AcGeMatrix3d&,Adesk::GsMarker) const = 0;
    virtual AcGeMatrix3d modelTransform() const = 0;
    virtual AcString getName() const = 0;
    virtual bool usingPartialContent() const = 0;

    int version() const;
};
