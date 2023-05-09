// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once
#include "BmPoint3d.h"
#include "BmLine3d.h"
#include "BmVector3d.h"

class AcGeMatrix3d;

namespace AModeler
{

class BM_IMPORTEXPORT Transf3d
{
public:
    enum ProjectionType
    {
        kParallelProjection = 0,
        kPerspectiveProjection
    };

    enum Type
    {
        kRigidMotion = 0,
        kEqualScalingOrtho,
        kNonOrtho,
        kProjection,
        kUnknown
    };

    static bool isError;
    static const Transf3d kBackView;
    static const Transf3d kBottomView;
    static const Transf3d kDimetricView;
    static const Transf3d kFrontView;
    static const Transf3d kIdentity;
    static const Transf3d kIsometricView;
    static const Transf3d kLeftView;
    static const Transf3d kRightView;
    static const Transf3d kTopView;

    double c[4][4];

    Transf3d();
    Transf3d(const Point3d&);
    Transf3d(const Line3d&);
    Transf3d(const AcGeMatrix3d&);
    Transf3d(const Point3d&,const Vector3d&,const Vector3d&);
    Transf3d(const Point3d&,const Vector3d&,const Vector3d&,const Vector3d&);
    Transf3d(ProjectionType,const Point3d&,const Point3d& = Point3d::kNull,const Vector3d& = Vector3d::kNull);

    bool isEqualScalingOrthogonal() const;
    bool isIdentity() const;
    bool isMirror() const;
    bool isOrthogonal() const;
    bool isPerspective() const;
    bool isValid() const;
    Point3d origin() const;
    Point3d project(const Point3d&) const;
    Transf3d invert(bool = true) const;
    Vector3d stretchVector() const;
    Vector3d xDir() const;
    Vector3d yDir() const;
    Vector3d zDir() const;
    void getCoordSystem(Point3d&,Vector3d&,Vector3d&,Vector3d&) const;

    void setCoordSystem(const Point3d&, const Vector3d&, const Vector3d&, const Vector3d&);

    void restore(SaveRestoreCallback*);
    void save(SaveRestoreCallback*) const;

    double operator()(int,int) const;
    double& operator()(int,int);
    Line3d operator*(const Line3d&) const;
    operator AcGeMatrix3d&();
    operator const AcGeMatrix3d&() const;
    Point3d operator*(const Point3d&) const;
    Transf3d operator*(const Transf3d&) const;
    Vector3d operator*(const Vector3d&) const;

    static Transf3d align(const Point3d&,const Point3d&,const Point3d&,const Point3d&,const Point3d&,const Point3d&);
    static Transf3d align(const Point3d&,const Vector3d&,const Point3d&,const Vector3d&);
    static Transf3d align(const Point3d&,const Vector3d&,const Vector3d&,const Point3d&,const Vector3d&,const Vector3d&);
    static Transf3d mirroring(const Plane&);
    static Transf3d projectOn(const Plane&,const Vector3d& = Vector3d::kNull);
    static Transf3d rotation(const Line3d&,double);
    static Transf3d scaling(const Point3d&,const Vector3d&);
    static Transf3d scaling(const Point3d&,double);
    static Transf3d stretching(const Line3d&);
    static Transf3d translation(const Vector3d&);

    static Transf3d& cast(AcGeMatrix3d&);

private:
    void setToIdentity();
};


inline Transf3d::Transf3d()
{
    setToIdentity();
    isError = false;
}

inline Transf3d::Transf3d(const Point3d& origin, 
                          const Vector3d& xAxis,
                          const Vector3d& yAxis,
                          const Vector3d& zAxis)
{
    setCoordSystem(origin, xAxis.normalize(), yAxis.normalize(), zAxis.normalize());
    isError = false;
}


inline double Transf3d::operator()(int row, int column) const
{
    return c[row][column];
}

inline double& Transf3d::operator()(int row, int column)
{
    return c[row][column];
}

inline Point3d Transf3d::project(const Point3d& pt) const
{
    isError = false;
    return pt.project(*this);
}

inline Vector3d Transf3d::operator*(const Vector3d& vec) const
{
    Vector3d newVec = vec;
    newVec *= *this;
    return newVec;
}

inline Point3d Transf3d::operator*(const Point3d& pt) const
{
    Point3d newPt = pt;
    newPt *= *this;
    return newPt;
}

} // namespace
