// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcPl/AcPlDSDData.h"
#include "Misc/AcNameValuePair.h"

/** _ */
class BRX_IMPORTEXPORT AcPublishUIReactorInfo
{
public:
    AcPublishUIReactorInfo() {}
    virtual ~AcPublishUIReactorInfo() {}

    virtual bool JobWillPublishInBackground() = 0;
    virtual bool WritePrivateSection(const ACHAR*,const AcNameValuePairVec) = 0;
    virtual const AcNameValuePairVec GetPrivateData(const ACHAR*) = 0;
    virtual const AcPlDSDData* GetDSDData() = 0;
};