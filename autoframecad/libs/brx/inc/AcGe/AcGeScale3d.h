// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcGeScale3d
{
public:
    static const AcGeScale3d kIdentity;

    double sx;
    double sy;
    double sz;

    AcGeScale3d();
    AcGeScale3d(double);
    AcGeScale3d(double,double,double);
    AcGeScale3d(const AcGeScale3d&);

    AcGeScale3d inverse() const;
    AcGeScale3d& extractScale(const AcGeMatrix3d&);
    AcGeScale3d& invert();
    AcGeScale3d& postMultBy(const AcGeScale3d&);
    AcGeScale3d& preMultBy(const AcGeScale3d&);
    AcGeScale3d& removeScale(AcGeMatrix3d&);
    AcGeScale3d& set(double,double,double);
    AcGeScale3d& setToProduct(const AcGeScale3d&,const AcGeScale3d&);
    AcGeScale3d& setToProduct(const AcGeScale3d&,double);
    Adesk::Boolean isProportional(const AcGeTol& = AcGeContext::gTol) const;
    bool isEqualTo(const AcGeScale3d&,const AcGeTol& = AcGeContext::gTol) const;
    void getMatrix(AcGeMatrix3d&) const;

    AcGeScale3d operator*(const AcGeScale3d&) const;
    AcGeScale3d operator*(double) const;
    AcGeScale3d& operator*=(const AcGeScale3d&);
    AcGeScale3d& operator*=(double);
    bool operator!=(const AcGeScale3d&) const;
    bool operator==(const AcGeScale3d&) const;
    double operator[](unsigned int) const;
    double& operator[](unsigned int);
    operator AcGeMatrix3d() const;

    friend AcGeScale3d operator*(double,const AcGeScale3d&);
};
