// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmEntityColor.h"
#include "AcDb/AcDbBackground.h"

/** _ */
class BRX_EXPORT AcDbSolidBackground: public AcDbBackground
{
public:
    ACRX_DECLARE_MEMBERS(AcDbSolidBackground);

    AcDbSolidBackground();
    virtual ~AcDbSolidBackground();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual DrawableType drawableType() const;

    AcCmEntityColor colorSolid() const;
    void setColorSolid(const AcCmEntityColor&);

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
