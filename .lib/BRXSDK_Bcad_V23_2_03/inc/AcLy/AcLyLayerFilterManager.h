// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcLy/AcLyLayerFilter.h"

/** _ */
class AcLyLayerFilterManager
{
public:
    virtual Acad::ErrorStatus getFilters(AcLyLayerFilter*&,AcLyLayerFilter*&) = 0;
    virtual Acad::ErrorStatus setFilters(const AcLyLayerFilter*,const AcLyLayerFilter*) = 0;
};