// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcGeVector3d
{
public:
    static const AcGeVector3d kIdentity;
    static const AcGeVector3d kXAxis;
    static const AcGeVector3d kYAxis;
    static const AcGeVector3d kZAxis;

    double x;
    double y;
    double z;

    AcGeVector3d();
    AcGeVector3d(double,double,double);
    AcGeVector3d(const AcGePlanarEnt&,const AcGeVector2d&);
    AcGeVector3d(const AcGeVector3d& vec);

    AcGeMatrix3d rotateTo(const AcGeVector3d&,const AcGeVector3d& = kIdentity) const;
    AcGeVector2d convert2d(const AcGePlanarEnt&) const;
    AcGeVector3d crossProduct(const AcGeVector3d&) const;
    AcGeVector3d normal(const AcGeTol& = AcGeContext::gTol) const;
    AcGeVector3d orthoProject(const AcGeVector3d&) const;
    AcGeVector3d orthoProject(const AcGeVector3d&,const AcGeTol&,AcGeError&) const;
    AcGeVector3d perpVector() const;
    AcGeVector3d project(const AcGeVector3d&,const AcGeVector3d&) const;
    AcGeVector3d project(const AcGeVector3d&,const AcGeVector3d&,const AcGeTol&,AcGeError&) const;
    AcGeVector3d& mirror(const AcGeVector3d&);
    AcGeVector3d& negate();
    AcGeVector3d& normalize(const AcGeTol& = AcGeContext::gTol);
    AcGeVector3d& normalize(const AcGeTol&,AcGeError&);
    AcGeVector3d& rotateBy(double,const AcGeVector3d&);
    AcGeVector3d& set(const AcGePlanarEnt&,const AcGeVector2d&);
    AcGeVector3d& set(double,double,double);
    AcGeVector3d& setToProduct(const AcGeMatrix3d&,const AcGeVector3d&);
    AcGeVector3d& setToProduct(const AcGeVector3d&,double);
    AcGeVector3d& setToSum(const AcGeVector3d&,const AcGeVector3d&);
    AcGeVector3d& transformBy(const AcGeMatrix3d&);
    Adesk::Boolean isCodirectionalTo(const AcGeVector3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isCodirectionalTo(const AcGeVector3d&,const AcGeTol&,AcGeError&) const;
    Adesk::Boolean isParallelTo(const AcGeVector3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isParallelTo(const AcGeVector3d&,const AcGeTol&,AcGeError&) const;
    Adesk::Boolean isPerpendicularTo(const AcGeVector3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isPerpendicularTo(const AcGeVector3d&,const AcGeTol&,AcGeError&) const;
    Adesk::Boolean isUnitLength(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isZeroLength(const AcGeTol& = AcGeContext::gTol) const;
    bool isEqualTo(const AcGeVector3d&,const AcGeTol& = AcGeContext::gTol) const;
    double angleOnPlane(const AcGePlanarEnt&) const;
    double angleTo(const AcGeVector3d&) const;
    double angleTo(const AcGeVector3d&,const AcGeVector3d&) const;
    double dotProduct(const AcGeVector3d&) const;
    double length() const;
    double lengthSqrd() const;
    unsigned int largestElement() const;

    AcGeVector3d operator*(double) const;
    AcGeVector3d operator+(const AcGeVector3d&) const;
    AcGeVector3d operator-() const;
    AcGeVector3d operator-(const AcGeVector3d&) const;
    AcGeVector3d operator/(double) const;
    AcGeVector3d& operator*=(double);
    AcGeVector3d& operator+=(const AcGeVector3d&);
    AcGeVector3d& operator-=(const AcGeVector3d&);
    AcGeVector3d& operator/=(double);
    bool operator!=(const AcGeVector3d&) const;
    bool operator==(const AcGeVector3d&) const;
    double operator[](unsigned int) const;
    double& operator[](unsigned int);
    operator AcGeMatrix3d() const;

    friend AcGeVector3d operator*(const AcGeMatrix3d&,const AcGeVector3d&);
    friend AcGeVector3d operator*(double,const AcGeVector3d&);
};

template<> struct T_AcArrayAllocatorSelector<AcGeVector3d, false> {
  typedef AcArrayMemCopyReallocator<AcGeVector3d> Allocator;
}; //AcGeVector3d can use fast MemCopyReallocator
typedef AcArray< AcGeVector3d, AcArrayMemCopyReallocator<AcGeVector3d> > AcGeVector3dArray;
