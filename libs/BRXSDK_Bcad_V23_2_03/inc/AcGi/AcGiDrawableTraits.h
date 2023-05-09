// Copyright (C) Menhirs NV. All rights reserved.
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
