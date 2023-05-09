// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbVertex.h"

/** _ */
class BRX_EXPORT AcDbPolyFaceMeshVertex: public AcDbVertex
{
public:
    ACDB_DECLARE_MEMBERS(AcDbPolyFaceMeshVertex);

    AcDbPolyFaceMeshVertex();
    AcDbPolyFaceMeshVertex(const AcGePoint3d&);
    ~AcDbPolyFaceMeshVertex();

    Acad::ErrorStatus setPosition(const AcGePoint3d&);
    AcGePoint3d position() const;

protected:
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
};
