// Copyright (C) Menhirs NV. All rights reserved.
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