// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcEd/AcEdCommandIterator.h"

/** _ */
class BRX_IMPORTEXPORT AcEdCommandStack: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcEdCommandStack);

    virtual Acad::ErrorStatus addCommand(const ACHAR*,const ACHAR*,const ACHAR*,Adesk::Int32,AcRxFunctionPtr,AcEdUIContext* = NULL,int = -1,HINSTANCE = NULL,AcEdCommand** = NULL) = 0;
    virtual Acad::ErrorStatus popGroupToTop(const ACHAR*) = 0;
    virtual Acad::ErrorStatus removeCmd(const ACHAR*,const ACHAR*) = 0;
    virtual Acad::ErrorStatus removeGroup(const ACHAR*) = 0;
    virtual AcEdCommand* lookupCmd(const ACHAR*,bool) = 0;
    virtual AcEdCommand* lookupCmd(const ACHAR*,bool,bool) = 0;
    virtual AcEdCommand* lookupCmd(const ACHAR*,bool,bool,bool) = 0;
    virtual AcEdCommand* lookupGlobalCmd(const ACHAR*) = 0;
    virtual AcEdCommand* lookupLocalCmd(const ACHAR*) = 0;
    virtual AcEdCommandIterator* iterator() = 0;
    virtual AcEdCommand* lookupCmd2(const ACHAR*, bool, bool, int, bool = false) = 0;
};
