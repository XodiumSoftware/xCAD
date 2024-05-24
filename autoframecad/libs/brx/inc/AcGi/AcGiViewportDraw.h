// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
