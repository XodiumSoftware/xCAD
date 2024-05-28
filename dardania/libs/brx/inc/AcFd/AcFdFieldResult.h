// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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