// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

class AcDbSectionSettings;
class AcDbSectionGeometryMap;

/** _ */
class BRX_EXPORT AcDbSection: public AcDbEntity
{
public:
    enum Height
    {
        kHeightAboveSectionLine = 1,
        kHeightBelowSectionLine
    };

    enum State
    {
        kPlane = 1,
        kBoundary = 2,
        kVolume = 4
    };

    enum SubItem
    {
        kNone = 0,
        kSectionLine = 1,
        kSectionLineTop = 2,
        kSectionLineBottom = 4,
        kBackLine = 8,
        kBackLineTop = 16,
        kBackLineBottom = 32,
        kVerticalLineTop = 64,
        kVerticalLineBottom = 128
    };

    ACDB_DECLARE_MEMBERS(AcDbSection);

    AcDbSection();
    AcDbSection(const AcGePoint3dArray&,const AcGeVector3d&);
    AcDbSection(const AcGePoint3dArray&,const AcGeVector3d&,const AcGeVector3d&);
    ~AcDbSection();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus subClose();

    Acad::ErrorStatus addVertex(int,const AcGePoint3d&);
    Acad::ErrorStatus createJog(const AcGePoint3d&);
    Acad::ErrorStatus enableLiveSection(bool);
    Acad::ErrorStatus generateSectionGeometry(AcDbEntity*, AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&) const;
    Acad::ErrorStatus generateSectionGeometry(const AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&) const;
    Acad::ErrorStatus generateSectionGeometry(const AcDbVoidPtrArray&, const AcDbIntArray&, const AcArray<AcGeMatrix3d>&, const AcArray<AcRxClass*>&,
                                              AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&, AcArray<AcDbEntity*>&,
                                              AcDbSectionGeometryMap* = NULL) const;
    Acad::ErrorStatus getName(ACHAR*&) const;
    Acad::ErrorStatus getName(AcString&) const;
    Acad::ErrorStatus getSettings(AcDbSectionSettings*&,AcDb::OpenMode) const;
    Acad::ErrorStatus getVertex(int,AcGePoint3d&) const;
    Acad::ErrorStatus getVertices(AcGePoint3dArray&) const;
    Acad::ErrorStatus plane(AcGeVector3d&,AcGeVector3d&) const;
    Acad::ErrorStatus removeVertex(int);
    Acad::ErrorStatus setHeight(Height,double);
    Acad::ErrorStatus setIndicatorFillColor(const AcCmColor&);
    Acad::ErrorStatus setIndicatorTransparency(int);
    Acad::ErrorStatus setName(const ACHAR*);
    Acad::ErrorStatus setState(State);
    Acad::ErrorStatus setVertex(int,const AcGePoint3d&);
    Acad::ErrorStatus setVerticalDirection(const AcGeVector3d&);
    Acad::ErrorStatus setVertices(const AcGePoint3dArray&);
    Acad::ErrorStatus setViewingDirection(const AcGeVector3d&);
    AcCmColor indicatorFillColor() const;
    AcDbObjectId getSettings() const;
    AcGeVector3d normal() const;
    AcGeVector3d verticalDirection() const;
    AcGeVector3d viewingDirection() const;
    bool isLiveSectionEnabled() const;
    const ACHAR* getName() const;
    double height(Height) const;
    int indicatorTransparency() const;
    int numVertices() const;
    State state() const;

    bool   hasJogs() const;
    double elevation() const;
    double topPlane() const;
    double bottomPlane() const;
    bool   isSlice() const;
    double thicknessDepth() const;
    double sectionPlaneOffset() const;

    Acad::ErrorStatus setElevation(double);
    Acad::ErrorStatus setTopPlane(double);
    Acad::ErrorStatus setBottomPlane(double);
    Acad::ErrorStatus setIsSlice(bool);
    Acad::ErrorStatus setThicknessDepth(double);
    Acad::ErrorStatus setSectionPlaneOffset(double);

    // 'hitTest' is not implemented yet
    bool hitTest(const AcGePoint3d&,int*,AcGePoint3d*,SubItem*) const;

protected:
    virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents&) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode,Adesk::GsMarker,const AcGePoint3d&,const AcGePoint3d&,const AcGeMatrix3d&,AcGePoint3dArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray&,const AcGeVector3d&,const int);
    virtual void subList() const;
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
};
