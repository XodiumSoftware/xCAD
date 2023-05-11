// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
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
