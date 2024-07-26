// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
