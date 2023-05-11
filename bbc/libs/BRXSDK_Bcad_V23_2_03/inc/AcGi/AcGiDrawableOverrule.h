// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxOverrule.h"

class AcGiDrawable;
class AcGiDrawableTraits;
class AcGiViewportDraw;
class AcGiWorldDraw;

/** _ */
class BRX_IMPORTEXPORT AcGiDrawableOverrule : public AcRxOverrule
{
public:
    ACRX_DECLARE_MEMBERS(AcGiDrawableOverrule);

    AcGiDrawableOverrule();

    virtual Adesk::UInt32 setAttributes(AcGiDrawable*, AcGiDrawableTraits*);
    virtual void viewportDraw(AcGiDrawable*, AcGiViewportDraw*);
    virtual Adesk::UInt32 viewportDrawLogicalFlags(AcGiDrawable*, AcGiViewportDraw*);
    virtual Adesk::Boolean worldDraw(AcGiDrawable*, AcGiWorldDraw*);

    // since V23
    virtual Adesk::UInt32 regenSupportFlags(AcGiDrawable* pSubject);
};
