// od_gi_glyph.h : OdGiGlyph definition

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "od_api_exports.h"

#include "Gi/GiDrawable.h"

class ODAPI OdGiGlyph : public OdGiDrawable
{
public:
    ODRX_DECLARE_MEMBERS(OdGiGlyph);

    // Called by host application before viewportDraw() resp. worldDraw() is called
    virtual OdResult setLocation(const OdGePoint3d& dcsPoint) = 0;

    // These functions are not called, implemented only to comply with base class
    virtual OdDbStub* id() const { return NULL; };
    virtual OdGsCache* gsNode() const { return NULL; };
    virtual void setGsNode(OdGsCache*) {};
    virtual bool isPersistent() const { return false; };

protected:
    // Glyphs are normally drawn as viewport-specific graphics;
    // to use worldDraw(), the default implementations need to be overridden.
    virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits) const { return 0; };
    virtual bool subWorldDraw(OdGiWorldDraw* pWd) const { return false; };

    // This function needs to be implemented, to draw the glyph's graphic
    // (taking pixel + display size ratio and ObjectSnap glyph settings into account)
    virtual void subViewportDraw(OdGiViewportDraw* pVd) const = 0;
};
