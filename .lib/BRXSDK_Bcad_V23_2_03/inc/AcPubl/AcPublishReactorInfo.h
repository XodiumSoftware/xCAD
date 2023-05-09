// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcPublishReactorInfo
{
public:
    AcPublishReactorInfo() {}
    virtual ~AcPublishReactorInfo() {}

    virtual bool isMultiSheetDwf() = 0;
    virtual const ACHAR* dwfFileName() = 0;
    virtual const ACHAR* dwfPassword() = 0;
    virtual const ACHAR* tempDwfFileName() = 0;
};