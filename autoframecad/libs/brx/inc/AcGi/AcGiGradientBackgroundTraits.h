// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiNonEntityTraits.h"

/** _ */
class AcGiGradientBackgroundTraits: public AcGiNonEntityTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiGradientBackgroundTraits);

    virtual AcCmEntityColor colorBottom() const = 0;
    virtual AcCmEntityColor colorMiddle() const = 0;
    virtual AcCmEntityColor colorTop() const = 0;
    virtual double height() const = 0;
    virtual double horizon() const = 0;
    virtual double rotation() const = 0;
    virtual void setColorBottom(const AcCmEntityColor&) = 0;
    virtual void setColorMiddle(const AcCmEntityColor&) = 0;
    virtual void setColorTop(const AcCmEntityColor&) = 0;
    virtual void setHeight(double) = 0;
    virtual void setHorizon(double) = 0;
    virtual void setRotation(double) = 0;
};
