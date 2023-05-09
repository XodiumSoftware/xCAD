// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_IMPORTEXPORT AcDbMatchProperties: public AcRxObject
{
public:
    enum Flags
    {
        kColorFlag = 1,
        kLayerFlag = 2,
        kLtypeFlag = 4,
        kThicknessFlag = 8,
        kLtscaleFlag = 16,
        kTextFlag = 32,
        kDimensionFlag = 64,
        kHatchFlag = 128,
        kLweightFlag = 256,
        kPlotstylenameFlag = 512,
        kPolylineFlag = 1024,
        kViewportFlag = 2048,
        kTableFlag = 4096,
        kMaterialFlag = 8192,
        kShadowDisplayFlag = 16384,
        kMultileaderFlag = 32768,
        kTransparencyFlag = 65536,

        kSetAllFlagsOn = kColorFlag | kLayerFlag | kLtypeFlag | kThicknessFlag | kLtscaleFlag |
                         kTextFlag | kDimensionFlag | kHatchFlag | kLweightFlag | kPlotstylenameFlag |
                         kPolylineFlag | kViewportFlag | kTableFlag | kMaterialFlag | kShadowDisplayFlag |
                         kMultileaderFlag | kTransparencyFlag,
    };

    ACRX_DECLARE_MEMBERS(AcDbMatchProperties);

    virtual void copyProperties(AcDbEntity*,AcDbEntity*,unsigned int) const = 0;
};
