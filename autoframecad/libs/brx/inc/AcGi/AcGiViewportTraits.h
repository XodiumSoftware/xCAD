// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiDrawableTraits.h"

/** _ */
class AcGiViewportTraits: public AcGiDrawableTraits
{
public:
    enum DefaultLightingType
    {
        kOneDistantLight = 0,
        kTwoDistantLights
    };

    ACRX_DECLARE_MEMBERS(AcGiViewportTraits);

    virtual AcCmColor ambientLightColor() const = 0;
    virtual AcDbObjectId background() const = 0;
    virtual AcDbObjectId renderEnvironment() const = 0;
    virtual AcDbObjectId renderSettings() const = 0;
    virtual bool isDefaultLightingOn() const = 0;
    virtual DefaultLightingType defaultLightingType() const = 0;
    virtual double brightness() const = 0;
    virtual double contrast() const = 0;
    virtual void setAmbientLightColor(const AcCmColor&) = 0;
    virtual void setBackground(const AcDbObjectId) = 0;
    virtual void setBrightness(double) = 0;
    virtual void setContrast(double) = 0;
    virtual void setDefaultLightingOn(bool) = 0;
    virtual void setDefaultLightingType(DefaultLightingType) = 0;
    virtual void setRenderEnvironment(const AcDbObjectId) = 0;
    virtual void setRenderSettings(const AcDbObjectId) = 0;
};