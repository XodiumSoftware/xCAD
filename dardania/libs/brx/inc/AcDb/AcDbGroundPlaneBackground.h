// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcCm/AcCmEntityColor.h"
#include "AcDb/AcDbBackground.h"

/** _ */
class BRX_EXPORT AcDbGroundPlaneBackground: public AcDbBackground
{
public:
    ACRX_DECLARE_MEMBERS(AcDbGroundPlaneBackground);

    AcDbGroundPlaneBackground();
    virtual ~AcDbGroundPlaneBackground();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual DrawableType drawableType() const;

    AcCmEntityColor colorGroundPlaneFar() const;
    AcCmEntityColor colorGroundPlaneNear() const;
    AcCmEntityColor colorSkyHorizon() const;
    AcCmEntityColor colorSkyZenith() const;
    AcCmEntityColor colorUndergroundAzimuth() const;
    AcCmEntityColor colorUndergroundHorizon() const;
    void setColorGroundPlaneFar (const AcCmEntityColor&);
    void setColorGroundPlaneNear(const AcCmEntityColor&);
    void setColorSkyHorizon(const AcCmEntityColor&);
    void setColorSkyZenith(const AcCmEntityColor&);
    void setColorUndergroundAzimuth(const AcCmEntityColor&);
    void setColorUndergroundHorizon(const AcCmEntityColor&);

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
