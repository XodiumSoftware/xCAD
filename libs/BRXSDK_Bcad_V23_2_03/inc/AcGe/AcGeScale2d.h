// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcGeScale2d
{
public:
    static const AcGeScale2d kIdentity;

    double sx;
    double sy;

    AcGeScale2d();
    AcGeScale2d(double);
    AcGeScale2d(double,double);
    AcGeScale2d(const AcGeScale2d&);

    AcGeScale2d inverse() const;
    AcGeScale2d& extractScale(const AcGeMatrix2d&);
    AcGeScale2d& invert();
    AcGeScale2d& postMultBy(const AcGeScale2d&);
    AcGeScale2d& preMultBy(const AcGeScale2d&);
    AcGeScale2d& removeScale(AcGeMatrix2d&);
    AcGeScale2d& set(double,double);
    AcGeScale2d& setToProduct(const AcGeScale2d&,const AcGeScale2d&);
    AcGeScale2d& setToProduct(const AcGeScale2d&,double);
    Adesk::Boolean isProportional(const AcGeTol& = AcGeContext::gTol) const;
    bool isEqualTo(const AcGeScale2d&,const AcGeTol& = AcGeContext::gTol) const;
    void getMatrix(AcGeMatrix2d&) const;

    AcGeScale2d operator*(const AcGeScale2d&) const;
    AcGeScale2d operator*(double) const;
    AcGeScale2d& operator*=(const AcGeScale2d&);
    AcGeScale2d& operator*=(double);
    bool operator!=(const AcGeScale2d&) const;
    bool operator==(const AcGeScale2d&) const;
    double operator[](unsigned int) const;
    double& operator[](unsigned int);
    operator AcGeMatrix2d() const;
    operator AcGeScale3d() const;

    friend AcGeScale2d operator*(double,const AcGeScale2d&);
};
