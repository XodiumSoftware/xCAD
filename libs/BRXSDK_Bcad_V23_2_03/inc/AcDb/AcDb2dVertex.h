// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbVertex.h"

/** _ */
class BRX_EXPORT AcDb2dVertex: public AcDbVertex
{
public:
    ACDB_DECLARE_MEMBERS(AcDb2dVertex);

    AcDb2dVertex();
    AcDb2dVertex(const AcGePoint3d&,double = 0.0,double = 0.0,double = 0.0,double = 0.0);
    ~AcDb2dVertex();

    Acad::ErrorStatus ignoreTangent();
    Acad::ErrorStatus setBulge(double);
    Acad::ErrorStatus setEndWidth(double);
    Acad::ErrorStatus setPosition(const AcGePoint3d&);
    Acad::ErrorStatus setStartWidth(double);
    Acad::ErrorStatus setTangent(double);
    Acad::ErrorStatus useTangent();
    AcDb::Vertex2dType vertexType() const;
    AcGePoint3d position() const;
    Adesk::Boolean isTangentUsed() const;
    double bulge() const;
    double endWidth() const;
    double startWidth() const;
    double tangent() const;

protected:
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&, AcDbEntity*&) const;
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
};
