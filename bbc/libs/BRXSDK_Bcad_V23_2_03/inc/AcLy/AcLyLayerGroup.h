// Copyright (C) Menhirs NV. All rights reserved.
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