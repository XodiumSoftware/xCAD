// Copyright (C) Menhirs NV. All rights reserved.
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
    virtual AcGsNode* gsNode() const;
    virtual Adesk::Boolean isPersistent() const;
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
    virtual void setGsNode(AcGsNode*);
    virtual void subViewportDraw(AcGiViewportDraw*) = 0;
};
