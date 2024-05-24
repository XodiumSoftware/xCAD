// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmGlobal.h"
#include "BmVector3d.h"
#include "BmVector2d.h"
#include "BmIntVector3d.h"

class AcGeVector3d;

namespace AModeler
{

class BM_IMPORTEXPORT Vector3d
{
public:
    static const Vector3d kNull;
    static const Vector3d kXDir;
    static const Vector3d kYDir;
    static const Vector3d kZDir;

    double x;
    double y;
    double z;

    Vector3d();
    Vector3d(double,double,double);
    Vector3d(const AcGeVector3d&);
    Vector3d(const IntVector3d&);
    Vector3d(const Vector2d&);

    bool isEqual(const Vector3d&,double = epsNorSqrd()) const;
    bool isEqualRect(const Vector3d&,double = epsNor()) const;
    bool isExactNull() const;
    bool isNull(double = epsNorSqrd()) const;
    bool isUnitLength(double = epsNor()) const;
    bool isParallel(const Vector3d&,double = epsNorSqrd()) const;
    bool isParallelNorm(const Vector3d&,double = epsNorSqrd()) const;
    bool isPerpend(const Vector3d&,double = epsNor()) const;
    const Vector2d& toVector2d() const;
    double angle(const Vector3d&) const;
    double dist(const Vector3d&) const;
    double distRect(const Vector3d&) const;
    double distSqrd(const Vector3d&) const;
    double length() const;
    double lengthRect() const;
    double lengthSqrd() const;
    int dominantDirection() const;
    Vector2d toVector2d(int) const;
    Vector2d toVector2d(int,int) const;
    Vector3d normalizeGetLength(double&) const;
    Vector3d normalize() const;
    Vector3d perpend() const;
    void orthoPlane(int&,int&) const;
    void orthoPlane(int&,int&,int&) const;

    double operator%(const Vector3d&) const;
    double operator[](int) const;
    double& operator[](int);
    operator AcGeVector3d&();
    operator const AcGeVector3d&() const;
    Vector3d operator*(double) const;
    Vector3d operator*(const Vector3d&) const;
    Vector3d operator+(const Vector3d&) const;
    Vector3d operator-() const;
    Vector3d operator-(const Vector3d&) const;
    Vector3d operator/(double) const;
    void operator*=(const Transf3d&);
    void operator*=(double);
    void operator+=(const Vector3d&);
    void operator-=(const Vector3d&);
    void operator/=(double);

    static Vector3d random();
    static Vector3d& cast(AcGeVector3d&);
};

inline Vector3d::Vector3d() : x(0.0), y(0.0), z(0.0) {};

inline Vector3d::Vector3d(double vecX, double vecY, double vecZ) : x(vecX), y(vecY), z(vecZ) {};

inline Vector3d::Vector3d(const IntVector3d& vec) : x(vec.x), y(vec.y), z(vec.z) {};

inline Vector3d::Vector3d(const Vector2d& vec) : x(vec.x), y(vec.y), z(0.0) {};

inline Vector3d Vector3d::operator+(const Vector3d& vec) const
{
    return Vector3d(x + vec.x, y + vec.y, z + vec.z);
};

inline Vector3d Vector3d::operator-(const Vector3d& vec) const
{
    return Vector3d(x - vec.x, y - vec.y, z - vec.z);
};

inline Vector3d Vector3d::operator-() const
{
    return Vector3d(-x, -y, -z);
};

inline Vector3d Vector3d::operator*(double scale) const
{
    return Vector3d(x*scale, y*scale, z*scale);
};

inline Vector3d Vector3d::operator/(double scale) const
{
    return Vector3d(x/scale, y/scale, z/scale);
};

inline void Vector3d::operator+=(const Vector3d& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
};

inline void Vector3d::operator-=(const Vector3d& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
};

inline void Vector3d::operator*=(double scale)
{
    x *= scale;
    y *= scale;
    z *= scale;
};

inline void Vector3d::operator/=(double scale)
{
    x /= scale;
    y /= scale;
    z /= scale;
};

inline double Vector3d::operator%(const Vector3d& vec) const
{
    return (x*vec.x + y*vec.y + z*vec.z);
};

inline double Vector3d::length() const
{
    return sqrt(lengthSqrd());
};

inline double Vector3d::lengthSqrd() const
{
    return (x*x + y*y + z*z);
};

inline double Vector3d::lengthRect() const
{
    return (fabs(x) + fabs(y) + fabs(z));
};

inline double Vector3d::dist(const Vector3d& vec) const
{
    return (*this - vec).length();
};

inline double Vector3d::distSqrd(const Vector3d& vec) const
{
    return (*this - vec).lengthSqrd();
};

inline double Vector3d::distRect(const Vector3d& vec) const
{
    return (*this - vec).lengthRect();
};

inline bool Vector3d::isEqual(const Vector3d& vec, double tolSqr) const
{
    return (distSqrd(vec) <= tolSqr);
};

inline bool Vector3d::isEqualRect(const Vector3d& vec, double tolRect) const
{
    return (distRect(vec) <= tolRect);
};

inline bool Vector3d::isExactNull() const
{
    return (x == 0.0 && y == 0.0 && z == 0.0);
};

inline bool Vector3d::isNull(double tolSqr) const
{
    return (lengthSqrd() <= tolSqr);
};

inline Vector3d Vector3d::normalizeGetLength(double& length) const
{
    length = this->length();
    return ((length > kEpsZero) ? Vector3d(x/length, y/length, z/length) : Vector3d::kNull);
};

inline Vector3d Vector3d::normalize() const
{
    double length = 0.0;
    return normalizeGetLength(length);
};

inline const Vector2d& Vector3d::toVector2d() const
{
    return *(reinterpret_cast<const Vector2d*>(this));
};

inline Vector2d Vector3d::toVector2d(int i) const
{
    return (i == 0) ? Vector2d(y, z) : (i == 1) ? Vector2d(z, x) : Vector2d(x, y);
};

inline Vector2d Vector3d::toVector2d(int i1, int i2) const
{
    return Vector2d((*this)[i1], (*this)[i2]);
};

inline double Vector3d::operator[](int i) const
{
    return *(&x + i);
};

inline double& Vector3d::operator[](int i)
{
    return *(&x + i);
};

inline void Vector3d::orthoPlane(int& i1, int& i2) const
{
    int i3 = 0;
    orthoPlane(i1, i2, i3);
};

inline bool Vector3d::isParallel(const Vector3d& vec, double tolSqr) const
{
    return normalize().isParallelNorm(vec.normalize(), tolSqr);
};

inline Vector3d operator*(double scale, const Vector3d& vec)
{
    return (vec*scale);
};


} // namespace