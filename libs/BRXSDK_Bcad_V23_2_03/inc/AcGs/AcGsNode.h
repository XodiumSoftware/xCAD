// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiGlobal.h"

/** _ */
class AcGsNode
{
public:
    virtual AcGiDrawable* drawable() const = 0;
    virtual void setDrawableNull () = 0;
};