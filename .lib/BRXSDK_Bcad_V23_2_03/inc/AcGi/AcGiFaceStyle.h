// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmColor.h"

/** _ */
class BRX_IMPORTEXPORT AcGiFaceStyle: public AcRxObject
{
public:
    enum FaceColorMode
    {
        kNoColorMode = 0,
        kObjectColor,
        kBackgroundColor,
        kMono,
        kTint,
        kDesaturate
    };
    enum FaceModifier
    {
        kNoFaceModifiers = 0,
        kOpacity,
        kSpecular
    };
    enum LightingModel
    {
        kInvisible = 0,
        kConstant,
        kPhong,
        kGooch
    };
    enum LightingQuality
    {
        kNoLighting = 0,
        kPerFaceLighting,
        kPerVertexLighting,
        kPerPixelLighting
    };

    ACRX_DECLARE_MEMBERS(AcGiFaceStyle);

    AcGiFaceStyle();
    AcGiFaceStyle(const AcGiFaceStyle&);
    virtual ~AcGiFaceStyle();

    virtual AcCmColor& monoColor();
    virtual AcGiFaceStyle& operator=(const AcGiFaceStyle&);
    virtual bool isFaceModifierFlagSet(FaceModifier) const;
    virtual bool operator==(const AcGiFaceStyle&) const;
    virtual const AcCmColor& monoColor() const;
    virtual double opacityLevel() const;
    virtual double specularAmount() const;
    virtual FaceColorMode faceColorMode() const;
    virtual LightingModel lightingModel() const;
    virtual LightingQuality lightingQuality() const;
    virtual unsigned long faceModifiers() const;
    virtual void set(const AcGiFaceStyle&);
    virtual void setFaceColorMode(FaceColorMode);
    virtual void setFaceModifierFlag(FaceModifier,bool);
    virtual void setFaceModifiers(unsigned long);
    virtual void setLightingModel(LightingModel);
    virtual void setLightingQuality(LightingQuality);
    virtual void setMonoColor(const AcCmColor&,bool);
    virtual void setOpacityLevel(double,bool);
    virtual void setSpecularAmount(double,bool);
};
