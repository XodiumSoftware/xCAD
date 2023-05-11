// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSymbolTableRecord.h"
#include "AcGi/AcGiViewportTraits.h"

/** _ */
class BRX_EXPORT AcDbAbstractViewTableRecord: public AcDbSymbolTableRecord
{
public:

    enum RenderMode
    {
        k2DOptimized = 0,
        kWireframe,
        kHiddenLine,
        kFlatShaded,
        kGouraudShaded,
        kFlatShadedWithWireframe,
        kGouraudShadedWithWireframe
    };

    ACDB_DECLARE_MEMBERS(AcDbAbstractViewTableRecord);

    AcDbAbstractViewTableRecord();
    virtual ~AcDbAbstractViewTableRecord();

    AcCmColor ambientLightColor() const;
    AcDbObjectId sunId() const;
    AcDbObjectId ucsName() const;
    AcDbObjectId visualStyle() const;
    AcDbObjectId& background();
    AcGePoint2d centerPoint() const;
    AcGePoint3d target() const;
    AcGeVector3d viewDirection() const;
    AcGiViewportTraits::DefaultLightingType defaultLightingType() const;
    Acad::ErrorStatus getUcs(AcGePoint3d&,AcGeVector3d&,AcGeVector3d&) const;
    Acad::ErrorStatus setAmbientLightColor(const AcCmColor&);
    Acad::ErrorStatus setBackground(const AcDbObjectId&);
    Acad::ErrorStatus setBrightness(double);
    Acad::ErrorStatus setContrast(double);
    Acad::ErrorStatus setDefaultLightingOn(bool);
    Acad::ErrorStatus setDefaultLightingType(AcGiViewportTraits::DefaultLightingType);
    Acad::ErrorStatus setElevation(double);
    Acad::ErrorStatus setSun(AcDbObjectId&,AcDbObject*);
    Acad::ErrorStatus setUcs(AcDb::OrthographicView);
    Acad::ErrorStatus setUcs(const AcDbObjectId&);
    Acad::ErrorStatus setUcs(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&);
    Acad::ErrorStatus setUcsToWorld();
    Acad::ErrorStatus setViewDirection(AcDb::OrthographicView);
    Acad::ErrorStatus setVisualStyle(const AcDbObjectId&);
    RenderMode renderMode() const;
    bool backClipEnabled() const;
    bool frontClipAtEye() const;
    bool frontClipEnabled() const;
    bool isDefaultLightingOn() const;
    bool isUcsOrthographic(AcDb::OrthographicView&) const;
    bool isViewOrthographic(AcDb::OrthographicView&) const;
    bool perspectiveEnabled() const;
    const AcDbObjectId& background() const;
    double backClipDistance() const;
    double brightness() const;
    double contrast() const;
    double elevation() const;
    double frontClipDistance() const;
    double height() const;
    double lensLength() const;
    double viewTwist() const;
    double width() const;
    void setBackClipDistance(double);
    void setBackClipEnabled(bool);
    void setCenterPoint(const AcGePoint2d&);
    void setFrontClipAtEye(bool);
    void setFrontClipDistance(double);
    void setFrontClipEnabled(bool);
    void setHeight(double);
    void setLensLength(double);
    void setPerspectiveEnabled(bool);
    void setRenderMode(RenderMode);
    void setTarget(const AcGePoint3d&);
    void setViewDirection(const AcGeVector3d&);
    void setViewTwist(double);
    void setWidth(double);
};
