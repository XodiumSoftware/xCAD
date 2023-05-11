// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"


namespace Atil
{;

class Matrix2d;
class Point2d;


class ATIL_IMPORTEXPORT Vector2d
{
public:
    double x;
    double y;

    Vector2d() : x(0), y(0) {}
    Vector2d(const Vector2d& rh) :x(rh.x), y(rh.y) {}
    Vector2d(double _x, double _y) : x(_x), y(_y) {}
    virtual ~Vector2d() {}
    //virtual double angle() const;
    //virtual double angleTo(const Vector2d& v) const;
    //virtual double ccwAngleTo(const Vector2d& v) const;
    //virtual double dotProduct(const Vector2d& v) const;
    //virtual Vector2d  getOrthoVector() const;
    //virtual bool isCodirectionalTo(const Vector2d& v) const;
    //virtual bool isEqualTo(const Vector2d& v) const;
    //virtual bool isParallelTo(const Vector2d& v) const;
    //virtual double length() const;
    //virtual const Vector2d& negate();
    //virtual Vector2d normal() const;
    //virtual const Vector2d& normalize();
    //virtual Vector2d perpVector() const;
    //virtual const Vector2d& rotate(double r);
    virtual const Vector2d& set(const Vector2d& rh) { x = rh.x; y = rh.y; return *this; }
    virtual const Vector2d& set(double _x, double _y) { x = _x; y = _y; return *this; }
    //virtual Vector2d& transformBy(const Matrix2d& lh);
    //virtual Vector2d operator-() const;
    //virtual Vector2d operator-(const Vector2d& rh) const;
    //virtual Vector2d& operator-=(const Vector2d& rh);
    //virtual Point2d operator-(const Point2d& rh) const;
    //virtual Point2d operator+(const Point2d& rh) const;
    //virtual Vector2d operator+(const Vector2d& rh) const;
    //virtual Vector2d& operator+=(const Vector2d& rh);
    //virtual Vector2d operator*(const double& rh) const;
    //virtual Vector2d& operator*=(const double& rh);
    //virtual Vector2d operator/(const double&rh) const;
    //virtual Vector2d& operator/=(const double& rh);
    //virtual bool operator==(const Vector2d& rh) const;
    //virtual bool operator!=(const Vector2d& rh) const;
};


class ATIL_IMPORTEXPORT VectorUL : public Vector2d
{
public:
    VectorUL() {}
    VectorUL(const Vector2d& rh) : Vector2d(rh) {}
    VectorUL(double _x, double _y) : Vector2d(_x, _y) {}
    virtual ~VectorUL() {}
    //virtual double angle() const;
    //virtual double ccwAngleTo(const Vector2d& v) const;
    //virtual Vector2d perpVector() const;
    //virtual const Vector2d& rotate(double r);
};


} //namespace Atil
