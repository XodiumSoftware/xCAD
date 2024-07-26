// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmRevolutionSurface.h"

namespace AModeler
{

class ImplTorusSurface;

class BM_IMPORTEXPORT TorusSurface: public RevolutionSurface
{
private:
    std::shared_ptr<ImplTorusSurface> m_pBrxImp;

public:
    TorusSurface();
    TorusSurface(const Line3d&,double,double,int,int,Body*);

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

    double majorRadius() const;
    double minorRadius() const;
    int majorApprox() const;
    int minorApprox() const;
    Point3d center() const;
};

}
