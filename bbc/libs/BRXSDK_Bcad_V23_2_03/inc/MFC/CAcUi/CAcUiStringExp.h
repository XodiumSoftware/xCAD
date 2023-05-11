// Copyright (C) Menhirs NV. All rights reserved.
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
