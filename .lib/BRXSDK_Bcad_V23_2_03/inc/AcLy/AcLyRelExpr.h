// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class AcLyRelExpr
{
public:
    virtual const ACHAR* getConstant() const = 0;
    virtual const ACHAR* getVariable() const = 0;
};