// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmEntity.h"
#include "BmTransf3d.h"

namespace AModeler
{

class ImplCurve;

class BM_IMPORTEXPORT Curve: public Entity
{
public:
    enum Type
    {
        kUnspecified = 0,
        kCircle
    };

private:
    std::shared_ptr<ImplCurve> m_pBrxImp;

public:
    Curve* cptr;
    int n;

    Curve(Body* = NULL);

    virtual bool transform(const Transf3d&,Transf3d::Type = Transf3d::kUnknown,const Vector3d& = Vector3d::kNull) = 0;
    virtual Curve* copy() const = 0;
    virtual Type type() const = 0;
    virtual void print(FILE* = NULL) const = 0;
    virtual void restore(SaveRestoreCallback*);
    virtual void save(SaveRestoreCallback*) const;

    Curve* next() const;
    void setNext(Curve*);
};

}
