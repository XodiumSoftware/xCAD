// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmRevolutionSurface.h"

namespace AModeler
{

class ImplCylinderSurface;

class BM_IMPORTEXPORT CylinderSurface: public RevolutionSurface
{
private:
    std::shared_ptr<ImplCylinderSurface> m_pBrxImp;

public:
    CylinderSurface();
    CylinderSurface(const Line3d&,double,int,Body*);
    CylinderSurface(const Line3d&,const Vector3d&,double,int,Body*);

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
    int approx() const;
};

}
