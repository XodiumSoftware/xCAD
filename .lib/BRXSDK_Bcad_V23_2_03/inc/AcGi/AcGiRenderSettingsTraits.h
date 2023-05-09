// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiNonEntityTraits.h"

/** _ */
class AcGiRenderSettingsTraits: public AcGiNonEntityTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiRenderSettingsTraits);

    virtual bool backFacesEnabled() const = 0;
    virtual bool diagnosticBackgroundEnabled() const = 0;
    virtual bool materialEnabled() const = 0;
    virtual bool shadowsEnabled() const = 0;
    virtual bool textureSampling() const = 0;
    virtual double modelScaleFactor() const = 0;
    virtual void setBackFacesEnabled(bool) = 0;
    virtual void setDiagnosticBackgroundEnabled(bool) = 0;
    virtual void setMaterialEnabled(bool) = 0;
    virtual void setModelScaleFactor(double) = 0;
    virtual void setShadowsEnabled(bool) = 0;
    virtual void setTextureSampling(bool) = 0;
};
