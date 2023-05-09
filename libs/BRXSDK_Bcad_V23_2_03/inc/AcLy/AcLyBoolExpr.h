// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcLy/AcLyAndExpr.h"

/** _ */
class AcLyBoolExpr
{
public:
    virtual ~AcLyBoolExpr() {}

    virtual const AcArray<AcLyAndExpr*>& getAndExprs() const = 0;
};