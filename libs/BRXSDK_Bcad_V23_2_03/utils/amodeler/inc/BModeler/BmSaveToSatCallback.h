// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class BM_IMPORTEXPORT SaveToSatCallback
{
public:
    virtual ~SaveToSatCallback();

    virtual void saveDouble(double) = 0;
    virtual void saveIdent(const char*) = 0;
    virtual void saveIndex(int) = 0;
    virtual void saveInt(int) = 0;
};

}