// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

class AcDMMEntityReactorInfo;
class AcDMMSheetReactorInfo;

/** _ */
class BRX_IMPORTEXPORT AcDMMReactor: public AcRxObject
{
protected:
    AcDMMReactor() {}
public:
    virtual ~AcDMMReactor() {}

    virtual void OnBeginEntity(AcDMMEntityReactorInfo*) {}
    virtual void OnBeginSheet(AcDMMSheetReactorInfo*) {}
    virtual void OnEndEntity(AcDMMEntityReactorInfo*) {}
    virtual void OnEndSheet(AcDMMSheetReactorInfo*) {}
};