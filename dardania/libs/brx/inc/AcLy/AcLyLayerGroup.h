// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcLy/AcLyLayerFilter.h"

/** _ */
class AcLyLayerGroup: public AcLyLayerFilter
{
public:
    ACRX_DECLARE_MEMBERS(AcLyLayerGroup);

    AcLyLayerGroup();

    virtual Acad::ErrorStatus addLayerId(const AcDbObjectId&);
    virtual Acad::ErrorStatus removeLayerId(const AcDbObjectId&);
    virtual const AcDbObjectIdArray& layerIds() const;
};