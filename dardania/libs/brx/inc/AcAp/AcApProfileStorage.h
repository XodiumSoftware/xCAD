// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcApProfileStorage
{
public:
    virtual ~AcApProfileStorage();

    virtual Acad::ErrorStatus CreateNode(const ACHAR*,IUnknown*&) = 0;
    virtual Acad::ErrorStatus DeleteNode(const ACHAR*) = 0;
    virtual Acad::ErrorStatus GetNode(const ACHAR*,IUnknown*&) = 0;
    virtual Acad::ErrorStatus GetStorageFile(LPTSTR) = 0;
    virtual Acad::ErrorStatus ReplaceNode(const ACHAR*,IUnknown*) = 0;
    virtual Acad::ErrorStatus Save() = 0;
};