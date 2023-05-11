// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"
#include "AcGi/AcGiLightAttenuation.h"
#include "AcGi/AcGiShadowParameters.h"
#include "AcCm/AcCmColor.h"


/** _ */
class BRX_EXPORT AcDbLight: public AcDbEntity
{
public:

    enum GlyphDisplayType
    {
        kGlyphDisplayAuto = 0,
        kGlyphDisplayOn   = 1,
        kGlyphDisplayOff  = 2,
    };

    enum LampColorPreset
    {
        kD65White            =  0,
        kFluorescent         =  1,
        kCoolWhite           =  2,
        kWhiteFluorescent    =  3,
        kDaylightFluorescent =  4,
        kIncandescent        =  5,
        kXenon               =  6,
        kHalogen             =  7,
        kQuartz              =  8,
        kMetalHalide         =  9,
        kMercury             = 10,
        kPhosphorMercury     = 11,
        kHighPressureSodium  = 12,
        kLowPressureSodium   = 13,
        kCustom              = 14,
    };

    enum LampColorType
    {
        kKelvin = 0,
        kPreset = 1,
    };

    enum PhysicalIntensityMethod
    {
        kPeakIntensity = 0,
        kFlux          = 1,
        kIlluminance   = 2,
    };

    ACRX_DECLARE_MEMBERS(AcDbLight);

    AcDbLight();
    virtual ~AcDbLight();

    virtual Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion,AcDbObject*&,AcDbObjectId&,Adesk::Boolean&);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus setHotspotAndFalloff(double,double);
    virtual Acad::ErrorStatus setIntensity(double);
    virtual Acad::ErrorStatus setIsPlottable(bool);
    virtual Acad::ErrorStatus setLightColor(const AcCmColor&);
    virtual Acad::ErrorStatus setLightDirection(const AcGeVector3d&);
    virtual Acad::ErrorStatus setLightType(DrawableType);
    virtual Acad::ErrorStatus setName(const AcString&);
    virtual Acad::ErrorStatus setOn(bool);
    virtual Acad::ErrorStatus setPosition(const AcGePoint3d&);
    virtual Acad::ErrorStatus setTargetLocation(const AcGePoint3d&);
    virtual Acad::ErrorStatus subClose();
    virtual bool castShadows() const;
    virtual bool isOn() const;
    virtual bool isPlottable() const;
    virtual bool receiveShadows() const;
    virtual const AcCmColor& lightColor() const;
    virtual const AcGePoint3d& position() const;
    virtual const AcGePoint3d& targetLocation() const;
    virtual const AcGeVector3d& lightDirection() const;
    virtual const AcGiLightAttenuation& lightAttenuation() const;
    virtual const AcGiShadowParameters& shadowParameters() const;
    virtual const AcString& name() const;
    virtual double falloffAngle() const;
    virtual double hotspotAngle() const;
    virtual double intensity() const;
    virtual DrawableType drawableType() const;
    virtual DrawableType lightType() const;
    virtual void subList() const;
    virtual void setCastShadows(bool);
    virtual void setLightAttenuation(const AcGiLightAttenuation&);
    virtual void setReceiveShadows(bool);
    virtual void setShadowParameters(const AcGiShadowParameters&);

    virtual GlyphDisplayType  glyphDisplay() const;
    virtual Acad::ErrorStatus setGlyphDisplay(GlyphDisplayType type);

    virtual LampColorType     lampColorType() const;
    virtual Acad::ErrorStatus setLampColorType(LampColorType colorType);

    virtual double            lampColorTemp() const;
    virtual Acad::ErrorStatus setLampColorTemp(double colorTemp);

    virtual double            illuminanceDistance() const;
    virtual Acad::ErrorStatus setIlluminanceDistance(double distance);

    virtual PhysicalIntensityMethod physicalIntensityMethod() const;
    virtual Acad::ErrorStatus       setPhysicalIntensityMethod(PhysicalIntensityMethod method);

    virtual double            physicalIntensity() const;
    virtual Acad::ErrorStatus setPhysicalIntensity(double physicalIntensity);

    //virtual Acad::ErrorStatus lampColorRGB(AcGiColorRGB& rgbColor) const;
    //virtual Acad::ErrorStatus setLampColorRGB(AcGiColorRGB rgbColor);
    virtual Acad::ErrorStatus resultingColor(AcCmColor& rgbColor) const;

    virtual LampColorPreset   lampColorPreset() const;
    virtual Acad::ErrorStatus setLampColorPreset(LampColorPreset colorPreset);

    virtual Acad::ErrorStatus webFile(AcString& webFile) const;
    virtual Acad::ErrorStatus setWebFile(const ACHAR* webFile);

    virtual Acad::ErrorStatus webRotation(AcGeVector3d& rotation) const;
    virtual Acad::ErrorStatus setWebRotation(const AcGeVector3d& rotation);

    virtual bool              hasTarget() const;
    virtual Acad::ErrorStatus setHasTarget(bool hasTarget);

protected:
    virtual Acad::ErrorStatus subDeepClone(AcDbObject*,AcDbObject*&,AcDbIdMapping&,Adesk::Boolean = Adesk::kTrue) const;
    virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents&) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&, AcDbEntity*&) const;
    virtual Acad::ErrorStatus subHighlight(const AcDbFullSubentPath&,const Adesk::Boolean) const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray&,const AcGeVector3d&,const int);
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
    virtual Acad::ErrorStatus subUnhighlight(const AcDbFullSubentPath&,const Adesk::Boolean) const;
    virtual Acad::ErrorStatus subWblockClone(AcRxObject*,AcDbObject*&,AcDbIdMapping&,Adesk::Boolean) const;
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
    virtual void subViewportDraw(AcGiViewportDraw*);
};
