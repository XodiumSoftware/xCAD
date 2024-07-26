// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include <vector>
#include <tchar.h>

#include "Misc/MiscGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcNameValuePair
{
public:
    AcNameValuePair();
    AcNameValuePair(const ACHAR*,const ACHAR*);
    AcNameValuePair(const AcNameValuePair&);
    ~AcNameValuePair();

    const ACHAR* name();
    const ACHAR* value();
    void setName(const ACHAR*);
    void setValue(const ACHAR*);

    AcNameValuePair& operator=(const AcNameValuePair&);
};

typedef AcArray<AcNameValuePair> AcNameValuePairVec;
