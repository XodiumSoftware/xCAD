// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/AcValue.h"

/** _ */
class AcFdFieldResult: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcFdFieldResult);

    AcFdFieldResult();

    virtual Acad::ErrorStatus setEvaluationStatus(int,int = 0,const ACHAR* = NULL);
    virtual Acad::ErrorStatus setFieldValue(const AcValue*);
};