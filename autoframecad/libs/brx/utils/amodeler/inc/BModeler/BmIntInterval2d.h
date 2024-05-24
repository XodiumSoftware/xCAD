// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmIntPoint2d.h"
#include "BmInterval2d.h"
#include "BmIntInterval1d.h"
#include <algorithm>

namespace AModeler
{

class BM_IMPORTEXPORT IntInterval2d
{
public:
    static const IntInterval2d kNull;

    IntPoint2d lower;
    IntPoint2d upper;

    IntInterval2d();
    IntInterval2d(const IntPoint2d&);
    IntInterval2d(const IntPoint2d&,const IntPoint2d&);
    IntInterval2d(const IntPoint2d&,const IntPoint2d&,int);

    bool isNull() const;
    int length(int) const;
    IntInterval1d project(int) const;
    IntPoint2d mid() const;
    void enlarge(int = 1);
    void init();

    bool operator&&(const IntInterval2d&) const;
    bool operator&&(const IntPoint2d&) const;
    bool operator<=(const Interval2d&) const;
    IntInterval2d operator*(const IntInterval2d&) const;
    IntInterval2d operator+(const IntInterval2d&) const;
    void operator*=(const IntInterval2d&);
    void operator+=(const IntInterval2d&);
    void operator+=(const IntPoint2d&);
};

inline IntInterval2d::IntInterval2d() : lower(INT_MAX, INT_MAX), upper(INT_MIN, INT_MIN) {};

inline IntInterval2d::IntInterval2d(const IntPoint2d& other) : lower(other), upper(other) {};

inline IntInterval2d::IntInterval2d(const IntPoint2d& p1, const IntPoint2d& p2)
{
    if (p1.x < p2.x)
    {
        lower.x = p1.x;
        upper.x = p2.x;
    }
    else
    {
        lower.x = p2.x;
        upper.x = p1.x;
    }

    if (p1.y < p2.y)
    {
        lower.y = p1.y;
        upper.y = p2.y;
    }
    else
    {
        lower.y = p2.y;
        upper.y = p1.y;
    }
};

inline IntInterval2d::IntInterval2d(const IntPoint2d& p1, const IntPoint2d& p2, int) : lower(p1), upper(p2) {};

inline int IntInterval2d::length(int idx) const
{
    return (idx == 0 || idx == 1) ? (upper[idx] - lower[idx]) : 0;
};

inline bool IntInterval2d::isNull() const
{
    return (lower.x > upper.x) || (lower.y > upper.y);
};

inline IntInterval1d IntInterval2d::project(int idx) const
{
    return (idx == 0 || idx == 1) ? IntInterval1d(lower[idx], upper[idx]) : IntInterval1d::kNull;
};

inline IntPoint2d IntInterval2d::mid() const
{
    return IntPoint2d((upper.x+lower.x)/2, (upper.y+lower.y)/2);
};

inline void IntInterval2d::enlarge(int amount)
{
    upper.x += amount; upper.y += amount;
    lower.x -= amount; lower.y -= amount;
};

inline void IntInterval2d::init()
{
    *this = kNull;
};

inline bool IntInterval2d::operator&&(const IntInterval2d& other) const
{
    return (lower.x <= other.upper.x) &&
           (upper.x >= other.lower.x) &&
           (lower.y <= other.upper.y) &&
           (upper.y >= other.lower.y);
};

inline bool IntInterval2d::operator&&(const IntPoint2d& pnt) const
{
    return (lower.x <= pnt.x) &&
           (upper.x >  pnt.x) &&
           (lower.y <= pnt.y) &&
           (upper.y >  pnt.y);
};

inline bool IntInterval2d::operator<=(const Interval2d& other) const
{
    if (isNull())
        return true;

    return (lower.x >= other.lower.x) &&
           (upper.x <= other.upper.x) &&
           (lower.y >= other.lower.y) &&
           (upper.y <= other.upper.y);
};

inline IntInterval2d IntInterval2d::operator*(const IntInterval2d& other) const
{
    IntInterval2d tmp;
    tmp.lower.x = std::max<int>(lower.x, other.lower.x);
    tmp.lower.y = std::max<int>(lower.y, other.lower.y);
    tmp.upper.x = std::min<int>(upper.x, other.upper.x);
    tmp.upper.y = std::min<int>(upper.y, other.upper.y);
    return tmp;
};

inline IntInterval2d IntInterval2d::operator+(const IntInterval2d& other) const
{
    IntInterval2d tmp = *this;
    tmp += other;
    return tmp;
};

inline void IntInterval2d::operator*=(const IntInterval2d& other)
{
    if (other.lower.x > lower.x) lower.x = other.lower.x;
    if (other.lower.y > lower.y) lower.y = other.lower.y;
    if (other.upper.x < upper.x) upper.x = other.upper.x;
    if (other.upper.y < upper.y) upper.y = other.upper.y;
};

inline void IntInterval2d::operator+=(const IntInterval2d& other)
{
    if (other.lower.x < lower.x) lower.x = other.lower.x;
    if (other.lower.y < lower.y) lower.y = other.lower.y;
    if (other.upper.x > upper.x) upper.x = other.upper.x;
    if (other.upper.y > upper.y) upper.y = other.upper.y;
};

inline void IntInterval2d::operator+=(const IntPoint2d& pnt)
{
    if (pnt.x < lower.x) lower.x = pnt.x;
    if (pnt.y < lower.y) lower.y = pnt.y;
    if (pnt.x > upper.x) upper.x = pnt.x;
    if (pnt.y > upper.y) upper.y = pnt.y;
};


// global operator
inline bool operator &&(const IntPoint2d& pnt, const IntInterval2d& other) 
{
    return (other.lower.x <= pnt.x) &&
           (other.lower.y <= pnt.y) &&
           (pnt.x <= other.upper.x) &&
           (pnt.y <= other.upper.y);
};

} // namespace AModeler
