// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"


namespace Atil
{;

class Matrix2d;
class Vector2d;


class ATIL_IMPORTEXPORT Point2d
{
public:
    double x;
    double y;

public:
    Point2d() {}
    Point2d(int _x, int  _y) : x(_x), y(_y) {}
    Point2d(double _x, double _y) : x(_x), y(_y) {}
    ~Point2d() {}
    const Point2d& set(int _x, int  _y) { x = _x; y = _y; return *this; }
    const Point2d& set(double _x, double _y) { x = _x; y = _y; return *this; }
    Point2d& transformBy(const Matrix2d& lh);
    double distance(const Point2d& pt) const;
    Vector2d operator-(const Point2d& rh) const;
    Point2d operator+(const Vector2d& rh) const;
    Point2d& operator+=(const Vector2d& rh);
    bool operator==(const Point2d& rh) const;
    bool operator!=(const Point2d& rh) const;
};


} //namespace Atil
