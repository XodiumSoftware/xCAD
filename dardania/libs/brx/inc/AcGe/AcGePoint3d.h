// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeVector3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGePoint3d
{
public:
    static const AcGePoint3d kOrigin;

    double x;
    double y;
    double z;

    AcGePoint3d();
    AcGePoint3d(double,double,double);
    AcGePoint3d(const AcGePlanarEnt&,const AcGePoint2d&);
    AcGePoint3d(const AcGePoint3d&);

    AcGePoint2d convert2d(const AcGePlanarEnt&) const;
    AcGePoint3d orthoProject(const AcGePlane&) const;
    AcGePoint3d project(const AcGePlane&,const AcGeVector3d&) const;
    AcGePoint3d& mirror(const AcGePlane&);
    AcGePoint3d& rotateBy(double,const AcGeVector3d&,const AcGePoint3d& = kOrigin);
    AcGePoint3d& scaleBy(double,const AcGePoint3d& = kOrigin);
    AcGePoint3d& set(const AcGePlanarEnt&,const AcGePoint2d&);
    AcGePoint3d& set(double,double,double);
    AcGePoint3d& setToProduct(const AcGeMatrix3d&,const AcGePoint3d&);
    AcGePoint3d& setToSum(const AcGePoint3d&,const AcGeVector3d&);
    AcGePoint3d& transformBy(const AcGeMatrix3d&);
    AcGeVector3d asVector() const;
    bool isEqualTo(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    double distanceTo(const AcGePoint3d&) const;

    AcGePoint3d operator*(double) const;
    AcGePoint3d operator+(const AcGeVector3d&) const;
    AcGePoint3d operator-(const AcGeVector3d&) const;
    AcGePoint3d operator/(double) const;
    AcGePoint3d& operator*=(double);
    AcGePoint3d& operator+=(const AcGeVector3d&);
    AcGePoint3d& operator-=(const AcGeVector3d&);
    AcGePoint3d& operator/=(double);
    AcGeVector3d operator-(const AcGePoint3d&) const;
    bool operator!=(const AcGePoint3d&) const;
    bool operator==(const AcGePoint3d&) const;
    double operator[](unsigned int) const;
    double& operator[](unsigned int);

    friend AcGePoint3d operator*(const AcGeMatrix3d&,const AcGePoint3d&);
    friend AcGePoint3d operator*(double,const AcGePoint3d&);
};

template<> struct T_AcArrayAllocatorSelector<AcGePoint3d, false> {
  typedef AcArrayMemCopyReallocator<AcGePoint3d> Allocator;
}; //AcGePoint3d can use fast MemCopyReallocator
typedef AcArray< AcGePoint3d, AcArrayMemCopyReallocator<AcGePoint3d> > AcGePoint3dArray;
