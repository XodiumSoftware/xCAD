// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "Misc/AcHeapOperators.h"

class BrxDbGraphNodeImp;

/** _ */
class BRX_IMPORTEXPORT AcDbGraphNode: public AcHeapOperators
{
protected:
    //BRX START
    //V10
    friend class BrxDbGraphNodeImp;
    BrxDbGraphNodeImp* m_pBrxImp;
    //BRX END

public:
    enum Flags
    {
        kNone = 0,
        kVisited = 1,
        kOutsideRefed = 2,
        kSelected = 4,
        kInList = 8,
        kListAll = 14,
        kFirstLevel = 16,
        kUnresTree = 32,
        kAll = 47
    };

public:
    AcDbGraphNode(void* = NULL);
    virtual ~AcDbGraphNode();

    Acad::ErrorStatus addRefTo(AcDbGraphNode*);
    Acad::ErrorStatus clear(Adesk::UInt8);
    Acad::ErrorStatus disconnectAll();
    Acad::ErrorStatus markAs(Adesk::UInt8);
    Acad::ErrorStatus markTree(Adesk::UInt8,AcDbVoidPtrArray* = NULL);
    Acad::ErrorStatus removeRefTo(AcDbGraphNode*);
    AcDbGraph* owner() const;
    AcDbGraphNode* cycleIn(int) const;
    AcDbGraphNode* cycleOut(int) const;
    AcDbGraphNode* in(int) const;
    AcDbGraphNode* nextCycleNode() const;
    AcDbGraphNode* out(int) const;
    bool isCycleNode() const;
    bool isMarkedAs(Adesk::UInt8) const;
    int numCycleIn() const;
    int numCycleOut() const;
    int numIn() const;
    int numOut() const;
    void setData(void*);
    void setEdgeGrowthRate(int,int);
    void* data() const;
};
