// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class AcFdFieldEvaluator: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcFdFieldEvaluator);

     AcFdFieldEvaluator();
     virtual ~AcFdFieldEvaluator();

    virtual Acad::ErrorStatus compile(AcDbField*, AcDbDatabase*, AcFdFieldResult*);
    virtual Acad::ErrorStatus evaluate(AcDbField*, int, AcDbDatabase*, AcFdFieldResult*);
    virtual Acad::ErrorStatus format(AcDbField*, AcString&);
    virtual Acad::ErrorStatus format(AcDbField*, ACHAR*&);
    virtual Acad::ErrorStatus initialize(AcDbField*);
    virtual const ACHAR* evaluatorId() const;
    virtual const ACHAR* evaluatorId(AcDbField*);
};
