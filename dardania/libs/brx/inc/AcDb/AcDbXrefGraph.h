// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
