// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/AcArray.h"
#include "AcDb/AcDbEntity.h"
#include "AcDb/AcDbSweepOptions.h"
#include "AcDb/AcDbFullSubentPath.h"
#include "AcDb/AcDbLoftOptions.h"
#include "AcDb/AcDbRevolveOptions.h"

class AcDbRevolvedSurface;
class AcDbSweptSurface;
class AcDbNurbSurface;
class AcDbExtrudedSurface;
class AcDbPathRef;

class AcDbLoftProfile;
class AcDb3dProfile;
class AcDbBlendOptions;

class AcDbEntity;
class AcDb3dSolid;
class AcDbSurface;
class AcDbSubentId;
class AcCmColor;

class AcGePoint3d;
class AcGeVector3d;
class AcGePlane;

class AcDbDwgFiler;
class AcDbDxfFiler;

typedef AcArray<AcDbNurbSurface*> AcDbNurbSurfaceArray;

/** _ */
class BRX_EXPORT AcDbSurface : public AcDbEntity
{
public:
    enum WireframeType
    {
      kIsolines = 0,
      kIsoparms,
    };
    enum EdgeExtensionType
    {
      kExtendEdge  = 0,
      kStretchEdge,
    };

public:
    ACDB_DECLARE_MEMBERS(AcDbSurface);

    AcDbSurface();
    virtual ~AcDbSurface();

    virtual Acad::ErrorStatus convertToRegion(AcArray<AcDbEntity*>&);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus getArea(double&) const;
    virtual Acad::ErrorStatus setUIsolineDensity(Adesk::UInt16);
    virtual Acad::ErrorStatus setVIsolineDensity(Adesk::UInt16);
    virtual Acad::ErrorStatus thicken(double,bool,AcDb3dSolid*&) const;
    virtual Adesk::UInt16 uIsolineDensity() const;
    virtual Adesk::UInt16 vIsolineDensity() const;

    static Acad::ErrorStatus createFrom(const AcDbEntity*,AcDbSurface*&);

    //V10
    virtual Acad::ErrorStatus setBody(const void*);
    virtual AcDbSubentId internalSubentId(void*) const;
    virtual void* body() const;
    virtual void* internalSubentPtr(const AcDbSubentId&) const;

    //V14
    virtual Acad::ErrorStatus createInterferenceObjects(AcArray<AcDbEntity*>&, AcDbEntity*, unsigned int) const;
    virtual Acad::ErrorStatus createSectionObjects(const AcGePlane&, AcArray<AcDbEntity*>&) const;

    virtual Acad::ErrorStatus imprintEntity(const AcDbEntity*);
    virtual Acad::ErrorStatus filletEdges(const AcArray<AcDbSubentId *>&, const AcGeDoubleArray&, const AcGeDoubleArray&, const AcGeDoubleArray&);
    virtual Acad::ErrorStatus chamferEdges(const AcArray<AcDbSubentId *>&, const AcDbSubentId&, double, double);
    virtual Acad::ErrorStatus sliceByPlane(const AcGePlane&, AcDbSurface*&, AcDbSurface*&);
    virtual Acad::ErrorStatus sliceBySurface(const AcDbSurface*, AcDbSurface*&, AcDbSurface*&);

    virtual Acad::ErrorStatus booleanUnion(const AcDbSurface*, AcDbSurface*&);
    virtual Acad::ErrorStatus booleanSubtract(const AcDbSurface*, AcDbSurface*&);
    virtual Acad::ErrorStatus booleanSubtract(const AcDb3dSolid*, AcDbSurface*&);
    virtual Acad::ErrorStatus booleanIntersect(const AcDbSurface*, AcArray<AcDbEntity*>&);
    virtual Acad::ErrorStatus booleanIntersect(const AcDb3dSolid*, AcArray<AcDbEntity*>&);

    virtual Acad::ErrorStatus getSubentColor(const AcDbSubentId&, AcCmColor&) const;
    virtual Acad::ErrorStatus getSubentMaterial(const AcDbSubentId&, AcDbObjectId&) const;
    virtual Acad::ErrorStatus getSubentMaterialMapper(const AcDbSubentId&, AcGiMapper&) const;

    virtual Acad::ErrorStatus setSubentColor(const AcDbSubentId&, const AcCmColor&);
    virtual Acad::ErrorStatus setSubentMaterial(const AcDbSubentId&, const AcDbObjectId&);
    virtual Acad::ErrorStatus setSubentMaterialMapper(const AcDbSubentId&, const AcGiMapper&);

    // V15
    Acad::ErrorStatus convertToNurbSurface(AcDbNurbSurfaceArray&);
    Acad::ErrorStatus projectOnToSurface(const AcDbEntity*, const AcGeVector3d&, AcArray<AcDbEntity*>&) const;

    Acad::ErrorStatus setWireframeType(WireframeType);
    WireframeType     getWireframeType() const;
    Acad::ErrorStatus getPerimeter(double&) const;

    Acad::ErrorStatus extendEdges(AcDbFullSubentPathArray&, double, EdgeExtensionType, bool);

    AcDbObjectId      creationActionBodyId() const;
    Acad::ErrorStatus modificationActionBodyIds(AcDbObjectIdArray&) const;

    Acad::ErrorStatus rayTest(const AcGePoint3d&, const AcGeVector3d&, double, AcDbSubentIdArray&, AcGeDoubleArray&) const;

    static Acad::ErrorStatus createLoftedSurface(const AcArray<AcDbLoftProfile*>&, const AcArray<AcDbLoftProfile*>&, AcDbLoftProfile*, AcDbLoftOptions&, AcDbSurface*&);
    static Acad::ErrorStatus createLoftedSurface(const AcArray<AcDbLoftProfile*>&, const AcArray<AcDbLoftProfile*>&, AcDbLoftProfile*, AcDbLoftOptions&, bool, AcDbObjectId&);

    static Acad::ErrorStatus createExtrudedSurface(AcDb3dProfile*, const AcGeVector3d&, AcDbSweepOptions&, AcDbExtrudedSurface*&);
    static Acad::ErrorStatus createExtrudedSurface(AcDb3dProfile*, const AcGeVector3d&, AcDbSweepOptions&, bool, AcDbObjectId&);

    static Acad::ErrorStatus createSweptSurface(AcDb3dProfile*, AcDb3dProfile*, AcDbSweepOptions&, AcDbSweptSurface*&);
    static Acad::ErrorStatus createSweptSurface(AcDb3dProfile*, AcDb3dProfile*, AcDbSweepOptions&, bool, AcDbObjectId&);

    static Acad::ErrorStatus createRevolvedSurface(AcDb3dProfile*, const AcGePoint3d&, const AcGeVector3d&, double, double, AcDbRevolveOptions&, AcDbRevolvedSurface*&);
    static Acad::ErrorStatus createRevolvedSurface(AcDb3dProfile*, const AcGePoint3d&, const AcGeVector3d&, double, double, AcDbRevolveOptions&, bool, AcDbObjectId&);
    static Acad::ErrorStatus createRevolvedSurface(AcDb3dProfile*, AcDb3dProfile*, bool, double, double, AcDbRevolveOptions&, AcDbRevolvedSurface*&);
    static Acad::ErrorStatus createRevolvedSurface(AcDb3dProfile*, AcDb3dProfile*, bool, double, double, AcDbRevolveOptions&, bool, AcDbObjectId&);

    static Acad::ErrorStatus createBlendSurface(AcDbLoftProfile*, AcDbLoftProfile*, AcDbBlendOptions*, AcDbSurface*&);
    static Acad::ErrorStatus createBlendSurface(AcDbLoftProfile*, AcDbLoftProfile*, AcDbBlendOptions*, bool, AcDbObjectId&);

    static Acad::ErrorStatus createNetworkSurface(const AcArray<AcDb3dProfile*>&, const AcArray<AcDb3dProfile*>&, AcDbSurface*&);
    static Acad::ErrorStatus createNetworkSurface(const AcArray<AcDb3dProfile*>&, const AcArray<AcDb3dProfile*>&, bool, AcDbObjectId&);

    static Acad::ErrorStatus createPatchSurface(const AcDbPathRef&, const AcDbObjectIdArray&, int, double, AcDbSurface*&);
    static Acad::ErrorStatus createPatchSurface(const AcDbPathRef&, const AcDbObjectIdArray&, int, double, bool, AcDbObjectId&);

    // BRX specific
    static Acad::ErrorStatus createPatchSurface(const AcDbFullSubentPathArray&, int, double, AcDbSurface*&);
    static Acad::ErrorStatus createPatchSurface(const AcDbFullSubentPathArray&, int, double, bool, AcDbObjectId&);

    virtual Acad::ErrorStatus getPlane(AcGePlane&, AcDb::Planarity&) const;

protected:
    virtual void subList() const;
};
