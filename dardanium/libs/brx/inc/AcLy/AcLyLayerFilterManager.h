// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcLy/AcLyLayerFilter.h"

/** _ */
class AcLyLayerFilterManager
{
public:
    virtual Acad::ErrorStatus getFilters(AcLyLayerFilter*&,AcLyLayerFilter*&) = 0;
    virtual Acad::ErrorStatus setFilters(const AcLyLayerFilter*,const AcLyLayerFilter*) = 0;
};