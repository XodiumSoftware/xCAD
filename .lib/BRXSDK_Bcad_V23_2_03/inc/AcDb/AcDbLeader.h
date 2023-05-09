// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbCurve.h"

/** _ */
class BRX_EXPORT AcDbLeader: public AcDbCurve
{
public:
    enum AnnoType
    {
        kMText = 0,
        kFcf,
        kBlockRef,
        kNoAnno
    };

    ACDB_DECLARE_MEMBERS(AcDbLeader);

    AcDbLeader();
    ~AcDbLeader();

    DBCURVE_METHODS
    virtual Acad::ErrorStatus attachAnnotation(const AcDbObjectId&);
    virtual Acad::ErrorStatus detachAnnotation();
    virtual Acad::ErrorStatus evaluateLeader();
    virtual Acad::ErrorStatus setAnnotationOffset(const AcGeVector3d&);
    virtual Acad::ErrorStatus setColorIndex (Adesk::UInt16,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setDimasz(double);
    virtual Acad::ErrorStatus setDimclrd(AcCmColor&);
    virtual Acad::ErrorStatus setDimgap(double);
    virtual Acad::ErrorStatus setDimldrblk(AcDbObjectId);
    virtual Acad::ErrorStatus setDimldrblk(const ACHAR*);
    virtual Acad::ErrorStatus setDimlwd(AcDb::LineWeight);
    virtual Acad::ErrorStatus setDimsah(bool);
    virtual Acad::ErrorStatus setDimscale(double);
    virtual Acad::ErrorStatus setDimtad(int);
    virtual Acad::ErrorStatus setDimtxsty(AcDbObjectId);
    virtual Acad::ErrorStatus setDimtxt(double);
    virtual AcCmColor dimclrd() const;
    virtual AcDb::LineWeight dimlwd() const;
    virtual AcDbHardPointerId dimensionStyle() const;
    virtual AcDbObjectId annotationObjId() const;
    virtual AcDbObjectId dimldrblk() const;
    virtual AcDbObjectId dimtxsty() const;
    virtual AcGePoint3d firstVertex() const;
    virtual AcGePoint3d lastVertex() const;
    virtual AcGePoint3d vertexAt(int) const;
    virtual AcGeVector3d annotationOffset() const;
    virtual AcGeVector3d normal() const;
    virtual Adesk::Boolean appendVertex(const AcGePoint3d&);
    virtual Adesk::Boolean hasArrowHead() const;
    virtual Adesk::Boolean hasHookLine() const;
    virtual Adesk::Boolean isSplined() const;
    virtual Adesk::Boolean setVertexAt(int,const AcGePoint3d&);
    virtual bool dimsah() const;
    virtual double dimasz() const;
    virtual double dimgap() const;
    virtual double dimscale() const;
    virtual double dimtxt() const;
    virtual int dimtad() const;
    virtual int numVertices() const;
    virtual void copied(const AcDbObject*,const AcDbObject*);
    virtual void disableArrowHead();
    virtual void enableArrowHead();
    virtual void erased(const AcDbObject*,Adesk::Boolean = Adesk::kTrue);
    virtual void goodbye(const AcDbObject*);
    virtual void modified(const AcDbObject*);
    virtual void removeLastVertex();
    virtual void setDimensionStyle(const AcDbHardPointerId&);
    virtual void setDimVars();
    virtual void setPlane(const AcGePlane&);
    virtual void setToSplineLeader();
    virtual void setToStraightLeader();

    Acad::ErrorStatus getDimstyleData(AcDbDimStyleTableRecord*&) const;
    Acad::ErrorStatus setDimstyleData(AcDbDimStyleTableRecord*);
    Acad::ErrorStatus setDimstyleData(AcDbObjectId);
    AnnoType annoType() const;
    double annoHeight() const;
    double annoWidth() const;

protected:
    virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,const AcGePlane&,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const;
};
