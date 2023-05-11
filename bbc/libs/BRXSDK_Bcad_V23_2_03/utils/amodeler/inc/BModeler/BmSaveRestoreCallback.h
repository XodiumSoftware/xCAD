// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class BM_IMPORTEXPORT SaveRestoreCallback
{
public:
    virtual ~SaveRestoreCallback();

    virtual void restoreBytes(void*,int) = 0;
    virtual void saveBytes(const void*,int) = 0;
};

}