// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmRevolutionSurface.h"

namespace AModeler
{

class ImplConeSurface;

class BM_IMPORTEXPORT ConeSurface: public RevolutionSurface
{
private:
    std::shared_ptr<ImplCircleCurve> m_pBrxImp;

public:
    ConeSurface();
    ConeSurface(const Line3d&,double,double,int,Body*);

    virtual bool containsPoint(const Point3d&) const;
    virtual bool isEqual(const Surface*) const;
    virtual bool transform(const Transf3d&,Transf3d::Type = Transf3d::kUnknown,const Vector3d& = Vector3d::kNull);
    virtual Circle3d circle(const Plane&,const Line3d&) const;
    virtual Surface* copy() const;
    virtual Type type() const;
    virtual Vector3d normal(const Point3d&) const;
    virtual void print(FILE* = NULL) const;
    virtual void restore(SaveRestoreCallback*);
    virtual void save(SaveRestoreCallback*) const;

    double radius() const;
    double tanAngle() const;
    int approx() const;
    Point3d apex() const;
};

}
