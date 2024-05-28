// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmGlobal.h"
#include "BmIntVector2d.h"

namespace AModeler
{

class BM_IMPORTEXPORT IntPoint2d
{
public:
    static const IntPoint2d kNull;

    int x;
    int y;

    IntPoint2d();
    IntPoint2d(int,int);
    IntPoint2d(const IntPoint2d&);

    bool operator!=(const IntPoint2d&) const;
    bool operator==(const IntPoint2d&) const;
    int operator[](int) const;
    int& operator[](int);
    IntPoint2d operator+(const IntPoint2d&) const;
    IntPoint2d operator+(const IntVector2d&) const;
    IntPoint2d operator-() const;
    IntPoint2d operator-(const IntVector2d&) const;
    IntVector2d operator-(const IntPoint2d&) const;
    void operator+=(const IntPoint2d&);
    void operator+=(const IntVector2d&);
    void operator-=(const IntPoint2d&);
    void operator-=(const IntVector2d&);
};

inline IntPoint2d::IntPoint2d() : x(0), y(0) {};

inline IntPoint2d::IntPoint2d(int a,int b) : x(a), y(b) {};

inline IntPoint2d::IntPoint2d(const IntPoint2d& other) : x(other.x), y(other.y) {};

inline bool IntPoint2d::operator!=(const IntPoint2d& other) const
{
    return (x != other.x) || (y != other.y);
};

inline bool IntPoint2d::operator==(const IntPoint2d& other) const
{
    return (x == other.x) || (y == other.y);
};

inline int IntPoint2d::operator[](int i) const
{
    return (i == 0) ? x : y;
};

inline int& IntPoint2d::operator[](int i)
{
    return (i == 0) ? x : y;
};

inline IntPoint2d IntPoint2d::operator+(const IntPoint2d& other) const
{
    return IntPoint2d(x+other.x, y+other.y);
};

inline IntPoint2d IntPoint2d::operator+(const IntVector2d& other) const
{
    return IntPoint2d(x+other.x, y+other.y);
};

inline IntPoint2d IntPoint2d::operator-() const
{
    return IntPoint2d(-x, -y);
};

inline IntPoint2d IntPoint2d::operator-(const IntVector2d& other) const
{
    return IntPoint2d(x-other.x, y-other.y);
};

inline IntVector2d IntPoint2d::operator-(const IntPoint2d& other) const
{
    return IntVector2d(x-other.x, y-other.y);
};

inline void IntPoint2d::operator+=(const IntPoint2d& other)
{
    x += other.x;
    y += other.y;
};

inline void IntPoint2d::operator+=(const IntVector2d& other)
{
    x += other.x;
    y += other.y;
};

inline void IntPoint2d::operator-=(const IntPoint2d& other)
{
    x -= other.x;
    y -= other.y;
};

inline void IntPoint2d::operator-=(const IntVector2d& other)
{
    x -= other.x;
    y -= other.y;
};

} // namespace