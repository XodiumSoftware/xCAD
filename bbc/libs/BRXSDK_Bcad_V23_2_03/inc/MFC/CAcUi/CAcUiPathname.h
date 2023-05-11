// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiPathname.h"

class AFILE;

/** _ */
class BRX_IMPORTEXPORT CAcUiPathname: public CAdUiPathname
{
public:
    virtual ~CAcUiPathname();
    virtual PathErr Parse(LPCTSTR,const BOOL = FALSE);
    BOOL Open(AFILE**,const ACHAR*);
    CAcUiPathname();
    CAcUiPathname(const CAcUiPathname&);
    const CAcUiPathname& operator=(const CAcUiPathname&);
    const CAcUiPathname& operator=(const CAcUiPathname*);
    int Status();
protected:
    virtual void AssignCopy(const CAcUiPathname&);
};
