// Copyright (C) Menhirs NV. All rights reserved.
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
