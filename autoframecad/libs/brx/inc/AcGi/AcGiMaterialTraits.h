// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiNonEntityTraits.h"

/** _ */
class AcGiMaterialTraits: public AcGiNonEntityTraits
{
public:
    enum ChannelFlags
    {
        kNone          = 0,
        kUseDiffuse    = 1,
        kUseSpecular   = 2,
        kUseReflection = 4,
        kUseOpacity    = 8,
        kUseBump       = 16,
        kUseRefraction = 32,
        kUseNormalMap  = 64,
        //
        kUseAll = kUseDiffuse | kUseSpecular   | kUseReflection | kUseOpacity |
                  kUseBump    | kUseRefraction | kUseNormalMap
    };

    enum IlluminationModel
    {
        kBlinnShader = 0,
        kMetalShader
    };

    enum Mode
    {
        kRealistic = 0,
        kAdvanced
    };

    ACRX_DECLARE_MEMBERS(AcGiMaterialTraits);

    virtual ChannelFlags channelFlags() const = 0;
    virtual double reflectivity() const = 0;
    virtual double selfIllumination() const = 0;
    virtual double translucence() const = 0;
    virtual IlluminationModel illuminationModel() const = 0;
    virtual Mode mode() const = 0;
    virtual void ambient(AcGiMaterialColor&) const = 0;
    virtual void bump(AcGiMaterialMap&) const = 0;
    virtual void diffuse(AcGiMaterialColor&,AcGiMaterialMap&) const = 0;
    virtual void opacity(double&,AcGiMaterialMap&) const = 0;
    virtual void reflection(AcGiMaterialMap&) const = 0;
    virtual void refraction(double&,AcGiMaterialMap&) const = 0;
    virtual void setAmbient(const AcGiMaterialColor&) = 0;
    virtual void setBump(const AcGiMaterialMap&) = 0;
    virtual void setChannelFlags(ChannelFlags) = 0;
    virtual void setDiffuse(const AcGiMaterialColor&,const AcGiMaterialMap&) = 0;
    virtual void setIlluminationModel(IlluminationModel) = 0;
    virtual void setMode(Mode) = 0;
    virtual void setOpacity(double,const AcGiMaterialMap&) = 0;
    virtual void setReflection(const AcGiMaterialMap&) = 0;
    virtual void setReflectivity(double) = 0;
    virtual void setRefraction(double,const AcGiMaterialMap&) = 0;
    virtual void setSelfIllumination(double) = 0;
    virtual void setSpecular(const AcGiMaterialColor&,const AcGiMaterialMap&,double) = 0;
    virtual void setTranslucence(double) = 0;
    virtual void specular(AcGiMaterialColor&,AcGiMaterialMap&,double&) const = 0;
};