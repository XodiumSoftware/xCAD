// Copyright (C) Menhirs NV. All rights reserved.
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
