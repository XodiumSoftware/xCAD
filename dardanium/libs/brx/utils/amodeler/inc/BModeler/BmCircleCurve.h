// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmCurve.h"

namespace AModeler
{

class ImplCircleCurve;

class BM_IMPORTEXPORT CircleCurve: public Curve
{
private:
    std::shared_ptr<ImplCircleCurve> m_pBrxImp;

public:
    CircleCurve();
    CircleCurve(const Circle3d&,int,Body*);

    virtual bool transform(const Transf3d&,Transf3d::Type = Transf3d::kUnknown,const Vector3d& = Vector3d::kNull);
    virtual Curve* copy() const;
    virtual Type type() const;
    virtual void print(FILE* = NULL) const;
    virtual void restore(SaveRestoreCallback*);
    virtual void save(SaveRestoreCallback*) const;

    Circle3d circle() const;
    const Transf3d& transf() const;
    double radius() const;
    int approx() const;
    Line3d axis() const;
    Point3d origin() const;
};

}
