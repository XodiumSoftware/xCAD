// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "Misc/AcHeapOperators.h"

class BrxDbGraphNodeImp;

/** _ */
class BRX_IMPORTEXPORT AcDbGraph: public AcHeapOperators
{
protected:
    //BRX START
    //V10
    friend class BrxDbGraphNodeImp;
    void* m_pBrxImp;
    //BRX END

public:
    AcDbGraph(AcDbGraphNode* = NULL);
    virtual ~AcDbGraph();

    virtual Adesk::Boolean findCycles(AcDbGraphNode* = NULL);

    Acad::ErrorStatus addEdge(AcDbGraphNode*,AcDbGraphNode*);
    Acad::ErrorStatus addNode(AcDbGraphNode*);
    Acad::ErrorStatus breakCycleEdge(AcDbGraphNode*,AcDbGraphNode*);
    Acad::ErrorStatus delNode(AcDbGraphNode*);
    AcDbGraphNode* node(int) const;
    AcDbGraphNode* rootNode() const;
    bool isEmpty() const;
    int numNodes() const;
    void clearAll(Adesk::UInt8);
    void getOutgoing(AcDbVoidPtrArray&);
    void reset();
    void setNodeGrowthRate(int);

protected:
    Acad::ErrorStatus clearAllCycles();
};
