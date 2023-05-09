// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiRenderSettingsTraits.h"

/** _ */
class AcGiMentalRayRenderSettingsTraits: public AcGiRenderSettingsTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiMentalRayRenderSettingsTraits);

    virtual AcGiMrDiagnosticBSPMode diagnosticBSPMode() const = 0;
    virtual AcGiMrDiagnosticMode diagnosticMode() const = 0;
    virtual AcGiMrDiagnosticPhotonMode diagnosticPhotonMode() const = 0;
    virtual AcGiMrShadowMode shadowMode() const = 0;
    virtual AcGiMrTileOrder tileOrder() const = 0;
    virtual bool exportMIEnabled() const = 0;
    virtual bool finalGatheringEnabled() const = 0;
    virtual bool giSampleRadiusEnabled() const = 0;
    virtual bool globalIlluminationEnabled() const = 0;
    virtual bool rayTraceEnabled() const = 0;
    virtual bool shadowMapEnabled() const = 0;
    virtual const ACHAR* exportMIFileName() const = 0;
    virtual const void* progressMonitor() const = 0;
    virtual double giSampleRadius() const = 0;
    virtual double lightLuminanceScale() const = 0;
    virtual float energyMultiplier() const = 0;
    virtual int fgRayCount() const = 0;
    virtual int giPhotonsPerLight() const = 0;
    virtual int giSampleCount() const = 0;
    virtual int memoryLimit() const = 0;
    virtual int tileSize() const = 0;
    virtual void SamplingFilter(AcGiMrFilter&,double&,double&) const = 0;
    virtual void diagnosticGridMode(AcGiMrDiagnosticGridMode&,float&) const = 0;
    virtual void fgSampleRadius(double&,double&) const = 0;
    virtual void fgSampleRadiusState(bool&,bool&,bool&) = 0;
    virtual void photonTraceDepth(int&,int&,int&) const = 0;
    virtual void rayTraceDepth(int&,int&,int&) const = 0;
    virtual void sampling(int&,int&) const = 0;
    virtual void samplingContrastColor(float&,float&,float&,float&) const = 0;
    virtual void setDiagnosticBSPMode(AcGiMrDiagnosticBSPMode) = 0;
    virtual void setDiagnosticGridMode(AcGiMrDiagnosticGridMode,float) = 0;
    virtual void setDiagnosticMode(AcGiMrDiagnosticMode) = 0;
    virtual void setDiagnosticPhotonMode(AcGiMrDiagnosticPhotonMode) = 0;
    virtual void setEnergyMultiplier(float) = 0;
    virtual void setExportMIEnabled(bool) = 0;
    virtual void setExportMIFileName(const ACHAR*) = 0;
    virtual void setFGRadiusState(bool,bool,bool) = 0;
    virtual void setFGRayCount(int) = 0;
    virtual void setFGSampleRadius(double,double) = 0;
    virtual void setFinalGatheringEnabled(bool) = 0;
    virtual void setGIPhotonsPerLight(int) = 0;
    virtual void setGISampleCount(int) = 0;
    virtual void setGISampleRadius(double) = 0;
    virtual void setGISampleRadiusEnabled(bool) = 0;
    virtual void setGlobalIlluminationEnabled(bool) = 0;
    virtual void setLightLuminanceScale(double) = 0;
    virtual void setMemoryLimit(int) = 0;
    virtual void setPhotonTraceDepth(int,int,int) = 0;
    virtual void setProgressMonitor(void*) = 0;
    virtual void setRayTraceDepth(int,int,int) = 0;
    virtual void setRayTraceEnabled(bool) = 0;
    virtual void setSampling(int,int) = 0;
    virtual void setSamplingContrastColor(float,float,float,float) = 0;
    virtual void setSamplingFilter(AcGiMrFilter,double,double) = 0;
    virtual void setShadowMapEnabled(bool) = 0;
    virtual void setShadowMode(AcGiMrShadowMode) = 0;
    virtual void setTileOrder(AcGiMrTileOrder) = 0;
    virtual void setTileSize(int) = 0;
};
