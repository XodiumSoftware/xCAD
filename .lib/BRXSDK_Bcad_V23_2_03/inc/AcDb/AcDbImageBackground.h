// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbBackground.h"

/** _ */
class BRX_EXPORT AcDbImageBackground: public AcDbBackground
{
public:
    ACRX_DECLARE_MEMBERS(AcDbImageBackground);

    AcDbImageBackground();
    virtual ~AcDbImageBackground();

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual DrawableType drawableType() const;

    bool fitToScreen() const;
    bool maintainAspectRatio() const;
    bool useTiling() const;
    const ACHAR* imageFilename() const;
    double xOffset() const;
    double xScale() const;
    double yOffset() const;
    double yScale() const;
    void setFitToScreen(bool);
    void setImageFilename(const ACHAR*);
    void setMaintainAspectRatio(bool);
    void setUseTiling(bool);
    void setXOffset(double);
    void setXScale(double);
    void setYOffset(double);
    void setYScale(double);

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
