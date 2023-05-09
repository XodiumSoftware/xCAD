// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmGlobal.h"
#include "BmPoint2d.h"
#include "BmVector3d.h"
#include "BmIntPoint3d.h"

class AcGePoint3d;

namespace AModeler
{

class BM_IMPORTEXPORT Point3d
{
public:
    static const Point3d kNull;

    double x;
    double y;
    double z;

    Point3d();
    Point3d(double,double,double);
    Point3d(const AcGePoint3d&);
    Point3d(const IntPoint3d&);
    Point3d(const Point2d&);

    bool isBetween(const Point3d&,const Point3d&) const;
    bool isEqual(const Point3d&,double = epsAbsSqrd()) const;
    bool isEqualRect(const Point3d&,double = epsAbs()) const;
    bool isValid() const;
    double dist(const Point3d&) const;
    double distRect(const Point3d&) const;
    double distSqrd(const Point3d&) const;
    double length() const;
    double lengthRect() const;
    double lengthSqrd() const;
    Point2d toPoint2d() const;
    Point2d toPoint2d(int) const;
    Point2d toPoint2d(int,int) const;
    Point3d project(const Transf3d&) const;
    const Vector3d& asVector() const;
    Vector3d toVector3d() const;

    double operator%(const Vector3d&) const;
    double operator[](int) const;
    double& operator[](int);
    operator AcGePoint3d&();
    operator const AcGePoint3d&() const;
    Point3d operator*(double) const;
    Point3d operator+(const Point3d&) const;
    Point3d operator+(const Vector3d&) const;
    Point3d operator-() const;
    Point3d operator-(const Vector3d&) const;
    Point3d operator/(double) const;
    Vector3d operator-(const Point3d&) const;
    void operator*=(const Transf3d&);
    void operator*=(double);
    void operator+=(const Point3d&);
    void operator+=(const Vector3d&);
    void operator-=(const Point3d&);
    void operator-=(const Vector3d&);
    void operator/=(double);

    static Point3d& cast(AcGePoint3d&);
};

inline Point3d::Point3d() : x(0.0), y(0.0), z(0.0) {};

inline Point3d::Point3d(double ptX, double ptY, double ptZ) : x(ptX), y(ptY), z(ptZ) {};

inline Point3d::Point3d(const IntPoint3d& pt) : x(pt.x), y(pt.y), z(pt.z) {};

inline Point3d::Point3d(const Point2d& pt) : x(pt.x), y(pt.y), z(0.0) {};

inline Point3d Point3d::operator+(const Point3d& pt) const
{
    return Point3d(x + pt.x, y + pt.y, z + pt.z);
};

inline Point3d Point3d::operator+(const Vector3d& vec) const
{
    return Point3d(x + vec.x, y + vec.y, z + vec.z);
};

inline Vector3d Point3d::operator-(const Point3d& pt) const
{
    return Vector3d(x - pt.x, y - pt.y, z - pt.z);
};

inline Point3d Point3d::operator-(const Vector3d& vec) const
{
    return Point3d(x - vec.x, y - vec.y, z - vec.z);
};

inline Point3d Point3d::operator-() const
{
    return Point3d(-x, -y, -z);
};

inline Point3d Point3d::operator*(double scale) const
{
    return Point3d(x*scale, y*scale, z*scale);
};

inline Point3d Point3d::operator/(double scale) const
{
    return Point3d(x/scale, y/scale, z/scale);
};

inline void Point3d::operator+=(const Point3d& pt)
{
    x += pt.x;
    y += pt.y;
    z += pt.z;
};

inline void Point3d::operator+=(const Vector3d& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
};

inline void Point3d::operator-=(const Point3d& pt)
{
    x -= pt.x;
    y -= pt.y;
    z -= pt.z;
};

inline void Point3d::operator-=(const Vector3d& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
};

inline void Point3d::operator*=(double scale)
{
    x *= scale;
    y *= scale;
    z *= scale;
};

inline void Point3d::operator/=(double scale)
{
    x /= scale;
    y /= scale;
    z /= scale;
};

inline double Point3d::operator%(const Vector3d& vec) const
{
    return (x*vec.x + y*vec.y + z*vec.z);
};

inline double Point3d::length() const
{
    return sqrt(lengthSqrd());
};

inline double Point3d::lengthSqrd() const
{
    return (x*x + y*y + z*z);
};

inline double Point3d::lengthRect() const
{
    return (fabs(x) + fabs(y) + fabs(z));
};

inline double Point3d::dist(const Point3d& pt) const
{
    return (*this - pt).length();
};

inline double Point3d::distSqrd(const Point3d& pt) const
{
    return (*this - pt).lengthSqrd();
};

inline double Point3d::distRect(const Point3d& pt) const
{
    return (*this - pt).lengthRect();
};

inline bool Point3d::isEqual(const Point3d& pt, double tolSqr) const
{
    return (distSqrd(pt) <= tolSqr);
};

inline bool Point3d::isEqualRect(const Point3d& pt, double tolRect) const
{
    return (distRect(pt) <= tolRect);
};

inline bool Point3d::isValid() const
{
    return (fabs(x) < kMaxReal && fabs(y) < kMaxReal && fabs(z) < kMaxReal);
};

inline Point2d Point3d::toPoint2d() const
{
    return Point2d(x, y);
};

inline Point2d Point3d::toPoint2d(int dropIndex) const
{
    if(dropIndex == 0)
        return Point2d(y, z);

    if(dropIndex == 1)
        return Point2d(z, x);

    return Point2d(x, y);
};

inline Point2d Point3d::toPoint2d(int i1, int i2) const
{
    return Point2d((*this)[i1], (*this)[i2]);
};

inline const Vector3d& Point3d::asVector() const
{
    return *reinterpret_cast<const Vector3d*>(this);
};

inline Vector3d Point3d::toVector3d() const
{
    return Vector3d(x,y,z);
};

inline double Point3d::operator[](int i) const
{
    return *(&x + i);
};

inline double& Point3d::operator[](int i)
{
    return *(&x + i);
};

inline Point3d operator*(double scale, const Point3d& pt)
{
    return (pt*scale);
};


BM_IMPORTEXPORT Point3d operator*(double scale, Point3d pt);

} // namespace