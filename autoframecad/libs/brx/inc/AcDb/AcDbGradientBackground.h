// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcCm/AcCmEntityColor.h"
#include "AcDb/AcDbBackground.h"

/** _ */
class BRX_EXPORT AcDbGradientBackground: public AcDbBackground
{
public:
    ACRX_DECLARE_MEMBERS(AcDbGradientBackground);

    AcDbGradientBackground();
    virtual ~AcDbGradientBackground();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual DrawableType drawableType() const;

    AcCmEntityColor colorBottom() const;
    AcCmEntityColor colorMiddle() const;
    AcCmEntityColor colorTop() const;
    double height() const ;
    double horizon() const;
    double rotation() const;
    void setColorBottom(const AcCmEntityColor&);
    void setColorMiddle(const AcCmEntityColor&);
    void setColorTop(const AcCmEntityColor&);
    void setHeight(double);
    void setHorizon(double);
    void setRotation(double);

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
