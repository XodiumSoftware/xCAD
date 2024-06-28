// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
