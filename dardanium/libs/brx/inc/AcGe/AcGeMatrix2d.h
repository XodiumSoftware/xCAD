// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGePoint2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeMatrix2d
{
public:
    static const AcGeMatrix2d kIdentity;

    double entry[3][3];

    AcGeMatrix2d();
    AcGeMatrix2d(const AcGeMatrix2d&);

    AcGeMatrix2d inverse() const;
    AcGeMatrix2d transpose() const;
    AcGeMatrix2d& invert();
    AcGeMatrix2d& postMultBy(const AcGeMatrix2d&);
    AcGeMatrix2d& preMultBy(const AcGeMatrix2d&);
    AcGeMatrix2d& setCoordSystem(const AcGePoint2d&,const AcGeVector2d&,const AcGeVector2d&);
    AcGeMatrix2d& setToAlignCoordSys(const AcGePoint2d&,const AcGeVector2d&,const AcGeVector2d&,const AcGePoint2d&,const AcGeVector2d&,const AcGeVector2d&);
    AcGeMatrix2d& setToIdentity();
    AcGeMatrix2d& setToMirroring(const AcGeLine2d&);
    AcGeMatrix2d& setToMirroring(const AcGePoint2d&);
    AcGeMatrix2d& setToProduct(const AcGeMatrix2d&,const AcGeMatrix2d&);
    AcGeMatrix2d& setToRotation(double,const AcGePoint2d& = AcGePoint2d::kOrigin);
    AcGeMatrix2d& setToScaling(double,const AcGePoint2d& = AcGePoint2d::kOrigin);
    AcGeMatrix2d& setToTranslation(const AcGeVector2d&);
    AcGeMatrix2d& setTranslation(const AcGeVector2d&);
    AcGeMatrix2d& transposeIt();
    AcGeVector2d translation() const;
    Adesk::Boolean isConformal(double&,double&,Adesk::Boolean&,AcGeVector2d&) const;
    Adesk::Boolean isScaledOrtho(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isSingular(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isUniScaledOrtho(const AcGeTol& = AcGeContext::gTol) const;
    bool isEqualTo(const AcGeMatrix2d&,const AcGeTol& = AcGeContext::gTol) const;
    double det() const;
    double scale();
    void getCoordSystem(AcGePoint2d&,AcGeVector2d&,AcGeVector2d&) const;

    AcGeMatrix2d operator*(const AcGeMatrix2d&) const;
    AcGeMatrix2d& operator*=(const AcGeMatrix2d&);
    bool operator!=(const AcGeMatrix2d&) const;
    bool operator==(const AcGeMatrix2d&) const;
    double operator()(unsigned int,unsigned int) const;
    double& operator()(unsigned int,unsigned int);

    static AcGeMatrix2d alignCoordSys(const AcGePoint2d&,const AcGeVector2d&,const AcGeVector2d&,const AcGePoint2d&,const AcGeVector2d&,const AcGeVector2d&);
    static AcGeMatrix2d mirroring(const AcGeLine2d&);
    static AcGeMatrix2d mirroring(const AcGePoint2d&);
    static AcGeMatrix2d rotation(double,const AcGePoint2d& = AcGePoint2d::kOrigin);
    static AcGeMatrix2d scaling(double,const AcGePoint2d& = AcGePoint2d::kOrigin);
    static AcGeMatrix2d translation(const AcGeVector2d&);
};
