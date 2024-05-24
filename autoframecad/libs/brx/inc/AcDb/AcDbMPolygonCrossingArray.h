// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/AcArray.h"

class AcDbMPolygonCrossing;

/** _ */
class BRX_IMPORTEXPORT AcDbMPolygonCrossingArray
{
public:
    AcArray<AcDbMPolygonCrossing*> mCrossingArray;

public:
    ~AcDbMPolygonCrossingArray();
};
