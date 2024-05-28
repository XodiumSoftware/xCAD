// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmCurve.h"

namespace AModeler
{

class BM_IMPORTEXPORT UnspecifiedCurve: public Curve
{
public:
    UnspecifiedCurve(Body* = NULL);

    virtual bool transform(const Transf3d&,Transf3d::Type = Transf3d::kUnknown,const Vector3d& = Vector3d::kNull);
    virtual Curve* copy() const;
    virtual Type type() const;
    virtual void print(FILE* = NULL) const;
};

}
