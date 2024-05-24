// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/AcHeapOperators.h"
#include "Misc/MiscGlobal.h"

/** _ */
class AcDbEvalContextPair: public AcHeapOperators
{
public:
    AcDbEvalContextPair();
    AcDbEvalContextPair(const ACHAR*,void*);
    virtual ~AcDbEvalContextPair();

    const ACHAR* key() const;
    void setKey(const ACHAR*);
    void setValue(void*);
    void* value() const;
};
