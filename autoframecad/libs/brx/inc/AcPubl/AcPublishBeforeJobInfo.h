// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcPl/AcPlDSDData.h"
#include "Misc/AcNameValuePair.h"

/** _ */
class BRX_IMPORTEXPORT AcPublishBeforeJobInfo
{
public:
    AcPublishBeforeJobInfo() {}
    virtual ~AcPublishBeforeJobInfo() {}

    virtual bool JobWillPublishInBackground() = 0;
    virtual bool WritePrivateSection(const ACHAR*,const AcNameValuePairVec) = 0;
    virtual const AcNameValuePairVec GetPrivateData(const ACHAR*) = 0;
    virtual const AcPlDSDData* GetDSDData() = 0;
};