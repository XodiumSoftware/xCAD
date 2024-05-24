// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmIntPoint3d.h"
#include "BmIntInterval1d.h"

namespace AModeler
{

class BM_IMPORTEXPORT IntInterval3d
{
public:
    static const IntInterval3d kNull;

    IntPoint3d lower;
    IntPoint3d upper;

    IntInterval3d();
    IntInterval3d(const IntPoint3d&);
    IntInterval3d(const IntPoint3d&, const IntPoint3d&);
    IntInterval3d(const IntPoint3d&, const IntPoint3d&, int);

    IntInterval1d project(int) const;
    int length(int) const;
    bool isNull() const;
    IntPoint3d mid() const;
    void enlarge(int = 1);
    void init();

    bool operator&&(const IntInterval3d&) const;
    bool operator&&(const IntPoint3d&) const;
    bool operator<=(const IntInterval3d&) const;
    IntInterval3d operator*(const IntInterval3d&) const;
    IntInterval3d operator+(const IntInterval3d&) const;
    void operator*=(const IntInterval3d&);
    void operator+=(const IntInterval3d&);
    void operator+=(const IntPoint3d&);
};

inline IntInterval3d::IntInterval3d() : lower(INT_MAX, INT_MAX, INT_MAX), upper(INT_MIN, INT_MIN, INT_MIN) {};

inline IntInterval3d::IntInterval3d(const IntPoint3d& pnt) : lower(pnt), upper(pnt) {};

inline IntInterval3d::IntInterval3d(const IntPoint3d& p1, const IntPoint3d& p2)
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

    if (p1.z < p2.z)
    {
        lower.z = p1.z;
        upper.z = p2.z;
    }
    else
    {
        lower.z = p2.z;
        upper.z = p1.z;
    }
};

inline IntInterval3d::IntInterval3d(const IntPoint3d& p1, const IntPoint3d& p2, int) : lower(p1), upper(p2) {};

inline IntInterval1d IntInterval3d::project(int idx) const
{
    return (idx >= 0 && idx <= 2) ? IntInterval1d(lower[idx], upper[idx]) : IntInterval1d::kNull;
};

inline int IntInterval3d::length(int idx) const
{
    return (idx >= 0 && idx <= 2) ? (upper[idx] - lower[idx]) : 0;
};

inline bool IntInterval3d::isNull() const
{
    return (lower.x > upper.x) ||
           (lower.y > upper.y) ||
           (lower.z > upper.z);
};

inline IntPoint3d IntInterval3d::mid() const
{
    return IntPoint3d((upper.x+lower.x)/2, (upper.y+lower.y)/2, (upper.z+lower.z)/2);
};

inline void IntInterval3d::enlarge(int amount)
{
    lower.x -= amount;
    lower.y -= amount;
    lower.z -= amount;

    upper.x += amount;
    upper.y += amount;
    upper.z += amount;
};

inline void IntInterval3d::init()
{
    *this = kNull;
};

inline bool IntInterval3d::operator&&(const IntInterval3d& other) const
{
    return (lower.x <= other.upper.x) && (upper.x >= other.lower.x) &&
           (lower.y <= other.upper.y) && (upper.y >= other.lower.y) &&
           (lower.z <= other.upper.z) && (upper.z >= other.lower.z);
};

inline bool IntInterval3d::operator&&(const IntPoint3d& pnt) const
{
    return (lower.x <= pnt.x) && (pnt.x <= upper.x) &&
           (lower.y <= pnt.y) && (pnt.y <= upper.y) &&
           (lower.z <= pnt.z) && (pnt.z <= upper.z);
};

inline bool IntInterval3d::operator<=(const IntInterval3d& other) const
{
    if (isNull())
        return true;

    return (lower.x >= other.lower.x) && (upper.x <= other.upper.x) &&
           (lower.y >= other.lower.y) && (upper.y <= other.upper.y) &&
           (lower.z >= other.lower.z) && (upper.z <= other.upper.z);
};

inline IntInterval3d IntInterval3d::operator*(const IntInterval3d& other) const
{
    IntInterval3d tmp;

    tmp.lower.x = std::max<int>(lower.x, other.lower.x);
    tmp.lower.y = std::max<int>(lower.y, other.lower.y);
    tmp.lower.z = std::max<int>(lower.z, other.lower.z);

    tmp.upper.x = std::min<int>(upper.x, other.upper.x);
    tmp.upper.y = std::min<int>(upper.y, other.upper.y);
    tmp.upper.z = std::min<int>(upper.z, other.upper.z);

    return tmp;
};

inline IntInterval3d IntInterval3d::operator+(const IntInterval3d& other) const
{
    IntInterval3d tmp = *this;
    tmp += other;
    return tmp;
};

inline void IntInterval3d::operator*=(const IntInterval3d& other)
{
    if (other.lower.x > lower.x) lower.x = other.lower.x;
    if (other.lower.y > lower.y) lower.y = other.lower.y;
    if (other.lower.z > lower.z) lower.z = other.lower.z;

    if (other.upper.x < upper.x) upper.x = other.upper.x;
    if (other.upper.y < upper.y) upper.y = other.upper.y;
    if (other.upper.z < upper.z) upper.z = other.upper.z;
};

inline void IntInterval3d::operator+=(const IntInterval3d& other)
{
    if (other.lower.x < lower.x) lower.x = other.lower.x;
    if (other.lower.y < lower.y) lower.y = other.lower.y;
    if (other.lower.z < lower.z) lower.z = other.lower.z;

    if (other.upper.x > upper.x) upper.x = other.upper.x;
    if (other.upper.y > upper.y) upper.y = other.upper.y;
    if (other.upper.z > upper.z) upper.z = other.upper.z;
};

inline void IntInterval3d::operator+=(const IntPoint3d& pnt)
{
    if (pnt.x < lower.x) lower.x = pnt.x;
    if (pnt.y < lower.y) lower.y = pnt.y;
    if (pnt.z < lower.z) lower.z = pnt.z;

    if (pnt.x > upper.x) upper.x = pnt.x;
    if (pnt.y > upper.y) upper.y = pnt.y;
    if (pnt.z > upper.z) upper.z = pnt.z;
};


// global operator
inline bool operator &&(const IntPoint3d& pnt, const IntInterval3d& other) 
{
    return (other.lower.x <= pnt.x) &&
           (other.lower.y <= pnt.y) &&
           (other.lower.z <= pnt.z) &&
           (pnt.x <= other.upper.x) &&
           (pnt.y <= other.upper.y) &&
           (pnt.z <= other.upper.z);
};

} // namespace AModeler
