// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcLy/AcLyRelExpr.h"
#include "Misc/AcArray.h"

/** _ */
class AcLyAndExpr
{
public:
    virtual ~AcLyAndExpr() {}

    virtual const AcArray<AcLyRelExpr*>& getRelExprs() const = 0;
};
