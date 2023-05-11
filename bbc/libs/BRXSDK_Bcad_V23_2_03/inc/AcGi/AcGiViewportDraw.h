// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcGi/AcGiCommonDraw.h"

/** _ */
class BRX_IMPORTEXPORT AcGiViewportDraw: public AcGiCommonDraw
{
public:
    ACRX_DECLARE_MEMBERS(AcGiViewportDraw);

    virtual AcDbObjectId viewportObjectId() const = 0;
    virtual AcGiViewport& viewport() const = 0;
    virtual AcGiViewportGeometry& geometry() const = 0;
    virtual Adesk::Boolean isValidId(const Adesk::ULongPtr) const = 0;
    virtual Adesk::UInt32 sequenceNumber() const = 0;
};
