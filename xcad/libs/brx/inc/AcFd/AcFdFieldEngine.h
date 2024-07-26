// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class AcFdFieldEngine: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcFdFieldEngine);

     AcFdFieldEngine();
     virtual ~AcFdFieldEngine();

    Acad::ErrorStatus registerEvaluatorLoader(AcFdFieldEvaluatorLoader*);
    Acad::ErrorStatus unregisterEvaluatorLoader(AcFdFieldEvaluatorLoader*);
    AcFdFieldEvaluator* findEvaluator(AcDbField*,const ACHAR*&);
    AcFdFieldEvaluator* getEvaluator(const ACHAR*);
    AcFdFieldEvaluatorLoader* getEvaluatorLoader(int);
    int evaluatorLoaderCount() const;
};