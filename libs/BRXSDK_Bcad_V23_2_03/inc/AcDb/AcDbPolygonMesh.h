// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbPolygonMesh: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbPolygonMesh);

    AcDbPolygonMesh();
    AcDbPolygonMesh(AcDb::PolyMeshType,Adesk::Int16,Adesk::Int16,const AcGePoint3dArray&,Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kTrue);
    ~AcDbPolygonMesh();

    Acad::ErrorStatus appendVertex(AcDbObjectId&,AcDbPolygonMeshVertex*);
    Acad::ErrorStatus appendVertex(AcDbPolygonMeshVertex*);
    Acad::ErrorStatus convertToPolyMeshType(AcDb::PolyMeshType);
    Acad::ErrorStatus makeMClosed();
    Acad::ErrorStatus makeMOpen();
    Acad::ErrorStatus makeNClosed();
    Acad::ErrorStatus makeNOpen();
    Acad::ErrorStatus openSequenceEnd(AcDbSequenceEnd*&,AcDb::OpenMode);
    Acad::ErrorStatus openVertex(AcDbPolygonMeshVertex*&,AcDbObjectId,AcDb::OpenMode,bool = false);
    Acad::ErrorStatus setMSize(Adesk::Int16);
    Acad::ErrorStatus setMSurfaceDensity(Adesk::Int16);
    Acad::ErrorStatus setNSize(Adesk::Int16);
    Acad::ErrorStatus setNSurfaceDensity(Adesk::Int16);
    Acad::ErrorStatus setPolyMeshType(AcDb::PolyMeshType);
    Acad::ErrorStatus straighten();
    Acad::ErrorStatus surfaceFit();
    Acad::ErrorStatus surfaceFit(AcDb::PolyMeshType,Adesk::Int16,Adesk::Int16);
    AcDb::PolyMeshType polyMeshType() const;
    AcDbObjectIterator* vertexIterator() const;
    Adesk::Boolean isMClosed() const;
    Adesk::Boolean isNClosed() const;
    Adesk::Int16 mSize() const;
    Adesk::Int16 mSurfaceDensity() const;
    Adesk::Int16 nSize() const;
    Adesk::Int16 nSurfaceDensity() const;
};
