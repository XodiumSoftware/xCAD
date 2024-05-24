// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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