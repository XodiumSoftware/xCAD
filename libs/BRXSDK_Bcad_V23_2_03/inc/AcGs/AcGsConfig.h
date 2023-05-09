// Copyright (C) Menhirs NV. All rights reserved.
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

    virtual ~AcGsConfig() {}

    virtual bool adaptiveDegradation() = 0;
    virtual bool cacheViewportDrawGeometry() const = 0;
    virtual bool canDegradeChannel(DegradationChannel) = 0;
    virtual bool configure(const ACHAR*,bool) = 0;
    virtual bool discardBackFaces() = 0;
    virtual bool dynamicTessellation() = 0;
    virtual bool isFeatureAvailable(HardwareFeature) = 0;
    virtual bool isFeatureEnabled(HardwareFeature) = 0;
    virtual bool isFeatureRecommended(HardwareFeature) = 0;
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
    virtual int curveTessellationTol() = 0;
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
    virtual void hardwareAcceleratedDrivers(ACHAR*,int,ACHAR**,int) = 0;
    virtual void setAdaptiveDegradation(bool) = 0;
    virtual void setCacheViewportDrawGeometry(bool) = 0;
    virtual void setCanDegradeChannel(DegradationChannel,bool) = 0;
    virtual void setDiscardBackFaces(bool) = 0;
    virtual void setDriverPath(const ACHAR*) = 0;
    virtual void setDynamicTessellation(bool) = 0;
    virtual void setFeatureEnabled(HardwareFeature,bool = true) = 0;
    virtual void setHandedness(Handedness) = 0;
    virtual void setHardwareAcceleratedDriver(const ACHAR*,const ACHAR*) = 0;
    virtual void setTransparency(Quality) = 0;
    virtual void setUseHalfPixelDeviation(bool) = 0;
    virtual void shiftDegradationChainPosition(DegradationChannel,bool) = 0;
};
