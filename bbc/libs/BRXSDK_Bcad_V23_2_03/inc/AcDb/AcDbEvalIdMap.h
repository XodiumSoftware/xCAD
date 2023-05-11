// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"

/** _ */
class AcDbEvalIdMap
{
public:
    virtual AcDbEvalNodeId find(const AcDbEvalNodeId&) = 0;
    virtual void kill() = 0;
};
