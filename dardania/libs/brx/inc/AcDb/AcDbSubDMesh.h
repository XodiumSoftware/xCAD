// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"
#include "Misc/AcArray.h"
#include "AcDb/AcDbGlobal.h"
#include "AcDb/AcDbEntity.h"
#include "AcGe/AcGePoint3d.h"
#include "AcGe/AcGeVector3d.h"

class AcCmEntityColor;
class AcDbObjectId;
class AcDbExtents;
class AcDbSurface;
class AcDbSubentId;
class AcDbFullSubentPath;
class AcDbSurface;
class AcDb3dSolid;

class AcGePlane;
class AcGeMatrix3d;

class AcGiFaceData;
class AcGiMapper;


struct MeshFaceterSettings
{
    double faceterDevSurface;
    double faceterDevNormal;
    double faceterGridRatio;
    double faceterMaxEdgeLength;
    Adesk::UInt16 faceterMaxGrid;
    Adesk::UInt16 faceterMinUGrid;
    Adesk::UInt16 faceterMinVGrid;
    Adesk::Int16  faceterMeshType;

    MeshFaceterSettings() // lets have it properly initialised
    : faceterMaxEdgeLength(0)
    , faceterGridRatio(0.0)
    , faceterDevNormal(0.0)
    , faceterDevSurface(0.0)
    , faceterMeshType(0)
    , faceterMinUGrid(0)
    , faceterMinVGrid(0)
    , faceterMaxGrid(0)
    {
    };
};
typedef struct MeshFaceterSettings AcDbFaceterSettings;

Acad::ErrorStatus acdbGetObjectMesh(AcDbObject*, const AcDbFaceterSettings*, AcGePoint3dArray&, AcArray<Adesk::Int32>&, AcGiFaceData*&);


/** _ */
class AcDbSubDMesh: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbSubDMesh);

    AcDbSubDMesh();
    virtual ~AcDbSubDMesh();

    Acad::ErrorStatus getFaceArray(AcArray<Adesk::Int32>&) const;
    Acad::ErrorStatus getEdgeArray(AcArray<Adesk::Int32>&) const;
    Acad::ErrorStatus getVertices(AcGePoint3dArray&) const;
    Acad::ErrorStatus getNormalArray(AcGeVector3dArray&) const;

    Acad::ErrorStatus getVertexAt(Adesk::Int32, AcGePoint3d&) const;
    Acad::ErrorStatus getVertexAt(const AcDbSubentId&, AcGePoint3d&) const;

    Acad::ErrorStatus getSubDividedFaceArray(AcArray<Adesk::Int32>&) const;
    Acad::ErrorStatus getSubDividedVertices(AcGePoint3dArray&) const;
    Acad::ErrorStatus getSubDividedNormalArray(AcGeVector3dArray&) const;

    Acad::ErrorStatus getSubDividedVertexAt(Adesk::Int32, AcGePoint3d&) const;
    Acad::ErrorStatus getSubDividedVertexAt(const AcDbSubentId&, AcGePoint3d&) const;

    Acad::ErrorStatus getFacePlane(const AcDbSubentId&, AcGePlane&) const;
    Acad::ErrorStatus getSubentPath(Adesk::Int32, AcDb::SubentType, AcDbFullSubentPathArray&) const;
    Acad::ErrorStatus getAdjacentSubentPath(const AcDbFullSubentPath&, AcDb::SubentType, AcDbFullSubentPathArray&) const;    

    Acad::ErrorStatus getVertexColorArray(AcArray<AcCmEntityColor>&) const;
    Acad::ErrorStatus getVertexNormalArray(AcGeVector3dArray&) const;
    Acad::ErrorStatus getVertexTextureArray(AcGePoint3dArray&) const;

    Acad::ErrorStatus getCrease(const AcDbSubentId&, double&) const;
    Acad::ErrorStatus getCrease(const AcDbFullSubentPathArray&, AcArray<double>&) const;    

    Acad::ErrorStatus getSubentColor(const AcDbSubentId&, AcCmColor&) const;
    Acad::ErrorStatus getSubentMaterial(const AcDbSubentId&, AcDbObjectId&) const;
    Acad::ErrorStatus getSubentMaterialMapper(const AcDbSubentId&, AcGiMapper&) const;

    Acad::ErrorStatus setVertexAt(Adesk::Int32, const AcGePoint3d&);
    Acad::ErrorStatus setVertexAt(const AcDbSubentId&, const AcGePoint3d&);

    Acad::ErrorStatus setBox(double, double, double, int, int, int, int);
    Acad::ErrorStatus setWedge(double, double, double, int, int, int, int, int, int);
    Acad::ErrorStatus setCone(double, double, double, int, int, int, double, int);
    Acad::ErrorStatus setTorus(double, int, int, double, double, int);
    Acad::ErrorStatus setCylinder(double, double, double, int, int, int, int);
    Acad::ErrorStatus setSphere(double, int, int, int);
    Acad::ErrorStatus setPyramid(double, double, int, int, int, int, double, int);
    Acad::ErrorStatus setSubDMesh(const AcGePoint3dArray&, const AcArray<Adesk::Int32>&, int);

    Acad::ErrorStatus setBox(const AcGeMatrix3d&, int, int, int, int);
    Acad::ErrorStatus setWedge(const AcGeMatrix3d&, int, int, int, int, int, int);
    Acad::ErrorStatus setCone(const AcGeMatrix3d&, int, int, int, double, int);
    Acad::ErrorStatus setTorus(const AcGeMatrix3d&, int, int, double, double, int);
    Acad::ErrorStatus setCylinder(const AcGeMatrix3d&, int, int, int, int);
    Acad::ErrorStatus setSphere(const AcGeMatrix3d&, int, int, int);
    Acad::ErrorStatus setPyramid(const AcGeMatrix3d&, int, int, int, int, double, int);

    Acad::ErrorStatus setSubentColor(const AcDbSubentId&, const AcCmColor&);
    Acad::ErrorStatus setSubentMaterial(const AcDbSubentId&, const AcDbObjectId&);
    Acad::ErrorStatus setSubentMaterialMapper(const AcDbSubentId&, const AcGiMapper&);

    Acad::ErrorStatus setVertexNormalArray(AcGeVector3dArray&);
    Acad::ErrorStatus setVertexTextureArray(AcGePoint3dArray&);
    Acad::ErrorStatus setVertexColorArray(AcArray<AcCmEntityColor>&);

    Acad::ErrorStatus setCrease(double);
    Acad::ErrorStatus setCrease(const AcDbFullSubentPathArray&, double);

    Acad::ErrorStatus subdLevel(Adesk::Int32&) const;
    Acad::ErrorStatus subdRefine();
    Acad::ErrorStatus subdRefine(const AcDbFullSubentPathArray&);
    Acad::ErrorStatus subdDivideUp();
    Acad::ErrorStatus subdDivideDown();

    Acad::ErrorStatus extrudeFaces(const AcDbFullSubentPathArray&, const AcGePoint3dArray&, double);
    Acad::ErrorStatus extrudeFaces(const AcDbFullSubentPathArray&, double, const AcGeVector3d&, double);
    Acad::ErrorStatus extrudeConnectedFaces(const AcDbFullSubentPathArray&, const AcGePoint3dArray&, double);
    Acad::ErrorStatus extrudeConnectedFaces(const AcDbFullSubentPathArray&, double, const AcGeVector3d&, double);
    Acad::ErrorStatus splitFace(const AcDbSubentId&, const AcDbSubentId&, const AcGePoint3d&, const AcDbSubentId&, const AcGePoint3d&);

    Acad::ErrorStatus mergeFaces(const AcDbFullSubentPathArray&);
    Acad::ErrorStatus collapse(const AcDbSubentId&);
    Acad::ErrorStatus cap(const AcDbFullSubentPathArray&);
    Acad::ErrorStatus spin(const AcDbSubentId&);
    Acad::ErrorStatus isWatertight(bool&) const;

    Acad::ErrorStatus numOfVertices(Adesk::Int32&) const;
    Acad::ErrorStatus numOfEdges(Adesk::Int32&) const;
    Acad::ErrorStatus numOfFaces(Adesk::Int32&) const;

    Acad::ErrorStatus numOfSubDividedVertices(Adesk::Int32&) const;
    Acad::ErrorStatus numOfSubDividedFacesAt(const AcDbFullSubentPathArray&, Adesk::Int32&) const;
    Acad::ErrorStatus numOfSubDividedFaces(Adesk::Int32&) const;    

    Acad::ErrorStatus convertToSolid(bool, bool, AcDb3dSolid*&) const;
    Acad::ErrorStatus convertToSurface(bool, bool, AcDbSurface*&) const;
    Acad::ErrorStatus convertToSurface(bool, const AcDbSubentId&, AcDbSurface*&) const;

    Acad::ErrorStatus computeSurfaceArea(double&) const;
    Acad::ErrorStatus computeVolume(double&) const;
    Acad::ErrorStatus computeRayIntersection(const AcGePoint3d&, const AcGeVector3d&, AcArray<AcDbSubentId>&, AcArray<double>&, AcGePoint3dArray&) const;

    virtual void dragStatus(const AcDb::DragStat);
    virtual bool bounds(AcDbExtents&) const;

    // BRX specific (since V21)

    // get + set vertex properties by index
    Acad::ErrorStatus getVertexNormalAt(Adesk::Int32 index,  AcGeVector3d& vtxNormal) const;
    Acad::ErrorStatus getVertexTextureAt(Adesk::Int32 index, AcGePoint3d& texturePoint) const;
    Acad::ErrorStatus getVertexColorAt(Adesk::Int32 index,   AcCmEntityColor& vtxColor) const;

    Acad::ErrorStatus setVertexNormalAt(Adesk::Int32 index,  const AcGeVector3d& vtxNormal);
    Acad::ErrorStatus setVertexTextureAt(Adesk::Int32 index, const AcGePoint3d& texturePoint);
    Acad::ErrorStatus setVertexColorAt(Adesk::Int32 index,   const AcCmEntityColor& vtxColor);

    // get + set vertex properties by location
    Acad::ErrorStatus getVertexNormalAt(const AcGePoint3d& vtx,  AcGeVector3d& vtxNormal, double tol = 1.0e-06) const;
    Acad::ErrorStatus getVertexTextureAt(const AcGePoint3d& vtx, AcGePoint3d& texturePoint, double tol = 1.0e-06) const;
    Acad::ErrorStatus getVertexColorAt(const AcGePoint3d& vtx,   AcCmEntityColor& vtxColor, double tol = 1.0e-06) const;

    Acad::ErrorStatus setVertexNormalAt(const AcGePoint3d& vtx,  const AcGeVector3d& vtxNormal, double tol = 1.0e-06);
    Acad::ErrorStatus setVertexTextureAt(const AcGePoint3d& vtx, const AcGePoint3d& texturePoint, double tol = 1.0e-06);
    Acad::ErrorStatus setVertexColorAt(const AcGePoint3d& vtx,   const AcCmEntityColor& vtxColor, double tol = 1.0e-06);
};
