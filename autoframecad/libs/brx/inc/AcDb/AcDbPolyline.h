// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbCurve.h"
#include "AcGe/AcGeCircArc2d.h"
#include "AcGe/AcGeCircArc3d.h"
#include "AcGe/AcGeLineSeg2d.h"
#include "AcGe/AcGeLineSeg3d.h"

/** _ */
class BRX_EXPORT AcDbPolyline: public AcDbCurve
{
public:
    enum SegType
    {
        kLine = 0,
        kArc,
        kCoincident,
        kPoint,
        kEmpty
    };

    ACDB_DECLARE_MEMBERS(AcDbPolyline);

    AcDbPolyline();
    AcDbPolyline(unsigned int);
    virtual ~AcDbPolyline();

    virtual Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler*,AcRxClass*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus extend(Adesk::Boolean,const AcGePoint3d&);
    virtual Acad::ErrorStatus extend(double);
    virtual Acad::ErrorStatus getArea(double&) const;
    virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d&,AcGePoint3d&,Adesk::Boolean = Adesk::kFalse) const;
    virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d&,const AcGeVector3d&,AcGePoint3d&,Adesk::Boolean = Adesk::kFalse) const;
    virtual Acad::ErrorStatus getDistAtParam(double,double&) const;
    virtual Acad::ErrorStatus getDistAtPoint(const AcGePoint3d&,double&) const;
    virtual Acad::ErrorStatus getEndParam(double&) const;
    virtual Acad::ErrorStatus getEndPoint(AcGePoint3d&) const;
    virtual Acad::ErrorStatus getFirstDeriv(const AcGePoint3d&,AcGeVector3d&) const;
    virtual Acad::ErrorStatus getFirstDeriv(double,AcGeVector3d&) const;
    virtual Acad::ErrorStatus getOffsetCurves(double,AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus getOrthoProjectedCurve(const AcGePlane&,AcDbCurve*&) const;
    virtual Acad::ErrorStatus getParamAtDist(double,double&) const;
    virtual Acad::ErrorStatus getParamAtPoint(const AcGePoint3d&,double&) const;
    virtual Acad::ErrorStatus getPlane(AcGePlane&,AcDb::Planarity&) const;
    virtual Acad::ErrorStatus getPointAtDist(double,AcGePoint3d&) const;
    virtual Acad::ErrorStatus getPointAtParam(double,AcGePoint3d&) const;
    virtual Acad::ErrorStatus getProjectedCurve(const AcGePlane&,const AcGeVector3d&,AcDbCurve*&) const;
    virtual Acad::ErrorStatus getSecondDeriv(const AcGePoint3d&,AcGeVector3d&) const;
    virtual Acad::ErrorStatus getSecondDeriv(double,AcGeVector3d&) const;
    virtual Acad::ErrorStatus getSpline(AcDbSpline*&) const;
    virtual Acad::ErrorStatus getSplitCurves(const AcGeDoubleArray&,AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus getSplitCurves(const AcGePoint3dArray&,AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus getStartParam(double&) const;
    virtual Acad::ErrorStatus getStartPoint(AcGePoint3d&) const;
    virtual Adesk::Boolean isPeriodic() const;
    virtual Adesk::Boolean isPlanar() const;
    virtual Adesk::Boolean onSegAt(unsigned int,const AcGePoint2d&,double&) const;
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;
    virtual void getEcs(AcGeMatrix3d&) const;
    virtual void saveAs(AcGiWorldDraw*,AcDb::SaveType);
    virtual Acad::ErrorStatus addVertexAt(unsigned int,const AcGePoint2d&,double = 0.0,double = -1.0,double = -1.0, Adesk::Int32 = 0);
    virtual Acad::ErrorStatus convertFrom(AcDbEntity*&,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus removeVertexAt(unsigned int);
    virtual Acad::ErrorStatus setBulgeAt(unsigned int,double);
    virtual Acad::ErrorStatus setConstantWidth(double);
    virtual Acad::ErrorStatus setNormal(const AcGeVector3d&);
    virtual Acad::ErrorStatus setPointAt(unsigned int,const AcGePoint2d&);
    virtual Acad::ErrorStatus setThickness(double);
    virtual Acad::ErrorStatus setWidthsAt(unsigned int,double,double);
    virtual void setClosed(Adesk::Boolean);
    virtual void setElevation(double);
    virtual Acad::ErrorStatus setVertexIdentifierAt(unsigned int, Adesk::Int32);
    virtual void reset(Adesk::Boolean,unsigned int);

    virtual Acad::ErrorStatus reverseCurve();
    virtual Acad::ErrorStatus getAcGeCurve(AcGeCurve3d*&, const AcGeTol& = AcGeContext::gTol) const;
    virtual Acad::ErrorStatus setFromAcGeCurve(const AcGeCurve3d&, AcGeVector3d* = NULL,
                                               const AcGeTol& = AcGeContext::gTol);

    Acad::ErrorStatus convertTo(AcDb2dPolyline*&,Adesk::Boolean = Adesk::kTrue) const;
    Acad::ErrorStatus getArcSegAt(unsigned int,AcGeCircArc2d&) const;
    Acad::ErrorStatus getArcSegAt(unsigned int,AcGeCircArc3d&) const;
    Acad::ErrorStatus getBulgeAt(unsigned int,double&) const;
    Acad::ErrorStatus getConstantWidth(double&) const;
    Acad::ErrorStatus getLineSegAt(unsigned int,AcGeLineSeg2d&) const;
    Acad::ErrorStatus getLineSegAt(unsigned int,AcGeLineSeg3d&) const;
    Acad::ErrorStatus getPointAt(unsigned int,AcGePoint2d&) const;
    Acad::ErrorStatus getPointAt(unsigned int,AcGePoint3d&) const;
    Acad::ErrorStatus getWidthsAt(unsigned int,double&,double&) const;
    Acad::ErrorStatus maximizeMemory();
    Acad::ErrorStatus minimizeMemory();
    AcGeVector3d normal() const;
    Adesk::Boolean hasBulges() const;
    Adesk::Boolean hasPlinegen() const;
    Adesk::Boolean hasWidth() const;
    Adesk::Boolean isClosed() const;
    Adesk::Boolean isOnlyLines() const;
    double elevation() const;
    double thickness() const;
    SegType segType(unsigned int) const;
    unsigned int numVerts() const;
    void setPlinegen(Adesk::Boolean);
    Acad::ErrorStatus getVertexIdentifierAt(unsigned int, Adesk::Int32&) const;
    Adesk::Boolean hasVertexIdentifiers() const;

protected:
    virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents&) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode,Adesk::GsMarker,const AcGePoint3d&,const AcGePoint3d&,const AcGeMatrix3d&,AcGePoint3dArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray&) const;
    virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(AcDb::SubentType,Adesk::GsMarker,const AcGePoint3d&,const AcGeMatrix3d&,int&,AcDbFullSubentPath*&,int,AcDbObjectId*) const;
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&,AcDbEntity*&) const;
    virtual void subGripStatus(const AcDb::GripStat);
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,const AcGePlane&,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath&) const;
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
    virtual void subViewportDraw(AcGiViewportDraw*);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
};
