// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"

/** _ */
class AcDbRecoverCallBack
{
public:
    AcDbRecoverCallBack();
    virtual ~AcDbRecoverCallBack();

    virtual Acad::ErrorStatus registerCallBack(AcDbRecover*);
    virtual Acad::ErrorStatus removeCallBack();
};
