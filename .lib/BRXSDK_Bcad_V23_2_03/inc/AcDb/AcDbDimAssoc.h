// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class AcDbLeader;
class AcDbPointRef;
class AcDbMLeader;
class AcDbRotatedDimension;
class AcDbRadialDimensionLarge;
class AcDbOrdinateDimension;
class AcDbRadialDimension;

/** _ */
class BRX_EXPORT AcDbDimAssoc : public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDimAssoc);

    AcDbDimAssoc();
    virtual ~AcDbDimAssoc();

    enum AssocFlags
    {
        kFirstPointRef     = 1,
        kSecondPointRef    = 2,
        kThirdPointRef     = 4,
        kFourthPointRef    = 8
    };

    enum PointType
    {
        kXline1Point = 0,
        kXline2Point,
        kOriginPoint = 0,
        kDefiningPoint,
        kXline1Start = 0,
        kXline1End,
        kXline2Start,
        kXline2End,
        kVertexPoint = 2,
        kChordPoint = 0,
        kCenterPoint,
        kFarChordPoint = 1,
        kOverrideCenterPoint,
        kAngLineStart = 2,
        kJogPoint,
        kAngLineEnd = 3,
        kLeaderPoint = 0
    };

    enum
    {
        kMaxPointRefs = 4
    };

    enum RotatedDimType
    {
        kUnknown       = 0,
        kParallel,
        kPerpendicular,
    };

    ////////////////virtual functions
    virtual void modifiedGraphics(const AcDbEntity* pObj);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus swapReferences (const AcDbIdMapping&);

protected:
    Acad::ErrorStatus   updateDimension(AcDbDiametricDimension*, AcGePoint3d*, bool = true);
    Acad::ErrorStatus   updateDimension(AcDbRotatedDimension*, AcGePoint3d*, bool = true);
    Acad::ErrorStatus   updateDimension(AcDbRadialDimensionLarge*, AcGePoint3d*, bool = true);
    Acad::ErrorStatus   updateDimension(AcDbLeader*, AcGePoint3d*, bool = true);
    Acad::ErrorStatus   updateDimension(AcDbAlignedDimension*, AcGePoint3d*, bool = true);
    Acad::ErrorStatus   updateDimension(AcDbOrdinateDimension*, AcGePoint3d*, bool = true);
    Acad::ErrorStatus   updateDimension(AcDbRadialDimension*, AcGePoint3d* , bool = true);
    Acad::ErrorStatus   updateDimension(AcDbArcDimension*, AcGePoint3d*, bool = true);
    Acad::ErrorStatus   updateDimension(AcDb3PointAngularDimension*, AcGePoint3d*, bool = true);
    Acad::ErrorStatus   updateDimension(AcDb2LineAngularDimension*, AcGePoint3d*, bool = true);
    Acad::ErrorStatus   updateDimension(AcDbMLeader*,  AcGePoint3d*, bool = true);

public:
    Acad::ErrorStatus setPointRef(int, AcDbPointRef*);
    const AcDbPointRef *pointRef(int) const;
    Acad::ErrorStatus setRotatedDimType(RotatedDimType);
    RotatedDimType    rotatedDimType() const;
    AcDbObjectId dimObjId() const;
    Acad::ErrorStatus setDimObjId(const AcDbObjectId&);
    Acad::ErrorStatus removePointRef(int);
    Acad::ErrorStatus updateDimension(bool = true, bool = false);
    Acad::ErrorStatus setAssocFlag(int, bool);
    void setAssocFlag(int);
    bool assocFlag(int) const;
    int assocFlag();
    Acad::ErrorStatus startOopsWatcher(bool = true);
    void removeOopsWatcher();
    Acad::ErrorStatus restoreAssocFromOopsWatcher();
    bool hasOopsWatcher() const;
    Acad::ErrorStatus addToPointRefReactor();
    Acad::ErrorStatus addToDimensionReactor(bool = true);
    Acad::ErrorStatus removeAssociativity(bool = true);
    bool isTransSpatial() const;
    Acad::ErrorStatus setTransSpatial(bool);
    Acad::ErrorStatus startCmdWatcher();
    Acad::ErrorStatus post(AcDbObjectId , AcDbObjectId&, bool = true);
    Acad::ErrorStatus getDimAssocGeomIds(AcDbObjectIdArray&) const;
    bool isAllGeomErased() const;

protected:
    Acad::ErrorStatus updateDimLineAndTextLocation(AcDbRotatedDimension*, const AcGePoint3d*, const AcGePoint3d*);
    Acad::ErrorStatus updateDimLineAndTextLocation(AcDbAlignedDimension*, const AcGePoint3d*, const AcGePoint3d*);
    Acad::ErrorStatus updateDimLineAndTextLocation(AcDb2LineAngularDimension*, const AcGePoint3d*, const AcGePoint3d*);
    Acad::ErrorStatus updateDimLineAndTextLocation(AcDb3PointAngularDimension*, const AcGePoint3d*, const AcGePoint3d*);
    Acad::ErrorStatus updateDimLineAndTextLocation(AcDbArcDimension*, const AcGePoint3d*,  const AcGePoint3d*);
    Acad::ErrorStatus setPointRefReactor(int, bool = true);
    Acad::ErrorStatus removeDimExtDict();
    bool isPointBetweenRays(const AcGePoint3d& ,const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGeVector3d&);
    Acad::ErrorStatus calculate3PointAngDimArcLocation(const AcGePoint3d*, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d*, const AcGeVector3d&,
                                                       AcGePoint3d&, AcGePoint3d&);
    Acad::ErrorStatus calculate2LineAngDimArcLocation(const AcGePoint3d*, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d*,
                                                      const AcGeVector3d&, AcGePoint3d&, AcGePoint3d&);
public:
    void updateDueToMirror(bool);
    Acad::ErrorStatus updateFillet(const AcDbObjectIdArray&);
    Acad::ErrorStatus updateAssociativity(const AcDbObjectIdArray&);
    Acad::ErrorStatus updateXrefSubentPath();
    Acad::ErrorStatus updateSubentPath(AcDbIdMapping&);

};
