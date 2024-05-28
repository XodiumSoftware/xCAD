// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiSubEntityTraits.h"

/** _ */
class BRX_IMPORTEXPORT AcGiDrawableTraits: public AcGiSubEntityTraits
{
protected:
    enum LayerFlags
    {
        kNone = 0,
        kOff = 1,
        kFrozen = 2,
        kZero = 4
    };

public:
    ACRX_DECLARE_MEMBERS(AcGiDrawableTraits);

    virtual void addLight(const AcDbObjectId&);
protected:
    virtual void setLayerFlags(Adesk::UInt8) {}
public:
    virtual void setupForEntity(AcDbEntity*);

    friend class AcDbLayerTableRecord;
};
