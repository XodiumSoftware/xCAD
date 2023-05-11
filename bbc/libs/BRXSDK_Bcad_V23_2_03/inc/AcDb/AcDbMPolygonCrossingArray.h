// Copyright (C) Menhirs NV. All rights reserved.
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
