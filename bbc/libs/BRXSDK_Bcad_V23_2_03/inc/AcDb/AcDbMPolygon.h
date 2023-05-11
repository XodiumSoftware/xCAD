// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbHatch.h"
#include <tchar.h>

class AcDbCircle;
class AcDbMPolygonCrossingArray;
class AcDbMPolygonNode;
class AcDbPolyline;

const double AcDbMPolygonCrossingFuzz = 1.e-6;

/** _ */
class BRX_EXPORT AcDbMPolygon: public AcDbEntity
{
public:
    enum loopDir
    {
        kExterior = 0,
        kInterior,
        kAnnotation
    };

    ACDB_DECLARE_MEMBERS(AcDbMPolygon);

    AcDbMPolygon();
    virtual ~AcDbMPolygon();

    virtual Acad::ErrorStatus appendLoopFromBoundary(const AcDb2dPolyline*,bool = true,double = AcDbMPolygonCrossingFuzz);
    virtual Acad::ErrorStatus appendLoopFromBoundary(const AcDbCircle*,bool = true,double = AcDbMPolygonCrossingFuzz);
    virtual Acad::ErrorStatus appendLoopFromBoundary(const AcDbPolyline*,bool = true,double = AcDbMPolygonCrossingFuzz);
    virtual Acad::ErrorStatus appendMPolygonLoop(const AcGePoint2dArray&,const AcGeDoubleArray&,bool = true,double = AcDbMPolygonCrossingFuzz);
    virtual Acad::ErrorStatus audit(AcDbAuditInfo*);
    virtual Acad::ErrorStatus balanceDisplay();
    virtual Acad::ErrorStatus balanceTree();
    virtual Acad::ErrorStatus createLoops(const AcArray<AcGePoint2dArray>&,const AcArray<AcGeDoubleArray>&,AcDbIntArray&,bool = true,double = AcDbMPolygonCrossingFuzz);
    virtual Acad::ErrorStatus createLoopsFromBoundaries(const AcDbObjectIdArray&,AcDbIntArray&,bool = true,double = AcDbMPolygonCrossingFuzz);
    virtual Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion,AcDbObject*&,AcDbObjectId&,Adesk::Boolean&);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus evaluateHatch(bool = false);
    virtual Acad::ErrorStatus getLoopAtGsMarker(int,int&) const;
    virtual Acad::ErrorStatus getLoopDirection(int,loopDir&) const;
    virtual Acad::ErrorStatus getMPolygonLoopAt(int,AcGePoint2dArray&,AcGeDoubleArray&) const;
    virtual Acad::ErrorStatus getMPolygonTree(AcDbMPolygonNode*&) const;
    virtual Acad::ErrorStatus getPatternDefinitionAt(int,double&,double&,double&,double&,double&,AcGeDoubleArray&) const;
    virtual Acad::ErrorStatus insertMPolygonLoopAt(int,const AcGePoint2dArray&,const AcGeDoubleArray&,bool = true,double = AcDbMPolygonCrossingFuzz);
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,const AcGePlane&,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const;
    virtual Acad::ErrorStatus loopCrossesItself(bool&,bool,AcDbMPolygonCrossingArray&,const AcGePoint2dArray&,const AcGeDoubleArray&,double = AcDbMPolygonCrossingFuzz) const;
    virtual Acad::ErrorStatus loopCrossesMPolygon(bool&,bool,AcDbMPolygonCrossingArray&,const AcGePoint2dArray&,const AcGeDoubleArray&,double = AcDbMPolygonCrossingFuzz) const;
    virtual Acad::ErrorStatus removeMPolygonLoopAt(int);
    virtual Acad::ErrorStatus setElevation(double);
    virtual Acad::ErrorStatus setLoopDirection(int,loopDir);
    virtual Acad::ErrorStatus setNormal(const AcGeVector3d&);
    virtual Acad::ErrorStatus setPattern(AcDbHatch::HatchPatternType,const ACHAR*);
    virtual Acad::ErrorStatus setPatternAngle(double);
    virtual Acad::ErrorStatus setPatternColor(const AcCmColor&);
    virtual Acad::ErrorStatus setPatternDouble(bool);
    virtual Acad::ErrorStatus setPatternScale(double);
    virtual Acad::ErrorStatus setPatternSpace(double);
    virtual AcCmColor patternColor() const;
    virtual AcDbHatch* hatch();
    virtual AcDbHatch::HatchPatternType patternType() const;
    virtual AcGeVector2d getOffsetVector() const;
    virtual AcGeVector3d normal() const;
    virtual bool includesTouchingLoops(double = AcDbMPolygonCrossingFuzz) const;
    virtual bool isBalanced() const;
    virtual bool isPointOnLoopBoundary(const AcGePoint3d&,int,double = AcDbMPolygonCrossingFuzz) const;
    virtual bool loopCrossesItself(const AcGePoint2dArray&,const AcGeDoubleArray&,double = AcDbMPolygonCrossingFuzz) const;
    virtual bool patternDouble() const;
    virtual bool selfCrosses(const AcGePoint2dArray&,const AcGeDoubleArray&,double = AcDbMPolygonCrossingFuzz) const;
    virtual const ACHAR* patternName() const;
    virtual double elevation() const;
    virtual double getArea() const;
    virtual double getPerimeter() const;
    virtual double patternAngle() const;
    virtual double patternScale() const;
    virtual double patternSpace() const;
    virtual int getClosestLoopTo(const AcGePoint3d&) const;
    virtual int getParentLoop(int) const;
    virtual int isPointInsideMPolygon(const AcGePoint3d&,AcGeIntArray&,double = AcDbMPolygonCrossingFuzz) const;
    virtual int numMPolygonLoops() const;
    virtual int numPatternDefinitions() const;
    virtual void deleteMPolygonTree(AcDbMPolygonNode*) const;
    virtual void getChildLoops(int,AcGeIntArray&) const;
    virtual void saveAs(AcGiWorldDraw*,AcDb::SaveType);

    Acad::ErrorStatus setGradient(AcDbHatch::GradientPatternType,const ACHAR*);
    Acad::ErrorStatus setGradientAngle(double);
    Acad::ErrorStatus setGradientColors(unsigned int,AcCmColor*,float*);
    Acad::ErrorStatus setGradientOneColorMode(Adesk::Boolean);
    Acad::ErrorStatus setGradientShift(float);

protected:
    virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus subGetClassID(CLSID*) const;
    virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents&) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetGsMarkersAtSubentPath(const AcDbFullSubentPath&,AcArray<Adesk::GsMarker>&) const;
    virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode,Adesk::GsMarker,const AcGePoint3d&,const AcGePoint3d&,const AcGeMatrix3d&,AcGePoint3dArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray&) const;
    virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(AcDb::SubentType,Adesk::GsMarker,const AcGePoint3d&,const AcGeMatrix3d&,int&,AcDbFullSubentPath*&,int = 0,AcDbObjectId* = NULL) const;
    virtual void subList() const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath&) const;
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
};
