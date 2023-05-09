// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "Misc/AcHeapOperators.h"

/** _ */
class AcDbGraphStack: public AcHeapOperators
{
private:
    AcDbVoidPtrArray m_stack;

public:
    AcDbGraphStack(int = 0,int = 8);
    ~AcDbGraphStack();

    Acad::ErrorStatus push(AcDbGraphNode*);
    AcDbGraphNode* pop();
    AcDbGraphNode* top() const;
    bool isEmpty() const;
};
