// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiNonEntityTraits.h"

/** _ */
class AcGiRenderEnvironmentTraits: public AcGiNonEntityTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiRenderEnvironmentTraits);

    virtual AcCmEntityColor fogColor() const = 0;
    virtual AcGiMaterialTexture* environmentMap() const = 0;
    virtual bool enable() const = 0;
    virtual bool isBackground() const = 0;
    virtual double farDistance() const = 0;
    virtual double farPercentage() const = 0;
    virtual double nearDistance() const = 0;
    virtual double nearPercentage() const = 0;
    virtual void setEnable(const bool) = 0;
    virtual void setEnvironmentMap(const AcGiMaterialTexture*) = 0;
    virtual void setFarDistance(const double) = 0;
    virtual void setFarPercentage(const double) = 0;
    virtual void setFogColor(const AcCmEntityColor&) = 0;
    virtual void setIsBackground(const bool) = 0;
    virtual void setNearDistance(const double) = 0;
    virtual void setNearPercentage(const double) = 0;
};
