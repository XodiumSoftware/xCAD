// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbAbstractViewTableRecord.h"
#include "AcDb/AcDbEntity.h"

class AcDbAnnotationScale;

/** _ */
class BRX_EXPORT AcDbViewport: public AcDbEntity
{
public:
    enum ShadePlotType
    {
        kAsDisplayed = 0,
        kWireframe,
        kHidden,
        kRendered,
        kVisualStyle,
        kRenderPreset
    };

    enum StandardScaleType
    {
        kScaleToFit = 0,
        kCustomScale,
        k1_1,
        k1_2,
        k1_4,
        k1_8,
        k1_10,
        k1_16,
        k1_20,
        k1_30,
        k1_40,
        k1_50,
        k1_100,
        k2_1,
        k4_1,
        k8_1,
        k10_1,
        k100_1,
        k1_128in_1ft,
        k1_64in_1ft,
        k1_32in_1ft,
        k1_16in_1ft,
        k3_32in_1ft,
        k1_8in_1ft,
        k3_16in_1ft,
        k1_4in_1ft,
        k3_8in_1ft,
        k1_2in_1ft,
        k3_4in_1ft,
        k1in_1ft,
        k1and1_2in_1ft,
        k3in_1ft,
        k6in_1ft,
        k1ft_1ft
    };

    ACDB_DECLARE_MEMBERS(AcDbViewport);

    AcDbViewport();
    ~AcDbViewport();

    virtual void copied(const AcDbObject*,const AcDbObject*);
    virtual void erased(const AcDbObject*,Adesk::Boolean);
    virtual void modified(const AcDbObject*);
    virtual void subObjModified(const AcDbObject*,const AcDbObject*);

    Acad::ErrorStatus effectivePlotStyleSheet(const ACHAR*&);
    Acad::ErrorStatus freezeLayersInViewport(const AcDbObjectIdArray&);
    Acad::ErrorStatus getFrozenLayerList(AcDbObjectIdArray&) const;
    Acad::ErrorStatus getLabelBlock(AcDbObjectId&) const;
    Acad::ErrorStatus getModelView(AcDbXrefObjectId&) const;
    Acad::ErrorStatus getSheetView(AcDbObjectId&) const;
    Acad::ErrorStatus getThumbnail(BITMAPINFO*&) const;
    Acad::ErrorStatus getUcs(AcGePoint3d&,AcGeVector3d&,AcGeVector3d&) const;
    Acad::ErrorStatus plotStyleSheet(ACHAR*&) const;
    Acad::ErrorStatus plotStyleSheet(const ACHAR*&) const;
    Acad::ErrorStatus removeHiddenLines();
    Acad::ErrorStatus removeLabelBlock();
    Acad::ErrorStatus removeModelView();
    Acad::ErrorStatus removeSheetView();
    Acad::ErrorStatus setAmbientLightColor(const AcCmColor&);
    Acad::ErrorStatus setAnnotationScale(const AcDbAnnotationScale*);
    Acad::ErrorStatus setBackClipDistance(double);
    Acad::ErrorStatus setBackClipOff();
    Acad::ErrorStatus setBackClipOn();
    Acad::ErrorStatus setBackground(AcDbObjectId);
    Acad::ErrorStatus setBrightness(double);
    Acad::ErrorStatus setCenterPoint(const AcGePoint3d&);
    Acad::ErrorStatus setCircleSides(Adesk::UInt16);
    Acad::ErrorStatus setContrast(double);
    Acad::ErrorStatus setCustomScale(double);
    Acad::ErrorStatus setDefaultLightingOn(bool);
    Acad::ErrorStatus setDefaultLightingType(AcGiViewportTraits::DefaultLightingType);
    Acad::ErrorStatus setElevation(double);
    Acad::ErrorStatus setFastZoomOff();
    Acad::ErrorStatus setFastZoomOn();
    Acad::ErrorStatus setFrontClipAtEyeOff();
    Acad::ErrorStatus setFrontClipAtEyeOn();
    Acad::ErrorStatus setFrontClipDistance(double);
    Acad::ErrorStatus setFrontClipOff();
    Acad::ErrorStatus setFrontClipOn();
    Acad::ErrorStatus setGridAdaptive(bool);
    Acad::ErrorStatus setGridBoundToLimits(bool);
    Acad::ErrorStatus setGridFollow(bool);
    Acad::ErrorStatus setGridIncrement(const AcGeVector2d&);
    Acad::ErrorStatus setGridMajor(Adesk::UInt16);
    Acad::ErrorStatus setGridOff();
    Acad::ErrorStatus setGridOn();
    Acad::ErrorStatus setGridSubdivisionRestricted(bool);
    Acad::ErrorStatus setHeight(double);
    Acad::ErrorStatus setLabelBlock(AcDbObjectId);
    Acad::ErrorStatus setLensLength(double);
    Acad::ErrorStatus setLocked();
    Acad::ErrorStatus setModelView(const AcDbXrefObjectId&);
    Acad::ErrorStatus setNonRectClipEntityId(AcDbObjectId);
    Acad::ErrorStatus setNonRectClipOff();
    Acad::ErrorStatus setNonRectClipOn();
    Acad::ErrorStatus setOff();
    Acad::ErrorStatus setOn();
    Acad::ErrorStatus setOpaque();
    Acad::ErrorStatus setPerspectiveOff();
    Acad::ErrorStatus setPerspectiveOn();
    Acad::ErrorStatus setPlotStyleSheet(const ACHAR*);
    Acad::ErrorStatus setShadePlot(const ShadePlotType);
    Acad::ErrorStatus setShadePlot(const ShadePlotType,const AcDbObjectId);
    Acad::ErrorStatus setSheetView(AcDbObjectId);
    Acad::ErrorStatus setSnapAngle(double);
    Acad::ErrorStatus setSnapBasePoint(const AcGePoint2d&);
    Acad::ErrorStatus setSnapIncrement(const AcGeVector2d&);
    Acad::ErrorStatus setSnapIsometric();
    Acad::ErrorStatus setSnapIsoPair(Adesk::UInt16);
    Acad::ErrorStatus setSnapOff();
    Acad::ErrorStatus setSnapOn();
    Acad::ErrorStatus setSnapStandard();
    Acad::ErrorStatus setStandardScale(const StandardScaleType);
    Acad::ErrorStatus setSun(AcDbObjectId&,AcDbObject*);
    Acad::ErrorStatus setThumbnail(const BITMAPINFO*);
    Acad::ErrorStatus setTransparent();
    Acad::ErrorStatus setTwistAngle(double);
    Acad::ErrorStatus setUcs(AcDb::OrthographicView);
    Acad::ErrorStatus setUcs(const AcDbObjectId&);
    Acad::ErrorStatus setUcs(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&);
    Acad::ErrorStatus setUcsFollowModeOff();
    Acad::ErrorStatus setUcsFollowModeOn();
    Acad::ErrorStatus setUcsIconAtCorner();
    Acad::ErrorStatus setUcsIconAtOrigin();
    Acad::ErrorStatus setUcsIconInvisible();
    Acad::ErrorStatus setUcsIconVisible();
    Acad::ErrorStatus setUcsToWorld();
    Acad::ErrorStatus setUnlocked();
    Acad::ErrorStatus setViewCenter(const AcGePoint2d&);
    Acad::ErrorStatus setViewDirection(AcDb::OrthographicView);
    Acad::ErrorStatus setViewDirection(const AcGeVector3d&);
    Acad::ErrorStatus setViewHeight(double);
    Acad::ErrorStatus setViewTarget(const AcGePoint3d&);
    Acad::ErrorStatus setVisualStyle(const AcDbObjectId);
    Acad::ErrorStatus setWidth(double);
    Acad::ErrorStatus showHiddenLines();
    Acad::ErrorStatus syncModelView();
    Acad::ErrorStatus thawAllLayersInViewport();
    Acad::ErrorStatus thawLayersInViewport(const AcDbObjectIdArray&);
    Acad::ErrorStatus updateDisplay() const;
    AcCmColor ambientLightColor() const;
    AcDbAnnotationScale* annotationScale() const;
    AcDbAbstractViewTableRecord::RenderMode renderMode() const;
    AcDbObjectId background() const;
    AcDbObjectId nonRectClipEntityId() const;
    AcDbObjectId shadePlotId() const;
    AcDbObjectId sunId() const;
    AcDbObjectId ucsName() const;
    AcDbObjectId visualStyle() const;
    AcGePoint2d snapBasePoint() const;
    AcGePoint2d viewCenter() const;
    AcGePoint3d centerPoint() const;
    AcGePoint3d viewTarget() const;
    AcGeVector2d gridIncrement() const;
    AcGeVector2d snapIncrement() const;
    AcGeVector3d viewDirection() const;
    AcGiViewportTraits::DefaultLightingType defaultLightingType() const;
    Adesk::Int16 number() const;
    Adesk::UInt16 circleSides() const;
    Adesk::UInt16 gridMajor() const;
    Adesk::UInt16 snapIsoPair() const;
    bool hiddenLinesRemoved() const;
    bool isBackClipOn() const;
    bool isDefaultLightingOn() const;
    bool isFastZoomOn() const;
    bool isFrontClipAtEyeOn() const;
    bool isFrontClipOn() const;
    bool isGridAdaptive() const;
    bool isGridBoundToLimits() const;
    bool isGridFollow() const;
    bool isGridOn() const;
    bool isGridSubdivisionRestricted() const;
    bool isLayerFrozenInViewport(const AcDbObjectId&) const;
    bool isLocked() const;
    bool isNonRectClipOn() const;
    bool isOn() const;
    bool isPerspectiveOn() const;
    bool isSnapIsometric() const;
    bool isSnapOn() const;
    bool isTransparent() const;
    bool isUcsFollowModeOn() const;
    bool isUcsIconAtOrigin() const;
    bool isUcsIconVisible() const;
    bool isUcsOrthographic(AcDb::OrthographicView&) const;
    bool isUcsSavedWithViewport() const;
    bool isViewOrthographic(AcDb::OrthographicView&) const;
    bool plotAsRaster() const;
    bool plotWireframe() const;
    double backClipDistance() const;
    double brightness() const;
    double contrast() const;
    double customScale() const;
    double elevation() const;
    double frontClipDistance() const;
    double height() const;
    double lensLength() const;
    double snapAngle() const;
    double twistAngle() const;
    double viewHeight() const;
    double width() const;
    ShadePlotType shadePlot() const;
    StandardScaleType standardScale() const;
    void setRenderMode(AcDbAbstractViewTableRecord::RenderMode);
    void setUcsPerViewport(bool);

protected:
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&,AcDbEntity*&) const;
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
