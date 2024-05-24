// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiNonEntityTraits.h"

/** _ */
class AcGiImageBackgroundTraits: public AcGiNonEntityTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiImageBackgroundTraits);

    virtual bool fitToScreen() const = 0;
    virtual bool maintainAspectRatio() const = 0;
    virtual bool useTiling() const = 0;
    virtual const ACHAR* imageFilename() const = 0;
    virtual double xOffset() const = 0;
    virtual double xScale() const = 0;
    virtual double yOffset() const = 0;
    virtual double yScale() const = 0;
    virtual void setFitToScreen(bool) = 0;
    virtual void setImageFilename(const ACHAR*) = 0;
    virtual void setMaintainAspectRatio(bool) = 0;
    virtual void setUseTiling(bool) = 0;
    virtual void setXOffset(double) = 0;
    virtual void setXScale(double) = 0;
    virtual void setYOffset(double) = 0;
    virtual void setYScale(double) = 0;
};
