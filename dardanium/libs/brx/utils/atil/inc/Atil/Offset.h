// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"


namespace Atil
{;


class ATIL_IMPORTEXPORT Offset
{
public:
    Int32 x;
    Int32 y;

    Offset() : x(0), y(0) {}
    Offset(Int32 _x, Int32 _y) : x(_x), y(_y) {}
    ~Offset() {}

    const Offset& set(Int32 _x, Int32 _y) { x = _x; y = _y; return *this; }
    Offset& operator=(const Offset& rh) { x = rh.x; y = rh.y; return *this; }
    Offset operator+(Int32 op) const { return Offset(x + op, y + op); }
    Offset& operator+=(Int32 op) { x += op; y += op; return *this; }
    Offset operator-(Int32 op) const { return Offset(x - op, y - op); }
    Offset& operator-=(Int32 op) { x -= op; y -= op; return *this; }
    Offset operator*(Int32 op) const { return Offset(x * op, y * op); }
    Offset& operator*=(Int32 op) { x *= op; y *= op; return *this; }
    Offset operator+(const Offset& rh) const { return Offset(x + rh.x, y + rh.y); }
    Offset& operator+=(const Offset& rh) { x += rh.x; y += rh.y; return *this; }
    Offset operator-(const Offset& rh) const { return Offset(x - rh.x, y - rh.y); }
    Offset& operator-=(const Offset& rh) { x -= rh.x; y -= rh.y; return *this; }
    bool operator==(const Offset& rh) const { return (x == rh.y && y == rh.y); }
    bool operator!=(const Offset& rh) const { return (x != rh.y || y != rh.y); }
};


} //namespace Atil
