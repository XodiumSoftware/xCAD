// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmGlobal.h"

class AcGeVector2d;


namespace AModeler
{

class BM_IMPORTEXPORT Vector2d
{
public:
    static const Vector2d kNull;
    static const Vector2d kXDir;
    static const Vector2d kYDir;

    double x;
    double y;

    Vector2d();
    Vector2d(const AcGeVector2d&);
    Vector2d(double,double);

    bool isEqual(const Vector2d&,double = epsNorSqrd()) const;
    bool isEqualRect(const Vector2d&,double = epsNor()) const;

    bool isExactNull() const;
    bool isNull(double = epsNorSqrd()) const;
    bool isUnitLength(double = epsNor()) const;
    bool isParallel(const Vector2d&) const;
    bool isPerpend(const Vector2d&) const;
    double angle(const Vector2d&) const;
    double dist(const Vector2d&) const;
    double distRect(const Vector2d&) const;
    double distSqrd(const Vector2d&) const;
    double length() const;
    double lengthRect() const;
    double lengthSqrd() const;
    Vector2d normalizeGetLength(double&) const;
    Vector2d normalize() const;
    Vector2d perpend() const;

    double operator%(const Vector2d&) const;
    double operator[](int) const;
    double& operator[](int);
    operator AcGeVector2d&();
    operator const AcGeVector2d&() const;
    Vector2d operator*(double) const;
    Vector2d operator+(const Vector2d&) const;
    Vector2d operator-() const;
    Vector2d operator-(const Vector2d&) const;
    Vector2d operator/(double) const;
    void operator*=(double);
    void operator+=(const Vector2d&);
    void operator-=(const Vector2d&);
    void operator/=(double);

    static Vector2d& cast(AcGeVector2d&);
};

inline Vector2d::Vector2d() : x(0.0), y(0.0) {};

inline Vector2d::Vector2d(double vecX, double vecY) : x(vecX), y(vecY) {};

inline Vector2d Vector2d::operator+(const Vector2d& vec) const
{
    return Vector2d(x + vec.x, y + vec.y);
};

inline Vector2d Vector2d::operator-(const Vector2d& vec) const
{
    return Vector2d(x - vec.x, y - vec.y);
};

inline Vector2d Vector2d::operator-() const
{
    return Vector2d(-x, -y);
};

inline Vector2d Vector2d::operator*(double scale) const
{
    return Vector2d(x*scale, y*scale);
};

inline Vector2d Vector2d::operator/(double scale) const
{
    return Vector2d(x/scale, y/scale);
};

inline void Vector2d::operator+=(const Vector2d& vec)
{
    x += vec.x;
    y += vec.y;
};

inline void Vector2d::operator-=(const Vector2d& vec)
{
    x -= vec.x;
    y -= vec.y;
};

inline void Vector2d::operator*=(double scale)
{
    x *= scale;
    y *= scale;
};

inline void Vector2d::operator/=(double scale)
{
    x /= scale;
    y /= scale;
};

inline double Vector2d::operator%(const Vector2d& vec) const
{
    return (x*vec.x + y*vec.y);
};

inline Vector2d Vector2d::perpend() const
{
    return Vector2d(-y, x);
};

inline double Vector2d::length() const
{
    return sqrt(lengthSqrd());
};

inline double Vector2d::lengthSqrd() const
{
    return (x*x + y*y);
};

inline double Vector2d::lengthRect() const
{
    return (fabs(x) + fabs(y));
};

inline double Vector2d::dist(const Vector2d& vec) const
{
    return (*this - vec).length();
};

inline double Vector2d::distSqrd(const Vector2d& vec) const
{
    return (*this - vec).lengthSqrd();
};

inline double Vector2d::distRect(const Vector2d& vec) const
{
    return (*this - vec).lengthRect();
};

inline bool Vector2d::isEqual(const Vector2d& vec, double tolSqr) const
{
    return (distSqrd(vec) <= tolSqr);
};

inline bool Vector2d::isEqualRect(const Vector2d& vec, double tolRect) const
{
    return (distRect(vec) <= tolRect);
};

inline bool Vector2d::isExactNull() const
{
    return (x == 0.0 && y == 0.0);
};

inline bool Vector2d::isNull(double tolSqr) const
{
    return (lengthSqrd() <= tolSqr);
};

inline Vector2d Vector2d::normalizeGetLength(double& len) const
{
    len = length();
    return ((len > kEpsZero) ? Vector2d(x/len, y/len) : Vector2d::kNull);
};

inline Vector2d Vector2d::normalize() const
{
    double length;
    return normalizeGetLength(length);
};

inline double Vector2d::operator[](int i) const
{
    return *(&x + i);
};

inline double& Vector2d::operator[](int i)
{
    return *(&x + i);
};

inline Vector2d operator*(double scale, const Vector2d& vec)
{
    return (vec*scale);
};

} // namespace
