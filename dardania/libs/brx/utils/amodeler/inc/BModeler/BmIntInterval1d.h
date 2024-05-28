// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmGlobal.h"
#include <algorithm>

namespace AModeler
{

class BM_IMPORTEXPORT IntInterval1d
{
public:
    static const IntInterval1d kNull;

    int lower;
    int upper;

    IntInterval1d();
    IntInterval1d(int);
    IntInterval1d(int,int);
    IntInterval1d(int,int,int);
    IntInterval1d(const IntInterval1d&);

    bool isNull() const;
    int length() const;
    int mid() const;
    void enlarge(int = 1);
    void init();

    bool operator&&(int) const;
    bool operator&&(const IntInterval1d&) const;
    bool operator<=(const IntInterval1d&) const;
    IntInterval1d operator*(const IntInterval1d&) const;
    IntInterval1d operator+(const IntInterval1d&) const;
    void operator*=(const IntInterval1d&);
    void operator+=(int);
    void operator+=(const IntInterval1d&);
};


inline IntInterval1d::IntInterval1d() : lower(INT_MAX), upper(INT_MIN) {};

inline IntInterval1d::IntInterval1d(int d) : lower (d), upper(d) {};

inline IntInterval1d::IntInterval1d(int i1,int i2) : lower (i1), upper(i2) {};

inline IntInterval1d::IntInterval1d(int i1,int i2,int) : lower (i1), upper(i2) {};

inline IntInterval1d::IntInterval1d(const IntInterval1d& other)
{
    lower = other.lower;
    upper = other.upper;
};

inline bool IntInterval1d::isNull() const
{
    return length() <= 0;
};

inline int IntInterval1d::length() const
{
    return upper-lower;
};

inline int IntInterval1d::mid() const
{
    return (int)((upper+lower)*0.5);
};

inline void IntInterval1d::enlarge(int i)
{
    lower-=i;
    upper+=i;
};

inline void IntInterval1d::init()
{
    *this = kNull;
};

inline bool IntInterval1d::operator&&(int i) const
{
    return (lower <= i) && (i <= upper);
};

inline bool IntInterval1d::operator&&(const IntInterval1d& other) const
{
    return (lower <= other.upper) && (upper >= other.lower);
};

inline bool IntInterval1d::operator<=(const IntInterval1d& other) const
{
    return isNull() ? true : (lower >= other.lower) && (upper <= other.upper);
};

inline IntInterval1d IntInterval1d::operator*(const IntInterval1d& other) const
{
    return IntInterval1d(std::max<int>(lower, other.lower), std::min<int>(upper, other.upper));
};

inline IntInterval1d IntInterval1d::operator+(const IntInterval1d& other) const
{
    IntInterval1d res = *this;
    res += other;
    return res;
};

inline void IntInterval1d::operator*=(const IntInterval1d& other)
{
    if (lower < other.lower) lower = other.lower;
    if (upper > other.upper) upper = other.upper;
};

inline void IntInterval1d::operator+=(int i)
{
    if (lower > i)
        lower = i;
    if (upper < i)
        upper = i;
};

inline void IntInterval1d::operator+=(const IntInterval1d& other)
{
    if (lower > other.lower)
        lower = other.lower;
    if (upper < other.upper)
        upper = other.upper;
};


// global operator
inline bool operator &&(int delta, const IntInterval1d& other) 
{
    return (other.lower <= delta) && (delta <= other.upper);
};

} // namespace AModeler
