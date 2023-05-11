// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbVertex.h"

/** _ */
class BRX_EXPORT AcDbPolygonMeshVertex: public AcDbVertex
{
public:
    ACDB_DECLARE_MEMBERS(AcDbPolygonMeshVertex);

    AcDbPolygonMeshVertex();
    AcDbPolygonMeshVertex(const AcGePoint3d&);
    ~AcDbPolygonMeshVertex();

    Acad::ErrorStatus setPosition(const AcGePoint3d&);
    AcDb::Vertex3dType vertexType() const;
    AcGePoint3d position() const;

protected:
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
};
