// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGraph.h"
#include "AcDb/AcDbIdMapping.h"
#include "AcDb/AcDbObjectIdGraphNode.h"

/** _ */
class AcDbObjectIdGraph: public AcDbGraph
{
public:
    AcDbObjectIdGraph();
    virtual ~AcDbObjectIdGraph();

    Acad::ErrorStatus addNode(AcDbObjectIdGraphNode*);
    Acad::ErrorStatus delNode(AcDbObjectIdGraphNode*);
    AcDbObjectIdGraphNode* findNode(const AcDbObjectId) const;
    AcDbObjectIdGraphNode* idNode(int) const;
};
