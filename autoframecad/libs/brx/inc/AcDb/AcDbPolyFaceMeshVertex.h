// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
