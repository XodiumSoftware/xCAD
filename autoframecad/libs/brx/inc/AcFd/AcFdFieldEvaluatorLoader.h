// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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