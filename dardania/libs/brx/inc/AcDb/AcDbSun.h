// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"
#include "AcGi/AcGiShadowParameters.h"

class AcCmColor;

/** _ */
class BRX_EXPORT AcDbSun: public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbSun);

    AcDbSun();
    ~AcDbSun();

    virtual Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion,AcDbObject*&,AcDbObjectId&,Adesk::Boolean&);
    virtual Acad::ErrorStatus dwgInFields (AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields (AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus setDateTime(const AcDbDate&);
    virtual Acad::ErrorStatus setDayLightSavingsOn(bool);
    virtual Acad::ErrorStatus setIntensity(double);
    virtual Acad::ErrorStatus setOn(bool);
    virtual Acad::ErrorStatus setSunColor(const AcCmColor&);
    virtual AcGiDrawable* drawable();
    virtual bool isDayLightSavingsOn() const;
    virtual bool isOn() const;
    virtual const AcCmColor& sunColor() const;
    virtual const AcDbDate& dateTime() const;
    virtual const AcGeVector3d& sunDirection() const;
    virtual const AcGiShadowParameters& shadowParameters() const;
    virtual double intensity() const;
    virtual DrawableType drawableType() const;
    virtual void setShadowParameters(const AcGiShadowParameters&);

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
