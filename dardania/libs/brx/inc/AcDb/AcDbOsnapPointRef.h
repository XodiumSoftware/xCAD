// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

/** _ */
class BRX_EXPORT AcDbOsnapPointRef : public AcDbPointRef
{
public:
    ACDB_DECLARE_MEMBERS(AcDbOsnapPointRef);

    AcDbOsnapPointRef();
    AcDbOsnapPointRef(const AcGePoint3d& );
    AcDbOsnapPointRef(const AcDbOsnapPointRef&);
    AcDbOsnapPointRef(AcDbPointRef::OsnapType, const AcDbFullSubentPath*, const AcDbFullSubentPath* = NULL,
                      const AcGePoint3d* = NULL, AcDbPointRef* = NULL);
    virtual ~AcDbOsnapPointRef();

    virtual AcDbPointRef& operator= (const AcDbPointRef&);
    AcDbOsnapPointRef& operator= (const AcDbOsnapPointRef&);


    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*, AcDbDatabase*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*, AcDbDatabase*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*, AcDbDatabase*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*, AcDbDatabase*) const;

    Acad::ErrorStatus  getIntIdPath(AcDbFullSubentPath&) const;
    Acad::ErrorStatus  setIntIdPath(const AcDbFullSubentPath&);
    Acad::ErrorStatus  setLastPointRef(AcDbPointRef*);
    AcDbPointRef*      lastPointRef() const;

    AcDbPointRef::OsnapType osnapType() const;
    Acad::ErrorStatus  setOsnapType(AcDbPointRef::OsnapType);

    Acad::ErrorStatus  getIdPath(AcDbFullSubentPath&) const;
    Acad::ErrorStatus  setIdPath(const AcDbFullSubentPath&);

    Acad::ErrorStatus  setPoint(const AcGePoint3d&);
    AcGePoint3d        point() const;

    double             nearPointParam() const;
    Acad::ErrorStatus  setNearPointParam(double);

protected:
    Acad::ErrorStatus  updateSubentPathGuts(AcDbFullSubentPath&, AcDbIdMapping&);
    Acad::ErrorStatus  evalPointGuts(AcDbPointRef::OsnapType, const AcGePoint3d&, const AcGePoint3d&, AcGePoint3d &);
    Acad::ErrorStatus  getIntPoints(const AcDbEntity*, const AcDbEntity*, AcDb::Intersect, AcGePoint3dArray&, int = 0, int = 0) const;


    AcGePoint3d        nearPoint();
    bool isTransSpatial(bool = true) const;

public:
    virtual bool isGeomErased() const;
    virtual bool isXrefObj(AcDbObjectIdArray&, AcDbObjectIdArray&, bool = true) const;
    virtual Acad::ErrorStatus updateXrefSubentPath();
    virtual Acad::ErrorStatus updateSubentPath(AcDbIdMapping&);
    virtual Acad::ErrorStatus evalPoint(AcGePoint3d&);

    virtual Acad::ErrorStatus getEntities(AcDbFullSubentPathArray&, bool = true) const;
    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);

    virtual void updateDueToMirror(bool = false);

public:
    Acad::ErrorStatus evalPoint(AcDbPointRef::OsnapType, const AcGePoint3d&, AcGePoint3d&);
    Acad::ErrorStatus getXrefIntHandles(AcDbHandleArrayPtRef&) const;
    Acad::ErrorStatus setXrefIntHandles(const AcDbHandleArrayPtRef&);
    Acad::ErrorStatus getXrefHandles(AcDbHandleArrayPtRef&) const;
    Acad::ErrorStatus setXrefHandles(const AcDbHandleArrayPtRef&);

protected:
    double             findNearPointParam(const AcGePoint3d&) const;
    bool getEllipseParams(double&, double&) const;
};
