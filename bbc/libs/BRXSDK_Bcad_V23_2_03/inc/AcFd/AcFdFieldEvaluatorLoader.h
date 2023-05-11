// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class AcFdFieldEvaluatorLoader: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcFdFieldEvaluatorLoader);

     AcFdFieldEvaluatorLoader();
     ~AcFdFieldEvaluatorLoader();

     virtual AcFdFieldEvaluator* findEvaluator(AcDbField*,const ACHAR*&);
     virtual AcFdFieldEvaluator* getEvaluator(const ACHAR*);
};