// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiDrawable.h"

class AcGePoint3d;

/** _ */
class BRX_IMPORTEXPORT AcGiGlyph: public AcGiDrawable
{
public:
    ACRX_DECLARE_MEMBERS(AcGiGlyph);

    virtual Acad::ErrorStatus setLocation(const AcGePoint3d&) = 0;
    virtual AcDbObjectId id() const;
    virtual Adesk::Boolean isPersistent() const;
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
    virtual void subViewportDraw(AcGiViewportDraw*) = 0;
};
