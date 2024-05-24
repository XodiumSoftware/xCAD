// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmGlobal.h"
#include <algorithm>

namespace AModeler
{

class BM_IMPORTEXPORT Interval1d
{
public:
    static const Interval1d kNull;

    double lower;
    double upper;

    Interval1d();
    Interval1d(double);
    Interval1d(double,double);
    Interval1d(double,double,int);
    Interval1d(const Interval1d&);

    bool isNull() const;
    double length() const;
    double mid() const;
    void enlarge(double = 10.0*epsAbs());
    void init();

    bool operator&&(const Interval1d&) const;
    bool operator&&(double) const;
    bool operator<=(const Interval1d&) const;
    Interval1d operator*(const Interval1d&) const;
    Interval1d operator+(const Interval1d&) const;
    void operator*=(const Interval1d&);
    void operator+=(const Interval1d&);
    void operator+=(double);
};


inline Interval1d::Interval1d () : lower(kMaxReal), upper(kMinReal) {};

inline Interval1d::Interval1d (double d) : lower(d), upper(d) {};

inline Interval1d::Interval1d (double d1, double d2) : lower(d1), upper(d2)
{
    if  (d1 > d2)
        std::swap(lower, upper);
};

inline Interval1d::Interval1d (double d1, double d2, int) : lower(d1), upper(d2)
{
};

inline Interval1d::Interval1d (const Interval1d& other)
{
    this->lower = other.lower;
    this->upper = other.upper;
};

inline bool Interval1d::isNull () const
{
    return length() <= 0.0;
};

inline double Interval1d::length () const
{
    return upper-lower;
};

inline double Interval1d::mid () const
{
    return (upper+lower) / 2.0;
};

inline void Interval1d::enlarge (double eps)
{
    lower -= eps;
    upper += eps;
};

inline void Interval1d::init ()
{
    *this = kNull;
};

inline bool Interval1d::operator&& (const Interval1d& other) const
{
    return (lower <= other.upper) && (upper >= other.lower);
};

inline bool Interval1d::operator&& (double d) const
{
    return (lower <= d) && (d <= upper);
};

inline bool Interval1d::operator<= (const Interval1d& other) const
{
    return isNull() ? true : (lower >= other.lower) && (upper <= other.upper);
};

inline Interval1d Interval1d::operator* (const Interval1d& other) const
{
    return Interval1d(std::max<double>(lower, other.lower), std::min<double>(upper, other.upper));
};

inline Interval1d Interval1d::operator+ (const Interval1d& other) const
{
    Interval1d res(*this);
    res += other;
    return res;
};

inline void Interval1d::operator*= (const Interval1d& other)
{
    if (other.lower > lower) lower = other.lower;
    if (other.upper < upper) upper = other.upper;
};

inline void Interval1d::operator+= (const Interval1d& other)
{
    if (other.lower < lower) lower = other.lower;
    if (other.upper > upper) upper = other.upper;
};

inline void Interval1d::operator+= (double d)
{
    if (d < lower) lower = d;
    if (d > upper) upper = d;
};


// global operator
inline bool operator &&(double delta, const Interval1d& other) 
{
    return (other.lower <= delta) && (delta <= other.upper);
};

} // namespace AModeler
