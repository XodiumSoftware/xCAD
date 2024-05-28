// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbRenderSettings.h"

/** _ */
class BRX_EXPORT AcDbMentalRayRenderSettings: public AcDbRenderSettings
{
public:
    ACRX_DECLARE_MEMBERS(AcDbMentalRayRenderSettings);

    AcDbMentalRayRenderSettings();
    virtual ~AcDbMentalRayRenderSettings();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual bool operator==(const AcDbMentalRayRenderSettings&);

    Acad::ErrorStatus copyFrom(const AcRxObject*);
    Acad::ErrorStatus setDiagnosticGridMode(AcGiMrDiagnosticGridMode,float);
    Acad::ErrorStatus setEnergyMultiplier(float);
    Acad::ErrorStatus setExportMIFileName(const AcString&);
    Acad::ErrorStatus setFGRayCount(int);
    Acad::ErrorStatus setFGSampleRadius(double,double);
    Acad::ErrorStatus setGIPhotonsPerLight(int);
    Acad::ErrorStatus setGISampleCount(int);
    Acad::ErrorStatus setGISampleRadius(double);
    Acad::ErrorStatus setMemoryLimit(int);
    Acad::ErrorStatus setPhotonTraceDepth(int,int,int);
    Acad::ErrorStatus setRayTraceDepth(int,int,int);
    Acad::ErrorStatus setSampling(int,int);
    Acad::ErrorStatus setSamplingContrastColor(float,float,float,float);
    Acad::ErrorStatus setSamplingFilter(AcGiMrFilter,double,double);
    Acad::ErrorStatus setTileSize(int);
    AcGiMrDiagnosticBSPMode diagnosticBSPMode() const;
    AcGiMrDiagnosticMode diagnosticMode() const;
    AcGiMrDiagnosticPhotonMode diagnosticPhotonMode() const;
    AcGiMrShadowMode shadowMode() const;
    AcGiMrTileOrder tileOrder() const;
    AcString exportMIFileName() const;
    bool diagnosticSamplesMode() const;
    bool exportMIEnabled() const;
    bool finalGatheringEnabled() const;
    bool giSampleRadiusEnabled() const;
    bool globalIlluminationEnabled() const;
    bool rayTracingEnabled() const;
    bool shadowMapsEnabled() const;
    double giSampleRadius() const;
    float energyMultiplier() const;
    int fgRayCount() const;
    int giPhotonsPerLight() const;
    int giSampleCount() const;
    int memoryLimit() const;
    int tileSize() const;
    void diagnosticGridMode(AcGiMrDiagnosticGridMode&,float&) const;
    void fgSampleRadius(double&,double&) const;
    void fgSampleRadiusState(bool&,bool&,bool&) const;
    void photonTraceDepth(int&,int&,int&) const;
    void rayTraceDepth(int&,int&,int&) const;
    void sampling(int&,int&) const;
    void samplingContrastColor(float&,float&,float&,float&) const;
    void SamplingFilter(AcGiMrFilter&,double&,double&) const;
    void setDiagnosticBSPMode(AcGiMrDiagnosticBSPMode);
    void setDiagnosticMode(AcGiMrDiagnosticMode);
    void setDiagnosticPhotonMode(AcGiMrDiagnosticPhotonMode);
    void setDiagnosticSamplesMode(bool);
    void setExportMIEnabled(bool);
    void setFGRadiusState(bool,bool,bool);
    void setFinalGatheringEnabled(bool);
    void setGISampleRadiusEnabled(bool);
    void setGlobalIlluminationEnabled(bool);
    void setRayTracingEnabled(bool);
    void setShadowMapsEnabled(bool);
    void setShadowMode(AcGiMrShadowMode);
    void setTileOrder(AcGiMrTileOrder);

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
