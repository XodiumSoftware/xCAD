// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeGlobal.h"
#include "AcGi/AcGiGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcGiCommonDraw: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcGiCommonDraw);

    virtual AcGiContext* context() = 0;
    virtual AcGiGeometry* rawGeometry() const = 0;
    virtual AcGiRegenType regenType() const = 0;
    virtual AcGiSubEntityTraits& subEntityTraits() const = 0;
    virtual Adesk::Boolean isDragging() const = 0;
    virtual Adesk::Boolean regenAbort() const = 0;
    virtual Adesk::UInt32 numberOfIsolines() const = 0;
    virtual bool secondaryCall() const;
    virtual double deviation(const AcGiDeviationType,const AcGePoint3d&) const = 0;
};
