// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbLoftOptions.h"
#include "AcDb/AcDbRevolveOptions.h"
#include "AcDb/AcDbSurface.h"
#include "AcDb/AcDbSweepOptions.h"

/** _ */
class BRX_EXPORT AcDb3dSolid: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDb3dSolid);

    AcDb3dSolid();
    virtual ~AcDb3dSolid();

    virtual Acad::ErrorStatus booleanOper(AcDb::BoolOperType,AcDb3dSolid*);
    virtual Acad::ErrorStatus chamferEdges(const AcArray<AcDbSubentId*>&,const AcDbSubentId&,double,double);
    virtual Acad::ErrorStatus checkInterference(const AcDb3dSolid*,Adesk::Boolean,Adesk::Boolean&,AcDb3dSolid*&) const;
    virtual Acad::ErrorStatus cleanBody();
    virtual Acad::ErrorStatus convertToBrepAtSubentPaths(const AcDbFullSubentPathArray&);
    virtual Acad::ErrorStatus copyEdge(const AcDbSubentId&,AcDbEntity*&);
    virtual Acad::ErrorStatus copyFace(const AcDbSubentId&,AcDbEntity*&);
    virtual Acad::ErrorStatus createBox(double,double,double);
    virtual Acad::ErrorStatus createExtrudedSolid(AcDbEntity*,const AcDbSubentId&,const AcGeVector3d&,AcDbSweepOptions&);
    virtual Acad::ErrorStatus createExtrudedSolid(AcDbEntity*,const AcDbSubentId&,double,AcDbSweepOptions&);
    virtual Acad::ErrorStatus createExtrudedSolid(AcDbEntity*,const AcGeVector3d&,AcDbSweepOptions&);
    virtual Acad::ErrorStatus createFrustum(double,double,double,double);
    virtual Acad::ErrorStatus createLoftedSolid(AcArray<AcDbEntity*>&,AcArray<AcDbEntity*>&,AcDbEntity*,AcDbLoftOptions&);
    virtual Acad::ErrorStatus createPyramid(double,int,double,double = 0.0);
    virtual Acad::ErrorStatus createRevolvedSolid(AcDbEntity*,const AcDbSubentId&,const AcGePoint3d&,const AcGeVector3d&,double,double,AcDbRevolveOptions&);
    virtual Acad::ErrorStatus createRevolvedSolid(AcDbEntity*,const AcGePoint3d&,const AcGeVector3d&,double,double,AcDbRevolveOptions&);
    virtual Acad::ErrorStatus createSphere(double);
    virtual Acad::ErrorStatus createSweptSolid(AcDbEntity*,AcDbEntity*,AcDbSweepOptions&);
    virtual Acad::ErrorStatus createSweptSolid(AcDbEntity*,const AcDbSubentId&,AcDbEntity*,AcDbSweepOptions&);
    virtual Acad::ErrorStatus createTorus(double,double);
    virtual Acad::ErrorStatus createWedge(double,double,double);
    virtual Acad::ErrorStatus extrude(const AcDbRegion*,double,double = 0.0);
    virtual Acad::ErrorStatus extrudeAlongPath(const AcDbRegion*,const AcDbCurve*,double = 0.0);
    virtual Acad::ErrorStatus extrudeFaces(const AcArray<AcDbSubentId*>&,double,double);
    virtual Acad::ErrorStatus extrudeFacesAlongPath(const AcArray<AcDbSubentId*>&,const AcDbCurve*);
    virtual Acad::ErrorStatus filletEdges(const AcArray<AcDbSubentId*>&,const AcGeDoubleArray&,const AcGeDoubleArray&,const AcGeDoubleArray&);
    virtual Acad::ErrorStatus getArea(double&) const;
    virtual Acad::ErrorStatus getMassProp(double&,AcGePoint3d&,double[3],double[3],double[3],AcGeVector3d[3],double[3],AcDbExtents&) const;
    virtual Acad::ErrorStatus getSection(const AcGePlane&,AcDbRegion*&) const;
    virtual Acad::ErrorStatus getSlice(AcDbSurface*,bool,AcDb3dSolid*&);
    virtual Acad::ErrorStatus getSlice(const AcGePlane&,Adesk::Boolean,AcDb3dSolid*&);
    virtual Acad::ErrorStatus getSubentColor(const AcDbSubentId&,AcCmColor&) const;
    virtual Acad::ErrorStatus getSubentMaterial(const AcDbSubentId&,AcDbObjectId&) const;
    virtual Acad::ErrorStatus getSubentMaterialMapper(const AcDbSubentId&,AcGiMapper&) const;
    virtual Acad::ErrorStatus imprintEntity(const AcDbEntity*);
    virtual Acad::ErrorStatus offsetBody(double);
    virtual Acad::ErrorStatus offsetFaces(const AcArray<AcDbSubentId*>&,double);
    virtual Acad::ErrorStatus removeFaces(const AcArray<AcDbSubentId*>&);
    virtual Acad::ErrorStatus revolve(const AcDbRegion*,const AcGePoint3d&,const AcGeVector3d&,double);
    virtual Acad::ErrorStatus separateBody(AcArray<AcDb3dSolid*>&);
    virtual Acad::ErrorStatus setRecordHistory(bool);
    virtual Acad::ErrorStatus setShowHistory(bool);
    virtual Acad::ErrorStatus setSubentColor(const AcDbSubentId&,const AcCmColor&);
    virtual Acad::ErrorStatus setSubentMaterial(const AcDbSubentId&,AcDbObjectId);
    virtual Acad::ErrorStatus setSubentMaterialMapper(const AcDbSubentId&,const AcGiMapper&);
    virtual Acad::ErrorStatus shellBody(const AcArray<AcDbSubentId*>&,double);
    virtual Acad::ErrorStatus stlOut(const ACHAR*,Adesk::Boolean,double = 0.0) const;
    virtual Acad::ErrorStatus taperFaces(const AcArray<AcDbSubentId*>&,const AcGePoint3d&,const AcGeVector3d&,double);
    virtual Acad::ErrorStatus transformFaces(const AcArray<AcDbSubentId*>&,const AcGeMatrix3d&);
    virtual Adesk::Boolean isNull() const;
    virtual Adesk::UInt32 numChanges() const;
    virtual bool recordHistory() const;
    virtual bool showHistory() const;

    //V10
    virtual Acad::ErrorStatus setBody(const void*);
    virtual AcDbSubentId internalSubentId(void*) const;
    virtual void* body() const;
    virtual void* internalSubentPtr(const AcDbSubentId&) const;

    //V14
    virtual Acad::ErrorStatus createFrom(const AcDbEntity*);

    //V18
    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);

    //V22
    Acad::ErrorStatus createSculptedSolid(const AcArray<AcDbEntity*>&, const AcGeIntArray&);

protected:
    virtual Acad::ErrorStatus subGetGsMarkersAtSubentPath(const AcDbFullSubentPath&,AcArray<Adesk::GsMarker>&) const;
    virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(AcDb::SubentType,Adesk::GsMarker,const AcGePoint3d&,const AcGeMatrix3d&,int&,AcDbFullSubentPath*&,int = 0,AcDbObjectId* = NULL) const;
    virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath&) const;
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual void subList() const;
    virtual void subViewportDraw(AcGiViewportDraw*);
};
