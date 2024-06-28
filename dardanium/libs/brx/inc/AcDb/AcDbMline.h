// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbMline: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbMline);

    AcDbMline();
    virtual ~AcDbMline();

    Acad::ErrorStatus appendSeg(const AcGePoint3d&);
    Acad::ErrorStatus getClosestPointTo(const AcGePoint3d&,AcGePoint3d&,bool,bool = false) const;
    Acad::ErrorStatus getClosestPointTo(const AcGePoint3d&,const AcGeVector3d&,AcGePoint3d&,bool,bool = false) const;
    Acad::ErrorStatus getParametersAt(int,AcGeVoidPointerArray&) const;
    Acad::ErrorStatus moveVertexAt(int,const AcGePoint3d&);
    Acad::ErrorStatus removeLastSeg(AcGePoint3d&);
    Acad::ErrorStatus setClosedMline(bool);
    Acad::ErrorStatus setJustification(Mline::MlineJustification);
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setScale(double);
    Acad::ErrorStatus setStyle(const AcDbObjectId&);
    AcDbObjectId style() const;
    AcGePoint3d vertexAt(int) const;
    AcGeVector3d axisAt(int) const;
    AcGeVector3d miterAt(int) const;
    AcGeVector3d normal() const;
    bool closedMline() const;
    bool supressEndCaps() const;
    bool supressStartCaps() const;
    double scale() const;
    int element(const AcGePoint3d&) const;
    int numVertices() const;
    Mline::MlineJustification justification() const;
    void getPlane(AcGePlane&) const;
    void setSupressEndCaps(bool);
    void setSupressStartCaps(bool);

protected:
    virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents&) const;
    virtual Acad::ErrorStatus subGetGsMarkersAtSubentPath(const AcDbFullSubentPath&,AcArray<Adesk::GsMarker>&) const;
    virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(AcDb::SubentType,Adesk::GsMarker,const AcGePoint3d&,const AcGeMatrix3d&,int&,AcDbFullSubentPath*&,int = 0,AcDbObjectId* = NULL) const;
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&, AcDbEntity*&) const;
    virtual void subList() const;
    virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath&) const;
};
