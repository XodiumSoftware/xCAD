// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGePoint3d.h"
#include "AcGi/AcGiDrawable.h"
#include "AcGs/AcGsColor.h"
#include "AcGs/AcGsDCRect.h"
#include "AcGs/AcGsClientViewInfo.h"

class AcGsGraphicsKernel;
class AcGsRenderProgressMonitor;


/** _ */
class BRX_IMPORTEXPORT AcGsView
{
public:
    enum DefaultLightingType
    {
        kOneLight = 0,
        kTwoLights,
        kBackLight
    };

    enum Projection
    {
        kParallel = 0,
        kPerspective
    };

    enum RenderMode
    {
        k2DOptimized = 0,
        kBoundingBox,
        kWireframe,
        kHiddenLine,
        kFlatShaded,
        kGouraudShaded,
        kFlatShadedWithWireframe,
        kGouraudShadedWithWireframe,
        kNone,
        kCount,
    };

    enum SelectionMode
    {
        kWindow = 0,
        kCrossing,
        kFence,
        kWPoly,
        kCPoly
    };

    enum ModelCloneOption
    {
        kCloneNoModels = 0,
        kCloneMainPersistentModel,
        kCloneAllModels
    };

    enum EnableIRResult
    {
        kSuccess = 0,
        kOutOfMemory
    };

    virtual ~AcGsView() {}

    virtual AcDbObjectId background() const = 0;
    virtual AcDbObjectId visualStyle() const = 0;
    virtual AcGeMatrix3d objectToDeviceMatrix() const = 0;
    virtual AcGeMatrix3d projectionMatrix() const = 0;
    virtual AcGeMatrix3d screenMatrix() const = 0;
    virtual AcGeMatrix3d viewingMatrix() const = 0;
    virtual AcGeMatrix3d worldToDeviceMatrix() const = 0;
    virtual AcGePoint3d position() const = 0;
    virtual AcGePoint3d target() const = 0;
    virtual AcGeVector3d upVector() const = 0;
    virtual AcGsDevice* getDevice() const = 0;
    virtual AcGsView* clone(bool = true,bool = false) = 0;
    virtual bool add(AcGiDrawable*,AcGsModel*) = 0;
    virtual bool erase(AcGiDrawable*) = 0;
    virtual bool exceededBounds() = 0;
    virtual bool extentsInView(const AcGePoint3d&,const AcGePoint3d&) = 0;
    virtual bool isBackClipped() const = 0;
    virtual bool isFrontClipped() const = 0;
    virtual bool isPerspective() const = 0;
    virtual bool isStereoEnabled() const = 0;
    virtual bool isValid() const = 0;
    virtual bool isViewportBorderVisible() const = 0;
    virtual bool isVisible() = 0;
    virtual bool pointInView(const AcGePoint3d&) = 0;
    virtual bool visualStyle(AcGiVisualStyle&) const = 0;
    virtual double backClip() const = 0;
    virtual double fieldHeight() const = 0;
    virtual double fieldWidth() const = 0;
    virtual double frontClip() const = 0;
    virtual int maximumUpgrade() = 0;
    virtual int minimumDegrade() = 0;
    virtual RenderMode mode() const = 0;
    virtual void beginInteractivity(double) = 0;
    virtual void clearFrozenLayers() = 0;
    virtual void dolly(const AcGeVector3d&) = 0;
    virtual void dolly(double,double,double) = 0;
    virtual void enableDefaultLighting(bool,DefaultLightingType = kTwoLights) = 0;
    virtual void enableStereo(bool) = 0;
    virtual void endInteractivity() = 0;
    virtual void eraseAll() = 0;
    virtual void flush() = 0;
    virtual void freezeLayer(Adesk::IntDbId) = 0;
    virtual const AcGsClientViewInfo& getClientViewInfo() const = 0;
    virtual AcGsModel* getModel(AcGiDrawable*) const = 0;
    virtual void getModelList(AcArray<AcGsModel*>&) const = 0;
    virtual void getNumPixelsInUnitSquare(const AcGePoint3d&,AcGePoint2d&,bool = true) const = 0;
    virtual void getSnapShot(Atil::Image*,const AcGsDCPoint&) = 0;
    virtual void getStereoParameters(double&,double&) const = 0;
    virtual void getViewport(AcGePoint2d&,AcGePoint2d&) const = 0;
    virtual void getViewport(AcGsDCRect&) const = 0;
    virtual void getViewportBorderProperties(AcGsColor&,int&) const = 0;
    virtual void hide() = 0;
    virtual void invalidate() = 0;
    virtual void invalidate(const AcGsDCRect&)= 0;
    virtual void invalidateCachedViewportGeometry() = 0;
    virtual void invalidateCachedViewportGeometry(AcGiDrawable*) = 0;
    virtual bool isInteractive() const = 0;
    virtual void orbit(double,double) = 0;
    virtual void pan(double,double) = 0;
    virtual void removeViewportClipRegion() = 0;
    virtual void roll(double) = 0;
    virtual void setBackClip(double) = 0;
    virtual void setBackground(const AcDbObjectId) = 0;
    virtual void setEnableBackClip(bool) = 0;
    virtual void setEnableFrontClip(bool) = 0;
    virtual void setFrontClip(double) = 0;
    virtual void setMaximumUpgrade(int) = 0;
    virtual void setMinimumDegrade(int) = 0;
    virtual void setMode(RenderMode) = 0;
    virtual void setStereoParameters(double,double) = 0;
    virtual void setView(const AcGePoint3d&,const AcGePoint3d&,const AcGeVector3d&,double,double,Projection = kParallel) = 0;
    virtual void setViewport(const AcGePoint2d&,const AcGePoint2d&) = 0;
    virtual void setViewport(const AcGsDCRect&) = 0;
    virtual void setViewportBorderProperties(const AcGsColor&,int) = 0;
    virtual void setViewportBorderVisibility(bool) = 0;
    virtual void setViewportClipRegion(int,const int*,const AcGsDCPoint*) = 0;
    virtual void setVisualStyle(const AcDbObjectId) = 0;
    virtual void setVisualStyle(const AcGiVisualStyle&) = 0;
    virtual void show() = 0;
    virtual void thawLayer(Adesk::IntDbId) = 0;
    virtual void update() = 0;
    virtual void zoom(double) = 0;
    virtual void zoomExtents(const AcGePoint3d&,const AcGePoint3d&) = 0;
    virtual void zoomWindow(const AcGePoint2d&,const AcGePoint2d&) = 0;

    //V17
    virtual AcGsGraphicsKernel& graphicsKernel() = 0;

    virtual void beginFastInteractivity() = 0;
    virtual EnableIRResult beginInteractiveRender(AcGsRenderProgressMonitor*) = 0;
    virtual AcGsView* clone(bool bCloneViewParameters, ModelCloneOption) = 0;
    virtual Atil::Image* createSnapshot(const AcGsDCPoint&, const AcGsDCRect&, GS::ImageDataFormat, GS::ImageOrientation, bool = false) = 0;
    virtual bool endFastInteractivity() = 0;
    virtual void endInteractiveRender() = 0;
    virtual bool isFastInteractivity() = 0;
    virtual bool isPointInViewport(const Adesk::Int32, const Adesk::Int32) = 0;
    virtual bool isRendering() const = 0;
    virtual bool renderToImage(Atil::Image*, AcGiDrawable*, AcGsRenderProgressMonitor*, const AcGsDCRect&, bool = false) = 0;
    virtual void update(GS::SyncBehavior) = 0;
};
