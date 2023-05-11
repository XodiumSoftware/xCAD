// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/AcArray.h"

/** _ */
class BRX_IMPORTEXPORT AcDbMPolygonNode
{
public:
    AcArray<AcDbMPolygonNode*> mChildren;
    AcDbMPolygonNode* mParent;
    int mLoopIndex;

public:
    AcDbMPolygonNode();
};
