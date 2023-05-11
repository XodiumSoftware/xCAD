
// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmEntity.h"
#include "BmTransf3d.h"

namespace AModeler
{

class ImplSurface;

class BM_IMPORTEXPORT Surface: public Entity
{
private:
    std::shared_ptr<ImplSurface> m_pBrxImp;

public:
    enum Type
    {
        kUnspecified = 0,
        kCylinder,
        kCone,
        kSphere,
        kTorus
    };

    int n;
    Surface* sptr;

    Surface(Body* = NULL);

    virtual bool containsPoint(const Point3d&) const = 0;
    virtual bool isEqual(const Surface*) const = 0;
    virtual bool transform(const Transf3d&,Transf3d::Type = Transf3d::kUnknown,const Vector3d& = Vector3d::kNull) = 0;
    virtual Circle3d circle(const Plane&,const Line3d&) const = 0;
    virtual Surface* copy() const = 0;
    virtual Type type() const = 0;
    virtual Vector3d normal(const Point3d&) const = 0;
    virtual void print(FILE* = NULL) const = 0;
    virtual void restore(SaveRestoreCallback*);
    virtual void save(SaveRestoreCallback*) const;

    Surface* next() const;
    void setNext(Surface*);
};

}
