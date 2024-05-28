// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmGlobal.h"
#include "BmVector2d.h"

class AcGePoint2d;

namespace AModeler
{

class BM_IMPORTEXPORT Point2d
{
public:
    static const Point2d kNull;

    double x;
    double y;

    Point2d();
    Point2d(const AcGePoint2d&);
    Point2d(double,double);

    bool isEqual(const Point2d&,double = epsAbsSqrd()) const;
    bool isEqualRect(const Point2d&,double = epsAbs()) const;
    bool isValid() const;
    double dist(const Point2d&) const;
    double distRect(const Point2d&) const;
    double distSqrd(const Point2d&) const;
    double length() const;
    double lengthRect() const;
    double lengthSqrd() const;
    const Vector2d& asVector() const;
    Vector2d toVector2d() const;

    double operator%(const Vector2d&) const;
    double operator[](int) const;
    double& operator[](int);
    operator AcGePoint2d&();
    operator const AcGePoint2d&() const;
    Point2d operator*(double) const;
    Point2d operator+(const Point2d&) const;
    Point2d operator+(const Vector2d&) const;
    Point2d operator-() const;
    Point2d operator-(const Vector2d&) const;
    Point2d operator/(double) const;
    Vector2d operator-(const Point2d&) const;
    void operator*=(double);
    void operator+=(const Point2d&);
    void operator+=(const Vector2d&);
    void operator-=(const Point2d&);
    void operator-=(const Vector2d&);
    void operator/=(double);

    static Point2d& cast(AcGePoint2d&);
};

inline Point2d::Point2d() : x(0.0), y(0.0) {};

inline Point2d::Point2d(double ptX, double ptY) : x(ptX), y(ptY) {};

inline Point2d Point2d::operator+(const Point2d& pt) const
{
    return Point2d(x + pt.x, y + pt.y);
};

inline Point2d Point2d::operator+(const Vector2d& vec) const
{
    return Point2d(x + vec.x, y + vec.y);
};

inline Vector2d Point2d::operator-(const Point2d& pt) const
{
    return Vector2d(x - pt.x, y - pt.y);
};

inline Point2d Point2d::operator-(const Vector2d& vec) const
{
    return Point2d(x - vec.x, y - vec.y);
};

inline Point2d Point2d::operator-() const
{
    return Point2d(-x, -y);
};

inline Point2d Point2d::operator*(double scale) const
{
    return Point2d(x*scale, y*scale);
};

inline Point2d Point2d::operator/(double scale) const
{
    return Point2d(x/scale, y/scale);
};

inline void Point2d::operator+=(const Point2d& pt)
{
    x += pt.x;
    y += pt.y;
};

inline void Point2d::operator+=(const Vector2d& vec)
{
    x += vec.x;
    y += vec.y;
};

inline void Point2d::operator-=(const Point2d& pt)
{
    x -= pt.x;
    y -= pt.y;
};

inline void Point2d::operator-=(const Vector2d& vec)
{
    x -= vec.x;
    y -= vec.y;
};

inline void Point2d::operator*=(double scale)
{
    x *= scale;
    y *= scale;
};

inline void Point2d::operator/=(double scale)
{
    x /= scale;
    y /= scale;
};

inline double Point2d::operator%(const Vector2d& vec) const
{
    return (x*vec.x + y*vec.y);
};

inline double Point2d::length() const
{
    return sqrt(lengthSqrd());
};

inline double Point2d::lengthSqrd() const
{
    return (x*x + y*y);
};

inline double Point2d::lengthRect() const
{
    return (fabs(x) + fabs(y));
};

inline double Point2d::dist(const Point2d& pt) const
{
    return (*this - pt).length();
};

inline double Point2d::distSqrd(const Point2d& pt) const
{
    return (*this - pt).lengthSqrd();
};

inline double Point2d::distRect(const Point2d& pt) const
{
    return (*this - pt).lengthRect();
}

inline bool Point2d::isEqual(const Point2d& pt, double tolSqr) const
{
    return (distSqrd(pt) <= tolSqr);
};

inline bool Point2d::isEqualRect(const Point2d& pt, double tolRect) const
{
    return (distRect(pt) <= tolRect);
};

inline bool Point2d::isValid() const
{
    return (fabs(x) < kMaxReal && fabs(y) < kMaxReal);
};

inline const Vector2d& Point2d::asVector() const
{
    return *reinterpret_cast<const Vector2d*>(this);
};

inline Vector2d Point2d::toVector2d() const
{
    return Vector2d(x, y);
};

inline double Point2d::operator[](int i) const
{
    return *(&x + i);
};

inline double& Point2d::operator[](int i)
{
    return *(&x + i);
};

inline Point2d operator*(double scale, const Point2d& pt)
{
    return (pt*scale);
};

BM_IMPORTEXPORT Point2d operator*(double scale, Point2d pt);

} // namespace