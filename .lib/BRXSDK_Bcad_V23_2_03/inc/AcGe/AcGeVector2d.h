// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcGeVector2d
{
public:
    static const AcGeVector2d kIdentity;
    static const AcGeVector2d kXAxis;
    static const AcGeVector2d kYAxis;

    double x;
    double y;

    AcGeVector2d();
    AcGeVector2d(double,double);
    AcGeVector2d(const AcGeVector2d&);

    AcGeVector2d normal(const AcGeTol& = AcGeContext::gTol) const;
    AcGeVector2d perpVector() const;
    AcGeVector2d& mirror(const AcGeVector2d&);
    AcGeVector2d& negate();
    AcGeVector2d& normalize(const AcGeTol& = AcGeContext::gTol);
    AcGeVector2d& normalize(const AcGeTol&,AcGeError&);
    AcGeVector2d& rotateBy(double);
    AcGeVector2d& set(double,double);
    AcGeVector2d& setToProduct(const AcGeMatrix2d&,const AcGeVector2d&);
    AcGeVector2d& setToProduct(const AcGeVector2d&,double);
    AcGeVector2d& setToSum(const AcGeVector2d&,const AcGeVector2d&);
    AcGeVector2d& transformBy(const AcGeMatrix2d&);
    Adesk::Boolean isCodirectionalTo(const AcGeVector2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isCodirectionalTo(const AcGeVector2d&,const AcGeTol&,AcGeError&) const;
    Adesk::Boolean isParallelTo(const AcGeVector2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isParallelTo(const AcGeVector2d&,const AcGeTol&,AcGeError&) const;
    Adesk::Boolean isPerpendicularTo(const AcGeVector2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isPerpendicularTo(const AcGeVector2d&,const AcGeTol&,AcGeError&) const;
    Adesk::Boolean isUnitLength(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isZeroLength(const AcGeTol& = AcGeContext::gTol) const;
    bool isEqualTo(const AcGeVector2d&,const AcGeTol& = AcGeContext::gTol) const;
    double angle() const;
    double angleTo(const AcGeVector2d&) const;
    double dotProduct(const AcGeVector2d&) const;
    double length() const;
    double lengthSqrd() const;

    AcGeVector2d operator*(double) const;
    AcGeVector2d operator+(const AcGeVector2d&) const;
    AcGeVector2d operator-() const;
    AcGeVector2d operator-(const AcGeVector2d&) const;
    AcGeVector2d operator/(double) const;
    AcGeVector2d& operator*=(double);
    AcGeVector2d& operator+=(const AcGeVector2d&);
    AcGeVector2d& operator-=(const AcGeVector2d&);
    AcGeVector2d& operator/=(double);
    bool operator!=(const AcGeVector2d&) const;
    bool operator==(const AcGeVector2d&) const;
    double operator[](unsigned int) const;
    double& operator[](unsigned int);
    operator AcGeMatrix2d() const;

    friend AcGeVector2d operator*(const AcGeMatrix2d&,const AcGeVector2d&);
    friend AcGeVector2d operator*(double,const AcGeVector2d&);
};

template<> struct T_AcArrayAllocatorSelector<AcGeVector2d, false> {
  typedef AcArrayMemCopyReallocator<AcGeVector2d> Allocator;
}; //AcGeVector2d can use fast MemCopyReallocator
typedef AcArray< AcGeVector2d, AcArrayMemCopyReallocator<AcGeVector2d> > AcGeVector2dArray;
