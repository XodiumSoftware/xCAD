// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmPoint3d.h"
#include "BmVector3d.h"
#include "BmTransf3d.h"

namespace AModeler
{

class BM_IMPORTEXPORT Line3d
{
public:
    static const Line3d kNull;
    static const Line3d kXAxis;
    static const Line3d kYAxis;
    static const Line3d kZAxis;

    Point3d  point;
    Vector3d vector;

    Line3d();
    Line3d(const Point3d&,const Point3d&);
    Line3d(const Point3d&,const Vector3d&);

    bool intersect(const Line3d&,Point3d&) const;
    bool isCoincident(const Line3d&,bool) const;
    bool isEqual(const Line3d&) const;
    bool isValid() const;
    double dist(const Point3d&) const;
    Point3d project(const Point3d&) const;

    void operator*=(const Transf3d&);
};

inline Line3d::Line3d() : point(Point3d::kNull), vector(Vector3d::kNull) {};

inline Line3d::Line3d(const Point3d& pt, const Vector3d& vec) : point(pt), vector(vec) {};

inline Line3d::Line3d(const Point3d& pt1, const Point3d& pt2) : point(pt1), vector(pt2-pt1) {};

inline bool Line3d::isValid() const
{
	return !vector.isNull();
};

inline double Line3d::dist(const Point3d& pt) const
{
	return (project(pt) - pt).length();
};

inline bool Line3d::isEqual(const Line3d& line) const
{
    return (point.isEqual(line.point) && vector.isEqual(line.vector));
};

inline void Line3d::operator*=(const Transf3d& transf)
{
    point *= transf;
    vector *= transf;
};

} // namespace