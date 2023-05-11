// Copyright (C) Menhirs NV. All rights reserved.
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
