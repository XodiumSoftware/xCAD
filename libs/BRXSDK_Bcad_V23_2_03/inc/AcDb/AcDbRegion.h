// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbRegion: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbRegion);

    AcDbRegion();
    virtual ~AcDbRegion();

    virtual Acad::ErrorStatus booleanOper(AcDb::BoolOperType,AcDbRegion*);
    virtual Acad::ErrorStatus getArea(double&) const;
    virtual Acad::ErrorStatus getAreaProp(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double&,double&,AcGePoint2d&,double[2],double&,double[2],AcGeVector2d[2],double[2],AcGePoint2d&,AcGePoint2d&) const;
    virtual Acad::ErrorStatus getNormal(AcGeVector3d&) const;
    virtual Acad::ErrorStatus getPerimeter(double&) const;
    virtual Acad::ErrorStatus getPlane(AcGePlane&) const;
    virtual Adesk::Boolean isNull() const;
    virtual Adesk::UInt32 numChanges() const;

    static Acad::ErrorStatus createFromCurves(const AcDbVoidPtrArray&,AcDbVoidPtrArray&);

    //V10
    virtual Acad::ErrorStatus setBody(const void*);
    virtual AcDbSubentId internalSubentId(void*) const;
    virtual void* body() const;
    virtual void* internalSubentPtr(const AcDbSubentId&) const;

protected:
    virtual Acad::ErrorStatus subGetGsMarkersAtSubentPath(const AcDbFullSubentPath&,AcArray<Adesk::GsMarker>&) const;
    virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(AcDb::SubentType,Adesk::GsMarker,const AcGePoint3d&,const AcGeMatrix3d&,int&,AcDbFullSubentPath*&,int = 0,AcDbObjectId* = NULL) const;
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&,AcDbEntity*&) const;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,AcGePoint3dArray&,Adesk::GsMarker,Adesk::GsMarker) const;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,const AcGePlane&,AcGePoint3dArray&,Adesk::GsMarker,Adesk::GsMarker) const;
    virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath&) const;
};
