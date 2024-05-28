// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObjectId.h"
#include "AcGi/AcGiGlobal.h"
#include "AcGs/AcGsGlobal.h"
#include "AcRx/AcRxObject.h"

class AcGiDrawStream;

/** _ */
class BRX_IMPORTEXPORT AcGiDrawable: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcGiDrawable);

    enum DrawableType
    {
        kGeometry = 0,
        kDistantLight,
        kPointLight,
        kSpotLight,
        kAmbientLight,
        kSolidBackground,
        kGradientBackground,
        kImageBackground,
        kGroundPlaneBackground,
        kViewport
    };

    enum SetAttributesFlags
    {
        kDrawableNone = 0,
        kDrawableIsAnEntity = 1,
        kDrawableUsesNesting = 2,
        kDrawableIsCompoundObject = 4,
        kDrawableViewIndependentViewportDraw = 8,
        kDrawableIsInvisible = 16,
        kDrawableHasAttributes = 32,
        kDrawableRegenTypeDependentGeometry = 64,
        kDrawableIsDimension = 133,
        kDrawableRegenDraw = 256,
        kDrawableStandardDisplaySingleLOD = 512,
        kDrawableShadedDisplaySingleLOD = 1024,
        kDrawableViewDependentViewportDraw = 2048,
        kDrawableBlockDependentViewportDraw = 4096,
        kDrawableIsExternalReference = 8192,
        kDrawableNotPlottable = 16384,
        kDrawableNotAllowLCS = 32768,
        kDrawableMergeControlOff = 65536,
        kThreadedWorldDrawViewportDraw = 131072, //UNUSED - see AcGiDrawable::regenSupportFlags()
    };

protected:
    AcGiDrawable();
public:
    virtual ~AcGiDrawable();

    // INFO :
    //   for 'virtual Adesk::UInt32 viewportDrawLogicalFlags(AcGiViewportDraw*) final'
    //   same logic as for "setAttributes()" function, but especially for 'ViewIndependentViewportDraw'
    //   draw process;
    //   to return the bitwise combination of desired SetAttributesFlags bit values

    virtual AcDbObjectId id() const = 0;
    AcGsNode* gsNode() const;   //deprecated
    virtual Adesk::Boolean isPersistent() const = 0;
    virtual Adesk::Boolean RolloverHit(Adesk::ULongPtr,Adesk::ULongPtr,Adesk::Boolean);
    virtual Adesk::Boolean worldDraw(AcGiWorldDraw*) final;
    virtual Adesk::UInt32 setAttributes(AcGiDrawableTraits*) final;
    virtual Adesk::UInt32 viewportDrawLogicalFlags(AcGiViewportDraw*) final;
    virtual DrawableType drawableType() const;
    void setGsNode(AcGsNode*);  //deprecated
    virtual void viewportDraw(AcGiViewportDraw*) final;
    virtual bool bounds(AcDbExtents&) const;
    virtual void setDrawStream(AcGiDrawStream*);
    virtual AcGiDrawStream* drawStream() const;

    // returns combination of AcRx::MTSupport enum flags for enabling multi-threading support
    virtual Adesk::UInt32 regenSupportFlags() const final;

protected:
    friend class AcGiDrawableOverrule;
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*) = 0;
    virtual void subViewportDraw(AcGiViewportDraw*) = 0;
    virtual Adesk::UInt32 subViewportDrawLogicalFlags(AcGiViewportDraw*);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*) = 0;

    // V23
    // returns combination of AcRx::MTSupport enum flags for enabling multi-threading support
    virtual Adesk::UInt32 subRegenSupportFlags() const;
};
