// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGraph.h"

/** _ */
class BRX_IMPORTEXPORT AcDbXrefGraph: public AcDbGraph
{
public:
    AcDbXrefGraph(AcDbXrefGraphNode* = NULL);
    virtual ~AcDbXrefGraph();

    virtual Adesk::Boolean findCycles(AcDbGraphNode* = NULL);

    AcDbXrefGraphNode* hostDwg() const;
    AcDbXrefGraphNode* xrefNode(AcDbObjectId) const;
    AcDbXrefGraphNode* xrefNode(const AcDbDatabase*) const;
    AcDbXrefGraphNode* xrefNode(const ACHAR*) const;
    AcDbXrefGraphNode* xrefNode(int) const;
    Adesk::Boolean markUnresolvedTrees();
};
