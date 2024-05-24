// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGs/AcGsView.h"

class AcGsGraphicsKernel;


/** _ */
class BRX_IMPORTEXPORT AcGsModel
{
public:
    enum InvalidationHint
    {
        kInvalidateNone = 0,
        kInvalidateIsolines,
        kInvalidateViewportCache,
        kInvalidateAll,
        kInvalidateAllStatic,
        kInvalidateFacets,
        kInvalidateFills,
        kInvalidateLinetypes,
        kInvalidateMaterials,
        kInvalidateLayers,
        kInvalidateXrefs,
        kInvalidateRasterImages,
        kInvalidateAttributes,
        kInvalidateUnderlayFrame,
        kInvalidateLtScale,
        kInvalidateTransform,
        kInvalidateTransparencies,
        kInvalidateDrawableByView
    };

    enum RenderType
    {
        kMain = 0,
        kSprite,
        kDirect,
        kHighlight,
        kHighlightSelection,
        kDirectTopmost,
        kContrast,
        kCount
    };

    enum OrderActionType
    {
        kMoveBelow = 0,
        kMoveAbove,
        kSwapOrder
    };

    virtual ~AcGsModel() {}

    virtual AcDbObjectId background() const = 0;
    virtual AcDbObjectId visualStyle() const = 0;
    virtual AcGeMatrix3d transform() const = 0;
    virtual bool addSceneGraphRoot(AcGiDrawable*) = 0;
    virtual bool eraseSceneGraphRoot(AcGiDrawable*) = 0;
    virtual bool isSectioningEnabled() const = 0;
    virtual bool linetypesEnabled() const = 0;
    virtual bool setSectioning(const AcGePoint3dArray&,const AcGeVector3d&) = 0;
    virtual bool setSectioning(const AcGePoint3dArray&,const AcGeVector3d&,double,double) = 0;
    virtual bool visualStyle(AcGiVisualStyle&) const = 0;
    virtual bool isLightingPhotometric() const = 0;
    virtual bool lightsInBlocksEnabled() const = 0;
    virtual double shadowPlaneLocation() const = 0;
    virtual double unitScale() const = 0;
    virtual RenderType renderType() = 0;
    virtual void enableLinetypes(bool) = 0;
    virtual void invalidate(InvalidationHint) = 0;
    virtual void onAdded(AcGiDrawable*,AcGiDrawable*) = 0;
    virtual void onAdded(AcGiDrawable*,LONG_PTR) = 0;
    virtual void onErased(AcGiDrawable*,AcGiDrawable*) = 0;
    virtual void onErased(AcGiDrawable*,LONG_PTR) = 0;
    virtual void onModified(AcGiDrawable*,AcGiDrawable*) = 0;
    virtual void onModified(AcGiDrawable*,LONG_PTR) = 0;
    virtual void onPaletteModified() = 0;
    virtual void setBackground(const AcDbObjectId) = 0;
    virtual void setEnableSectioning(bool) = 0;
    virtual void setExtents(const AcGePoint3d&,const AcGePoint3d&) = 0;
    virtual void setLightingPhotometric(bool) = 0;
    virtual void setLightsInBlocksEnabled(bool) = 0;
    virtual void setRenderModeOverride(AcGsView::RenderMode = AcGsView::kNone) = 0;
    virtual void setSectioningVisualStyle(const AcDbObjectId) = 0;
    virtual void setShadowPlaneLocation(double) = 0;
    virtual void setTransform(const AcGeMatrix3d&) = 0;
    virtual void setViewClippingOverride(bool) = 0;
    virtual void setVisualStyle(const AcDbObjectId) = 0;
    virtual void setVisualStyle(const AcGiVisualStyle&) = 0;
    virtual bool selectable() const = 0;
    virtual void setSelectable(bool) = 0;
    virtual void setUnitScale(bool) = 0;

    //V17
    virtual AcGsGraphicsKernel& graphicsKernel() = 0;

    virtual bool bounds(const AcGiDrawable&, AcGePoint3d&, AcGePoint3d&) = 0;
    virtual void onModified(AcGiDrawable*, AcGiDrawable*, InvalidationHint) = 0;
    virtual void onModified(AcGiDrawable*, LONG_PTR, InvalidationHint) = 0;
    virtual void setDrawOrder(AcGiDrawable*, AcGiDrawable*, AcGiDrawable*, OrderActionType) = 0;
};
