// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmPoint2d.h"
#include <algorithm>

namespace AModeler
{

class BM_IMPORTEXPORT Interval2d
{
public:
    static const Interval2d kNull;

    Point2d lower;
    Point2d upper;

    Interval2d();
    Interval2d(int);
    Interval2d(const Point2d&);
    Interval2d(const Point2d&,double);
    Interval2d(const Point2d&,const Point2d&);
    Interval2d(const Point2d&,const Point2d&,int);
    Interval2d(const Interval2d&);

    bool isNull() const;
    double length() const;
    double length(int) const;
    Point2d mid() const;
    void enlarge(double = 10.0*epsAbs());
    void init();

    bool operator&&(const Interval2d&) const;
    bool operator&&(const Point2d&) const;
    bool operator<=(const Interval2d&) const;
    Interval2d operator*(const Interval2d&) const;
    Interval2d operator+(const Interval2d&) const;
    void operator*=(const Interval2d&);
    void operator+=(const Interval2d&);
    void operator+=(const Point2d&);
};

inline Interval2d::Interval2d() : lower(kMaxReal, kMaxReal), upper(kMinReal, kMinReal) {};

inline Interval2d::Interval2d(int) {};

inline Interval2d::Interval2d(const Point2d& pt) : lower(pt), upper(pt) {};

inline Interval2d::Interval2d(const Point2d& pt, double d) : lower(pt), upper(pt)
{
    enlarge(d);
};

inline Interval2d::Interval2d(const Point2d& pt1, const Point2d& pt2)
{
    if (pt1.x < pt2.x) {
        lower.x = pt1.x; upper.x = pt2.x;
    } else {
        lower.x = pt2.x; upper.x = pt1.x;
    }
    if (pt1.y < pt2.y) {
        lower.y = pt1.y; upper.y = pt2.y;
    } else {
        lower.y = pt2.y; upper.y = pt1.y;
    }
};

inline Interval2d::Interval2d(const Point2d& pt1, const Point2d& pt2, int i) : lower(pt1), upper(pt2)
{
};

inline Interval2d::Interval2d(const Interval2d& other)
{
    lower = other.lower;
    upper = other.upper;
};

inline bool Interval2d::isNull() const
{
    return (lower.x == upper.x) && (lower.y == upper.y);
};

inline double Interval2d::length() const
{
    return lower.dist(upper);
};

inline double Interval2d::length(int i) const
{
    return (upper[i] - lower[i]);
};

inline Point2d Interval2d::mid() const
{
    return Point2d(0.5*(lower.x+upper.x), 0.5*(lower.y+upper.y));
};

inline void Interval2d::enlarge(double d)
{
    lower.x -= d;
    lower.y -= d;
    upper.x += d;
    upper.y += d;
};

inline void Interval2d::init()
{
    *this = kNull;
};

inline bool Interval2d::operator&&(const Interval2d& other) const
{
    if ((lower.x > other.upper.x) || (upper.x < other.lower.x) ||
        (lower.y > other.upper.y) || (upper.y < other.lower.y))
        return false;
    return true;
};

inline bool Interval2d::operator&&(const Point2d& pt) const
{
    if ((lower.x > pt.x) || (upper.x < pt.x) ||
        (lower.y > pt.y) || (upper.y < pt.y))
        return false;
    return true;
};

inline bool Interval2d::operator<=(const Interval2d& other) const
{
    if (isNull())
        return true;
    return (lower.x >= other.lower.x) && (upper.x <= other.upper.x) &&
           (lower.y >= other.lower.y) && (upper.y <= other.upper.y);
};

inline Interval2d Interval2d::operator*(const Interval2d& other) const
{
    Point2d ptLower(std::max<double>(lower.x, other.lower.x), std::max<double>(lower.y, other.lower.y));
    Point2d ptUpper(std::min<double>(upper.x, other.upper.x), std::min<double>(upper.y, other.upper.y));
    return Interval2d(ptLower, ptUpper);
};

inline Interval2d Interval2d::operator+(const Interval2d& other) const
{
    Interval2d res = *this;
    res += other;
    return res;
};

inline void Interval2d::operator*=(const Interval2d& other)
{
    lower = Point2d(std::max<double>(lower.x, other.lower.x), std::max<double>(lower.y, other.lower.y));
    upper = Point2d(std::min<double>(upper.x, other.upper.x), std::min<double>(upper.y, other.upper.y));
};

inline void Interval2d::operator+=(const Interval2d& other)
{
    lower = Point2d(std::min<double>(lower.x, other.lower.x), std::min<double>(lower.y, other.lower.y));
    upper = Point2d(std::max<double>(upper.x, other.upper.x), std::max<double>(upper.y, other.upper.y));
};

inline void Interval2d::operator+=(const Point2d& pt)
{
    lower = Point2d(std::min<double>(lower.x, pt.x), std::min<double>(lower.y, pt.y));
    upper = Point2d(std::max<double>(upper.x, pt.x), std::max<double>(upper.y, pt.y));
};


// global operator
inline bool operator &&(const Point2d& pnt, const Interval2d& other) 
{
    return (other.lower.x <= pnt.x) &&
           (other.lower.y <= pnt.y) &&
           (pnt.x <= other.upper.x) &&
           (pnt.y <= other.upper.y);
};

} // namespace AModeler
