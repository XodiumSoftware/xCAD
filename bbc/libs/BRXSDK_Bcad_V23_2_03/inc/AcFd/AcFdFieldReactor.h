// Copyright (C) Menhirs NV. All rights reserved.
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