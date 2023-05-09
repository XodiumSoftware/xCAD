// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbPolyFaceMesh: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbPolyFaceMesh);

    AcDbPolyFaceMesh();
    ~AcDbPolyFaceMesh();

    Acad::ErrorStatus appendFaceRecord(AcDbFaceRecord*);
    Acad::ErrorStatus appendFaceRecord(AcDbObjectId&,AcDbFaceRecord*);
    Acad::ErrorStatus appendVertex(AcDbObjectId&,AcDbPolyFaceMeshVertex*);
    Acad::ErrorStatus appendVertex(AcDbPolyFaceMeshVertex*);
    Acad::ErrorStatus openSequenceEnd(AcDbSequenceEnd*&,AcDb::OpenMode);
    Acad::ErrorStatus openVertex(AcDbVertex*&,AcDbObjectId,AcDb::OpenMode,bool = false);
    AcDbObjectIterator* vertexIterator() const;
    Adesk::Int16 numFaces() const;
    Adesk::Int16 numVertices() const;
};
