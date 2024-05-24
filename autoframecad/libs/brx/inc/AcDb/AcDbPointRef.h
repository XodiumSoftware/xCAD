// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

typedef AcArray<AcDbFullSubentPath, AcArrayObjectCopyReallocator<AcDbFullSubentPath> >AcDbFullSubentPathArray;
typedef AcArray<AcDbHandle, AcArrayObjectCopyReallocator<AcDbHandle> >AcDbHandleArrayPtRef;

/** _ */
class BRX_EXPORT AcDbPointRef : public AcRxObject
{
public:
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*, AcDbDatabase*) const = 0;
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*, AcDbDatabase*) = 0;
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*, AcDbDatabase*) const = 0;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*, AcDbDatabase*) = 0;
    virtual AcDbPointRef& operator=(const AcDbPointRef&);
    virtual Acad::ErrorStatus evalPoint(AcGePoint3d&) = 0; 
    virtual Acad::ErrorStatus getEntities(AcDbFullSubentPathArray&, bool = true) const = 0;
    virtual bool isGeomErased() const = 0;
    virtual void updateDueToMirror(bool = false) = 0;
    virtual bool isXrefObj(AcDbObjectIdArray&, AcDbObjectIdArray&, bool = true) const = 0;
    virtual Acad::ErrorStatus updateXrefSubentPath() = 0;
    virtual Acad::ErrorStatus updateSubentPath(AcDbIdMapping&) = 0;

    virtual Acad::ErrorStatus subErase(Adesk::Boolean) { return Acad::eOk; };
    virtual Acad::ErrorStatus wblockClone(AcRxObject*, AcDbObject*&, AcDbIdMapping&, Adesk::Boolean = Adesk::kTrue) const { return Acad::eOk; };
    virtual Acad::ErrorStatus deepClone(AcRxObject*, AcDbObject*&, AcDbIdMapping&, Adesk::Boolean = Adesk::kTrue) const { return Acad::eOk; };

public:
    static AcGeMatrix3d wcsToDcsMatrix(const AcDbViewport*);
    static AcGeMatrix3d mswcsToPswcs(const AcDbViewport*);
    static Acad::ErrorStatus dwgInFields(AcDbDwgFiler*, AcDbDatabase*, AcDbPointRef*&);
    static Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*,AcDbDatabase*, const AcDbPointRef*);
    static Acad::ErrorStatus dxfInFields(AcDbDxfFiler*, AcDbDatabase*, AcDbPointRef*&);
    static Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*, AcDbDatabase*, const AcDbPointRef*);
    static AcDbEntity* subentPtr(const AcDbFullSubentPath&, bool&, bool&, bool&);
    static bool calcTransform(const AcDbObjectIdArray&, AcGeMatrix3d&);

    enum OsnapType
    { 
        kOsnapNone = 0,
        kOsnapEnd,
        kOsnapMid,
        kOsnapCen,
        kOsnapNode,
        kOsnapQuad, 
        kOsnapInt,
        kOsnapIns,
        kOsnapPerp,
        kOsnapTan,
        kOsnapNear,
        kOsnapApint,
        kOsnapStart = 13,
        kOsnapCentroid
    };

protected:
};
