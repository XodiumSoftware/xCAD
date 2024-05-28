// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"
#include "AcGi/AcGiMaterialTraits.h"

/** _ */
class BRX_EXPORT AcDbMaterial: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbMaterial);

    AcDbMaterial();
    virtual ~AcDbMaterial();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus setChannelFlags(AcGiMaterialTraits::ChannelFlags);
    virtual Acad::ErrorStatus setDescription(const ACHAR*);
    virtual Acad::ErrorStatus setIlluminationModel(AcGiMaterialTraits::IlluminationModel);
    virtual Acad::ErrorStatus setMode(AcGiMaterialTraits::Mode);
    virtual Acad::ErrorStatus setName(const ACHAR*);
    virtual Acad::ErrorStatus setReflectivity(double);
    virtual Acad::ErrorStatus setSelfIllumination(double);
    virtual Acad::ErrorStatus setTranslucence(double);
    virtual AcGiDrawable* drawable();
    virtual AcGiMaterialTraits::ChannelFlags channelFlags() const;
    virtual AcGiMaterialTraits::IlluminationModel illuminationModel() const;
    virtual AcGiMaterialTraits::Mode mode() const;
    virtual const ACHAR* description() const;
    virtual const ACHAR* name() const;
    virtual double reflectivity() const;
    virtual double selfIllumination() const;
    virtual double translucence() const;
    virtual void ambient(AcGiMaterialColor&) const;
    virtual void bump(AcGiMaterialMap&) const;
    virtual void diffuse(AcGiMaterialColor&,AcGiMaterialMap&) const;
    virtual void opacity(double&,AcGiMaterialMap&) const;
    virtual void reflection(AcGiMaterialMap&) const;
    virtual void refraction(double&,AcGiMaterialMap&) const;
    virtual void setAmbient(const AcGiMaterialColor&);
    virtual void setBump(const AcGiMaterialMap&);
    virtual void setDiffuse(const AcGiMaterialColor&,const AcGiMaterialMap&);
    virtual void setOpacity(double,const AcGiMaterialMap&);
    virtual void setReflection(const AcGiMaterialMap&);
    virtual void setRefraction (double,const AcGiMaterialMap&);
    virtual void setSpecular(const AcGiMaterialColor&,const AcGiMaterialMap&,double);
    virtual void specular(AcGiMaterialColor&,AcGiMaterialMap&,double&) const;

    // V20
    virtual double shininess () const;
    virtual Acad::ErrorStatus setShininess(double);

    double luminance() const;
    double colorBleedScale() const;
    double indirectBumpScale() const;
    double reflectanceScale() const;
    double transmittanceScale() const;
    Adesk::Boolean twoSided() const;
    Adesk::Boolean isAnonymous() const;

    Acad::ErrorStatus setLuminance(double);
    Acad::ErrorStatus setColorBleedScale(double);
    Acad::ErrorStatus setIndirectBumpScale(double);
    Acad::ErrorStatus setReflectanceScale(double);
    Acad::ErrorStatus setTransmittanceScale(double);
    Acad::ErrorStatus setTwoSided(Adesk::Boolean);
    Acad::ErrorStatus setAnonymous(Adesk::Boolean);


protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
