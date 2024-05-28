// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGs/AcGsColor.h"
#include "AcGs/AcGsDCRect.h"

class AcGsGraphicsKernel;
class AcGsRenderInterrupter;


/** _ */
class BRX_IMPORTEXPORT AcGsDevice
{
public:
    enum RendererType
    {
        kDefault = 0,
        kSoftware,
        kSoftwareNewViewsOnly,
        kFullRender,
        kSelectionRender,
        kFbxExportRender,
    };

    enum EnableIRResult
    {
        kSuccess,
        kOutOfMemory
    };

public:
    virtual ~AcGsDevice() {}

    virtual AcGsColor getBackgroundColor() = 0;
    virtual bool add(AcGsView*) = 0;
    virtual bool erase(AcGsView*) = 0;
    virtual bool isValid() const = 0;
    virtual bool setBackgroundColor(AcGsColor) = 0;
    virtual RendererType getDeviceRenderer() = 0;
    virtual void eraseAll() = 0;
    virtual void getSnapShot(Atil::Image*,const AcGsDCPoint&) = 0;
    virtual void invalidate() = 0;
    virtual void invalidate(const AcGsDCRect&) = 0;
    virtual void onDisplayChange(int,int,int) = 0;
    virtual void onRealizeBackgroundPalette() = 0;
    virtual void onRealizeForegroundPalette() = 0;
    virtual void onSize(int,int) = 0;
    virtual void setDeviceRenderer(RendererType) = 0;
    virtual void setLogicalPalette(const AcGsColor*,int) = 0;
    virtual void setPhysicalPalette(const AcGsColor*,int) = 0;
    virtual void update(AcGsDCRect* = NULL) = 0;

    //V17
    virtual AcGsGraphicsKernel& graphicsKernel() = 0;

    virtual EnableIRResult beginInteractiveRender(AcGsRenderProgressMonitor*) = 0;
    virtual Atil::Image * createSnapshot(const AcGsDCPoint&, const AcGsDCRect&, GS::ImageDataFormat, GS::ImageOrientation) = 0;
    virtual void endInteractiveRender() = 0;
    virtual int getMaxDeviceWidth() = 0;
    virtual int getMaxDeviceHeight() = 0;
    virtual AcGsRenderInterrupter* getRenderInterrupter() const = 0;
    virtual void invalidate(AcGsModel::RenderType) = 0;
    virtual void invalidate(const AcGsDCRect&, AcGsModel::RenderType) = 0;
    virtual bool isRendering() const = 0;
    virtual void pauseInteractiveRender() = 0;
    virtual void postRenderProgressCheckingReqeust() = 0;
    virtual void resumeInteractiveRender() = 0;
    virtual void setDesiredFrameRate(float) = 0;
    virtual void setDisplayUpdateSuppressed(bool) = 0;
    virtual void setFontKerningDisplay(bool) = 0;
    virtual void setRenderInterrupter(AcGsRenderInterrupter*) = 0;
    virtual void update(AcGsDCRect*, GS::SyncBehavior) = 0;
};
