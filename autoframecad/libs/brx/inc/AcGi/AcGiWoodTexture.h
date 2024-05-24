// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiGlobal.h"
#include "AcGi/AcGiProceduralTexture.h"

/** _ */
class AcGiWoodTexture: public AcGiProceduralTexture
{
public:
    ACRX_DECLARE_MEMBERS(AcGiWoodTexture);

    AcGiWoodTexture();
    AcGiWoodTexture(const AcGiWoodTexture&);
    virtual ~AcGiWoodTexture();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual bool operator==(const AcGiMaterialTexture&) const;
    virtual const AcGiMaterialColor& color1() const;
    virtual const AcGiMaterialColor& color2() const;
    virtual double axialNoise() const;
    virtual double grainThickness() const;
    virtual double radialNoise() const;
    virtual void setAxialNoise(double);
    virtual void setColor1(const AcGiMaterialColor&);
    virtual void setColor2(const AcGiMaterialColor&);
    virtual void setGrainThickness(double);
    virtual void setRadialNoise(double);

    AcGiWoodTexture& operator=(const AcGiWoodTexture&);
};
