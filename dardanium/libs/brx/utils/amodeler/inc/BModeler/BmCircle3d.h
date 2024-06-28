// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmLine3d.h"

namespace AModeler
{

class BM_IMPORTEXPORT Circle3d
{
public:
    double radius;
    Line3d axis;

    Circle3d();
    Circle3d(Line3d,double);
    Circle3d(const Point3d&,const Point3d&,const Point3d&,double);
    Circle3d(const Point3d&,const Point3d&,const Vector3d&,double,bool);

    bool isEqual(const Circle3d&) const;
    bool isValid() const;
    int tessellate(int,bool,const Point3d,const Point3d,Point3d*);
    Vector3d tangentAt(const Point3d&) const;

    void operator*=(const Transf3d&);
};

}
