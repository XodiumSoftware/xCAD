// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiString.h"

/** _ */
class CAcUiStringExp: public CAcUiString
{
public:
    CAcUiStringExp();
    CAcUiStringExp(ACHAR,int = 1);
    CAcUiStringExp(const CString&);
    CAcUiStringExp(LPCTSTR);
    CAcUiStringExp(LPCTSTR,int);
    CAcUiStringExp(UINT);
    virtual BOOL LoadString(UINT);
    void ReplaceProductMacroStrings();
};
