// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeVector2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGePoint2d
{
public:
    static const AcGePoint2d kOrigin;

    double x;
    double y;

    AcGePoint2d();
    AcGePoint2d(double,double);
    AcGePoint2d(const AcGePoint2d&);

    AcGePoint2d& mirror(const AcGeLine2d&);
    AcGePoint2d& rotateBy(double,const AcGePoint2d& = kOrigin);
    AcGePoint2d& scaleBy(double,const AcGePoint2d& = kOrigin);
    AcGePoint2d& set(double,double);
    AcGePoint2d& setToProduct(const AcGeMatrix2d&,const AcGePoint2d&);
    AcGePoint2d& setToSum(const AcGePoint2d&,const AcGeVector2d&);
    AcGePoint2d& transformBy(const AcGeMatrix2d&);
    AcGeVector2d asVector() const;
    bool isEqualTo(const AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    double distanceTo(const AcGePoint2d&) const;

    AcGePoint2d operator*(double) const;
    AcGePoint2d operator+(const AcGeVector2d&) const;
    AcGePoint2d operator-(const AcGeVector2d&) const;
    AcGePoint2d operator/(double) const;
    AcGePoint2d& operator*=(double);
    AcGePoint2d& operator+=(const AcGeVector2d&);
    AcGePoint2d& operator-=(const AcGeVector2d&);
    AcGePoint2d& operator/=(double);
    AcGeVector2d operator-(const AcGePoint2d&) const;
    bool operator!=(const AcGePoint2d&) const;
    bool operator==(const AcGePoint2d&) const;
    double operator[](unsigned int) const;
    double& operator[](unsigned int);

    friend AcGePoint2d operator*(const AcGeMatrix2d&,const AcGePoint2d&);
    friend AcGePoint2d operator*(double,const AcGePoint2d&);
};

template<> struct T_AcArrayAllocatorSelector<AcGePoint2d, false> {
  typedef AcArrayMemCopyReallocator<AcGePoint2d> Allocator;
}; //AcGePoint2d can use fast MemCopyReallocator
typedef AcArray< AcGePoint2d, AcArrayMemCopyReallocator<AcGePoint2d> > AcGePoint2dArray;
