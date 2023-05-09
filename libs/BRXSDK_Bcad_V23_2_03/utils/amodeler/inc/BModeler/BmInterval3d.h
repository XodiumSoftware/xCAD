// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmPoint3d.h"
#include "BmVector3d.h"
#include "BmInterval3d.h"
#include "BmInterval2d.h"
#include "BmPlane.h"
#include "BmLine3d.h"
#include <algorithm>

namespace AModeler
{

class BM_IMPORTEXPORT Interval3d
{
public:
    static const Interval3d kNull;

    Point3d lower;
    Point3d upper;

    Interval3d();
    Interval3d(int);
    Interval3d(const Point3d&);
    Interval3d(const Point3d&,double);
    Interval3d(const Point3d&,const Point3d&);
    Interval3d(const Point3d&,const Point3d&,int);
    Interval3d(const Interval3d&);

    bool intersectsPlane(const Plane&) const;
    bool isNull() const;
    double length() const;
    double length(int) const;
    Interval2d toInterval2d(int) const;
    Point3d lowerInDirection(const Vector3d&) const;
    Point3d mid() const;
    Point3d upperInDirection(const Vector3d&) const;
    void enlarge(double = 10.0*epsAbs());
    void init();

    bool operator&&(const Interval3d&) const;
    bool operator&&(const Point3d&) const;
    bool operator<=(const Interval3d&) const;
    Interval3d operator*(const Line3d&) const;
    Interval3d operator*(const Interval3d&) const;
    Interval3d operator+(const Interval3d&) const;
    void operator*=(const Interval3d&);
    void operator+=(const Interval3d&);
    void operator+=(const Point3d&);
};

inline Interval3d::Interval3d() : lower(kMaxReal, kMaxReal, kMaxReal), upper(kMinReal, kMinReal, kMinReal) {};

inline Interval3d::Interval3d(int) {};

inline Interval3d::Interval3d(const Point3d& pt) : lower(pt), upper(pt) {};

inline Interval3d::Interval3d(const Point3d& pt, double d)
    : lower(pt), upper(pt)
{
    enlarge(d);
};

inline Interval3d::Interval3d(const Point3d& pt1, const Point3d& pt2)
{
    if (pt1.x < pt2.x)
         { lower.x = pt1.x; upper.x = pt2.x; }
    else { lower.x = pt2.x; upper.x = pt1.x; }

    if (pt1.y < pt2.y)
         { lower.y = pt1.y; upper.y = pt2.y; }
    else { lower.y = pt2.y; upper.y = pt1.y; }

    if (pt1.z < pt2.z)
         { lower.z = pt1.z; upper.z = pt2.z; }
    else { lower.z = pt2.z; upper.z = pt1.z; }
};

inline Interval3d::Interval3d(const Point3d& pt1, const Point3d& pt2, int)
    : lower(pt1), upper(pt2)
{
};

inline Interval3d::Interval3d(const Interval3d& other)
{
    lower = other.lower;
    upper = other.upper;
}

inline bool Interval3d::intersectsPlane(const Plane& plane) const
{
    if (plane.dist(lowerInDirection(plane.normal)) > epsAbs())
        return false;
    if (plane.dist(upperInDirection(plane.normal)) < -epsAbs())
        return false;
    return true;
};

inline bool Interval3d::isNull() const
{
    return (lower.x == upper.x) && (lower.y == upper.y);
};

inline double Interval3d::length() const
{
    return lower.dist(upper);
};

inline double Interval3d::length(int i) const
{
    return upper[i] - lower[i];
};

inline Point2d toPoint2d(const Point3d& pt, int i)
{
    if (i == 0)
        return Point2d(pt.y, pt.z);
    if (i == 1)
        return Point2d(pt.z, pt.x);
    return Point2d(pt.x, pt.y);
};

inline Interval2d Interval3d::toInterval2d(int i) const
{
    return Interval2d(toPoint2d(lower, i), toPoint2d(upper, i));
};

inline double select_lower_direction(double d, double a1, double a2)
{
    return (d >= 0.0) ? a1 : a2;
};

inline Point3d Interval3d::lowerInDirection(const Vector3d& d) const
{
    return Point3d(select_lower_direction(d.x, lower.x, upper.x),
                   select_lower_direction(d.y, lower.y, upper.y),
                   select_lower_direction(d.z, lower.z, upper.z));
};

inline Point3d Interval3d::mid() const
{
    return Point3d(0.5*(lower.x+upper.x), 0.5*(lower.y+upper.y), 0.5*(lower.z+upper.z));
};

inline Point3d Interval3d::upperInDirection(const Vector3d& d) const
{
    return Point3d(select_lower_direction(d.x, upper.x, lower.x),
                   select_lower_direction(d.y, upper.y, lower.y),
                   select_lower_direction(d.z, upper.z, lower.z));
};

inline void Interval3d::enlarge(double d)
{
    lower.x -= d;
    lower.y -= d;
    lower.z -= d;
    upper.x += d;
    upper.y += d;
    upper.z += d;
};

inline void Interval3d::init()
{
    *this = kNull;
};

inline bool Interval3d::operator&&(const Interval3d& other) const
{
    if ((lower.x > other.upper.x) || (upper.x < other.lower.x) || (lower.y > other.upper.y) ||
        (upper.y < other.lower.y) || (lower.z > other.upper.z) || (upper.z < other.lower.z))
        return false;
    return true;
};

inline bool Interval3d::operator&&(const Point3d& pt) const
{
    if ((lower.x > pt.x) || (upper.x < pt.x) || (lower.y > pt.y) ||
        (upper.y < pt.y) || (lower.z > pt.z) || (upper.z < pt.z))
        return false;
    return true;
};

inline bool Interval3d::operator<=(const Interval3d& other) const
{
    if (isNull())
        return true;
    return (lower.x >= other.lower.x) && (upper.x <= other.upper.x) &&
           (lower.y >= other.lower.y) && (upper.y <= other.upper.y) &&
           (lower.z >= other.lower.z) && (upper.z <= other.upper.z);
};

inline Interval3d Interval3d::operator*(const Interval3d& other) const
{
    Point3d ptLower(std::max<double>(lower.x, other.lower.x), 
                    std::max<double>(lower.y, other.lower.y), 
                    std::max<double>(lower.z, other.lower.z));
    Point3d ptUpper(std::min<double>(upper.x, other.upper.x), 
                    std::min<double>(upper.y, other.upper.y), 
                    std::min<double>(upper.z, other.upper.z));
    return Interval3d(ptLower, ptUpper);
};

inline Interval3d Interval3d::operator*(const Line3d& line) const
{
    Interval3d other(line.point, line.point+line.vector);
    return operator*(other);
};

inline Interval3d Interval3d::operator+(const Interval3d& other) const
{
    Interval3d res = *this;
    res += other;
    return res;
};

inline void Interval3d::operator*=(const Interval3d& other)
{
    lower = Point3d(std::max<double>(lower.x, other.lower.x), 
                    std::max<double>(lower.y, other.lower.y), 
                    std::max<double>(lower.z, other.lower.z));
    upper = Point3d(std::min<double>(upper.x, other.upper.x), 
                    std::min<double>(upper.y, other.upper.y), 
                    std::min<double>(upper.z, other.upper.z));
};

inline void Interval3d::operator+=(const Interval3d& other)
{
    lower = Point3d(std::min<double>(lower.x, other.lower.x), 
                    std::min<double>(lower.y, other.lower.y), 
                    std::min<double>(lower.z, other.lower.z));
    upper = Point3d(std::max<double>(upper.x, other.upper.x), 
                    std::max<double>(upper.y, other.upper.y), 
                    std::max<double>(upper.z, other.upper.z));
};

inline void Interval3d::operator+=(const Point3d& pt)
{
    lower = Point3d(std::min<double>(lower.x, pt.x), 
                    std::min<double>(lower.y, pt.y), 
                    std::min<double>(lower.z, pt.z));
    upper = Point3d(std::max<double>(upper.x, pt.x), 
                    std::max<double>(upper.y, pt.y), 
                    std::max<double>(upper.z, pt.z));
};


// global operator
inline bool operator &&(const Point3d& pnt, const Interval3d& other) 
{
    return (other.lower.x <= pnt.x) &&
           (other.lower.y <= pnt.y) &&
           (other.lower.z <= pnt.z) &&
           (pnt.x <= other.upper.x) &&
           (pnt.y <= other.upper.y) &&
           (pnt.z <= other.upper.z);
};

} // namespace AModeler
