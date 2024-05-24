// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"

class AcCmEntityColor;

/** _ */
class BRX_EXPORT AcDbRenderEnvironment: public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbRenderEnvironment);

    AcDbRenderEnvironment();
    virtual ~AcDbRenderEnvironment();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual AcGiDrawable* drawable();
    virtual bool operator==(const AcDbRenderEnvironment&);

    Acad::ErrorStatus setDistances(double,double);
    Acad::ErrorStatus setEnvironmentImageFileName(const AcString&);
    Acad::ErrorStatus setFogDensity(double,double);
    AcCmEntityColor fogColor() const;
    AcString environmentImageFileName() const;
    bool environmentImageEnabled() const;
    bool fogBackgroundEnabled() const;
    bool fogEnabled() const;
    void distances(double&,double&) const;
    void fogDensity(double&,double&) const;
    void setEnvironmentImageEnabled(bool);
    void setFogBackgroundEnabled(bool);
    void setFogColor(const AcCmEntityColor&);
    void setFogEnabled(bool);

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
