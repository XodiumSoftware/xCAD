// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"
#include "Misc/AcArray.h"

/** _ */
class AcFdFieldReactor: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcFdFieldReactor);

    virtual Acad::ErrorStatus beginEvaluateFields(int,AcDbDatabase*);
    virtual Acad::ErrorStatus endEvaluateFields(int,AcDbDatabase*);
};

typedef AcArray<AcFdFieldReactor*> FieldReactors;