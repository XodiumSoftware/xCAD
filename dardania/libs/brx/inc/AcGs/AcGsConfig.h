// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGs/AcGsGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcGsConfig
{
public:
    enum DegradationChannel
    {
        kViewportDraw = 0,
        kLineAntialias,
        kLighting,
        kTransparencyQuality,
        kShadowsFull,
        kTransparency,
        kDiscardBackfaces,
        kShadowsGround,
        kEdgeStyles,
        kFacetEdges,
        kFastSilhouette,
        kTextures,
        kMaterials,
        kLightingQuality,
        kBackgrounds,
        kIntersectEdges,
        kFaceted,
        kWireframe,
        kDegradationChannels
    };

    enum EffectListType
    {
        kEL_Current,
        kEL_RegistryHardware,
        kEL_RegistrySoftware,
        kEL_File,
        kEL_HardwareBasic,
        kEL_HardwareMedium,
        kEL_HardwareAdvanced
    };

    enum FeatureModeType
    {
        kFM_Start = -3,
        kFM_Legacy = kFM_Start,
        kFM_ClassicDx9,
        kFM_ClassicDx11,
        kFM_Software,
        kFM_Basic,
        kFM_Medium,
        kFM_Advanced,
        kFM_Unknown = 0xffff
    };

    enum Handedness
    {
        kLeft = 0,
        kRight
    };

    enum HardwareFeature
    {
        kHwAcceleration = 0,
        kHwGeometryAccel,
        kHwAntiAliasing,
        kHwGooch,
        kHwShadows,
        kHwFeatures
    };

    enum Quality
    {
        kLowQuality = 0,
        kMediumQuality,
        kHighQuality
    };

    enum SpyglassType
    {
        kNone = 0,
        kSoftware,
        kHardware
    };

    struct EffectStatus
    {
        const AcUniqueString* pUniqueString;
        AcString effectName;
        int bEnabled;
        int bRecommended;
        int bAvailable;
        int nFeatureLevel;
    };

    virtual ~AcGsConfig() {}

    virtual bool adaptiveDegradation() = 0;
    virtual bool cacheViewportDrawGeometry() const = 0;
    virtual bool canDegradeChannel(DegradationChannel) = 0;
    virtual bool configure(const ACHAR*,bool) = 0;
    virtual bool discardBackFaces() = 0;
    virtual bool dynamicTessellation() = 0;
    virtual bool isFeatureAvailable(HardwareFeature) = 0;       //deprecated
    virtual bool isFeatureAvailable(const AcUniqueString*) const = 0;
    virtual bool isFeatureEnabled(HardwareFeature) = 0;         //deprecated
    virtual bool isFeatureEnabled(const AcUniqueString*) const = 0;
    virtual bool isFeatureRecommended(HardwareFeature) = 0;     //deprecated
    virtual bool isFeatureRecommended(const AcUniqueString*) const = 0;
    virtual bool redrawOnWindowExpose() = 0;
    virtual bool saveSettings() = 0;
    virtual bool useDisplayLists() = 0;
    virtual bool useHalfPixelDeviation() = 0;
    virtual DegradationChannel degradationChannelAt(int) = 0;
    virtual GS::ErrorStatus setCurveTessellationTol(int) = 0;
    virtual GS::ErrorStatus setFrameRate(int) = 0;
    virtual GS::ErrorStatus setMaxLODs(int) = 0;
    virtual GS::ErrorStatus setSurfaceTessellationTol(int) = 0;
    virtual Handedness handedness() const = 0;
    virtual int curveTessellationTol() const = 0;
    virtual int degradationChainPosition(DegradationChannel) = 0;
    virtual int driverRevision() const = 0;
    virtual int driverVersion() const = 0;
    virtual int frameRate() = 0;
    virtual int maxLODs() = 0;
    virtual int numHardwareAcceleratedDrivers() = 0;
    virtual int surfaceTessellationTol() = 0;
    virtual Quality transparency() = 0;
    virtual void currentDisplayDriver(ACHAR*,int,ACHAR*,int,bool&) = 0;
    virtual void defaultHardwareAcceleratedDriver(ACHAR*,int,ACHAR*,int) = 0;
    virtual void driverName(ACHAR*,int) const = 0;
    virtual void driverPath(ACHAR*,int) const = 0;
    virtual void hardwareAcceleratedDriver(ACHAR*,int,ACHAR*,int) = 0;
    virtual void hardwareAcceleratedDrivers(ACHAR*,int,ACHAR**,int) = 0;    //deprecated
    virtual void hardwareAcceleratedDrivers(ACHAR*, int, ACHAR**, int, int) = 0;
    virtual void setAdaptiveDegradation(bool) = 0;
    virtual void setCacheViewportDrawGeometry(bool) = 0;
    virtual void setCanDegradeChannel(DegradationChannel,bool) = 0;
    virtual void setDiscardBackFaces(bool) = 0;
    virtual void setDriverPath(const ACHAR*) = 0;
    virtual void setDynamicTessellation(bool) = 0;
    virtual void setFeatureEnabled(HardwareFeature,bool = true) = 0;        //deprecated
    virtual void setFeatureEnabled(const AcUniqueString*, bool = true) = 0;
    virtual void setHandedness(Handedness) = 0;
    virtual void setHardwareAcceleratedDriver(const ACHAR*,const ACHAR*) = 0;
    virtual void setTransparency(Quality) = 0;
    virtual void setUseHalfPixelDeviation(bool) = 0;
    virtual void shiftDegradationChainPosition(DegradationChannel,bool) = 0;

    virtual void addReactor(AcGsConfigReactor*) = 0;
    virtual void removeReactor(AcGsConfigReactor*) = 0;
    virtual bool canEnableMetal() const = 0;
    virtual bool configure() = 0;
    virtual bool generateVertexNormals() const = 0;
    virtual AcArray<EffectStatus>* getEffectList(EffectListType type) = 0;
    virtual int getFeatureAvailableVal(const AcUniqueString*) const = 0;
    virtual int getFeatureRecommendedVal(const AcUniqueString*) const = 0;
    virtual FeatureModeType getFeatureMode() const = 0;
    virtual int getFeatureVal(const AcUniqueString*) const = 0;
    virtual int getFeatureModeAvailable() const = 0;
    virtual AcString getVirtualDeviceName() = 0;
    virtual int getMetalMode() const = 0;
    virtual bool isAADisabledInInteractive() const = 0;
    virtual bool isHardwareAccelerationAvailable() const = 0;
    virtual bool isHardwareAccelerationEnabled() const = 0;
    virtual bool isHardwareAccelerationRecommended() const = 0;
    virtual bool isInConfiguring() = 0;
    virtual bool isLODEnabledInRetainModeWhileInteractive() const = 0;
    virtual bool isNoHardwareOverrideEnabled() const = 0;
    virtual void saveToRegistry() = 0;
    virtual void setFeatureVal(const AcUniqueString*, int = 0) = 0;
    virtual void setGenerateVertexNormals(bool bEnable) = 0;
    virtual void setHardwareAcceleration(bool bEnable) = 0;
    virtual void setFeatureMode(const FeatureModeType) = 0;
    virtual void setRedrawOnWindowExpose(bool bRedrawWindowExpose) = 0;
    virtual void setMetalMode(int metalMode) = 0;
    virtual bool showConfigDialog(const wchar_t* = nullptr) const = 0;
    virtual SpyglassType spyglassType() const = 0;
};
