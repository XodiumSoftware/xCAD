// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
