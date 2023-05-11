// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"

/** _ */
class AcDbRecover
{
public:
    virtual int callBack(AcDbDatabase*) = 0;
};
