// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiGlobal.h"
#include "AcGi/AcGiProceduralTexture.h"

/** _ */
class AcGiMarbleTexture: public AcGiProceduralTexture
{
public:
    ACRX_DECLARE_MEMBERS(AcGiMarbleTexture);

    AcGiMarbleTexture();
    AcGiMarbleTexture(const AcGiMarbleTexture&);
    virtual ~AcGiMarbleTexture();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual bool operator==(const AcGiMaterialTexture&) const;
    virtual const AcGiMaterialColor& stoneColor() const;
    virtual const AcGiMaterialColor& veinColor() const;
    virtual double veinSpacing() const;
    virtual double veinWidth() const;
    virtual void setStoneColor(const AcGiMaterialColor&);
    virtual void setVeinColor(const AcGiMaterialColor&);
    virtual void setVeinSpacing(double);
    virtual void setVeinWidth(double);

    AcGiMarbleTexture& operator=(const AcGiMarbleTexture&);
};
