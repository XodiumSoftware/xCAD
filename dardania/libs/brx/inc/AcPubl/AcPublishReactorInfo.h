// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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