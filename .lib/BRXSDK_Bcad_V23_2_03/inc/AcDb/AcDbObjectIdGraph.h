// Copyright (C) Menhirs NV. All rights reserved.
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
