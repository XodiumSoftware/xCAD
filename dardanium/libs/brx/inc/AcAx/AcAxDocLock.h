// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcAxDocLock
{
//BRX START
private:
    void* m_pBrxImp;
//BRX END

public:
    enum DocLockType
    {
        kNormal = 0,
        kCurDocSwitch
    };

    AcAxDocLock();
    AcAxDocLock(AcDbDatabase*,DocLockType = kNormal);
    AcAxDocLock(const AcDbObjectId&,DocLockType = kNormal);
    ~AcAxDocLock();

    Acad::ErrorStatus lockStatus() const;
};
