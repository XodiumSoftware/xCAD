// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmVector3d.h"
#include "BmPoint3d.h"
#include "BmLine3d.h"

namespace AModeler
{

class BM_IMPORTEXPORT Plane
{
public:
    double d;
    Vector3d normal;

    Plane();
    Plane(const Point3d&,const Vector3d&);
    Plane(const Vector3d&,double);
    Plane(const Point3d&,const Point3d&,const Point3d&);
    Plane(const Point3d&,const Vector3d&,const Vector3d&);
    Plane(const Point3d[],int);
    Plane(const Point3d[],int,const Vector3d&);

    Point3d pointOnPlane() const;

    bool isEqual(const Plane&) const;
    bool isValid() const;
    double dist(const Point3d&) const;
    Line3d project(const Line3d&) const;
    Point3d project(const Point3d&) const;
    Vector3d project(const Vector3d&) const;
    void orthoPlane(int&,int&) const;
    void orthoPlane(int&,int&,int&) const;

    Line3d operator*(const Plane&) const;
    Plane operator-() const;
    Point3d operator*(const Line3d&) const;

    static Plane fromPoints(const Point3d[],int,bool);
};

inline Plane::Plane() : normal(Vector3d::kNull), d(0.0) {};

inline Plane::Plane(const Vector3d& planeNormal, double dist) : normal(planeNormal), d(dist) {};

inline Point3d Plane::pointOnPlane() const
{
    return project(Point3d::kNull);
};

inline bool Plane::isValid() const
{
    return normal.isUnitLength();
};

inline bool Plane::isEqual(const Plane& plane) const
{
    return (normal.isEqual(plane.normal) && fabs(d - plane.d) <= epsAbs());
};

inline Plane Plane::operator-() const
{
    return Plane(-normal, -d);
};

inline Line3d Plane::project(const Line3d& line) const
{
    return Line3d(project(line.point), project(line.vector));
};

inline void Plane::orthoPlane(int& i1, int& i2, int& i3) const
{
    normal.orthoPlane(i1, i2, i3);
};

inline void Plane::orthoPlane(int& i1, int& i2) const
{
    normal.orthoPlane(i1, i2);
};


} // namespace
