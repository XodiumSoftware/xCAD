// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbVertex.h"

/** _ */
class BRX_EXPORT AcDb3dPolylineVertex: public AcDbVertex
{
public:
    ACDB_DECLARE_MEMBERS(AcDb3dPolylineVertex);

    AcDb3dPolylineVertex();
    AcDb3dPolylineVertex(const AcGePoint3d&);
    ~AcDb3dPolylineVertex();

    Acad::ErrorStatus setPosition(const AcGePoint3d&);
    AcDb::Vertex3dType vertexType() const;
    AcGePoint3d position() const;

protected:
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
};
