// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGs/AcGsGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcGsDCPoint
{
public:
    enum MaxFlag
    {
        Maximum = 0
    };

    enum MinFlag
    {
        Minimum = 0
    };

    long x;
    long y;

    AcGsDCPoint();
    AcGsDCPoint(MinFlag);
    AcGsDCPoint(MaxFlag);
    AcGsDCPoint(long,long);

    bool operator!=(const AcGsDCPoint&) const;
    bool operator==(const AcGsDCPoint&) const;
    void operator=(const AcGsDCPoint&);
    void operator=(MaxFlag);
    void operator=(MinFlag);
};
