// Copyright (C) Menhirs NV. All rights reserved.
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
