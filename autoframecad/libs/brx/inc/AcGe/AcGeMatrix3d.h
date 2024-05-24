// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeMatrix2d.h"
#include "AcGe/AcGePoint3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeMatrix3d
{
public:
    static const AcGeMatrix3d kIdentity;

    double entry[4][4];

    AcGeMatrix3d();
    AcGeMatrix3d(const AcGeMatrix3d&);

    AcGeMatrix2d convertToLocal(AcGeVector3d&,double&) const;
    AcGeMatrix3d inverse() const;
    AcGeMatrix3d transpose() const;
    AcGeMatrix3d& invert();
    AcGeMatrix3d& postMultBy(const AcGeMatrix3d&);
    AcGeMatrix3d& preMultBy(const AcGeMatrix3d&);
    AcGeMatrix3d& setCoordSystem(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGeVector3d&);
    AcGeMatrix3d& setToAlignCoordSys(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGeVector3d&);
    AcGeMatrix3d& setToIdentity();
    AcGeMatrix3d& setToMirroring(const AcGeLine3d&);
    AcGeMatrix3d& setToMirroring(const AcGePlane&);
    AcGeMatrix3d& setToMirroring(const AcGePoint3d&);
    AcGeMatrix3d& setToPlaneToWorld(const AcGePlane&);
    AcGeMatrix3d& setToPlaneToWorld(const AcGeVector3d&);
    AcGeMatrix3d& setToProduct(const AcGeMatrix3d&,const AcGeMatrix3d&);
    AcGeMatrix3d& setToProjection(const AcGePlane&,const AcGeVector3d&);
    AcGeMatrix3d& setToRotation(double,const AcGeVector3d&,const AcGePoint3d& = AcGePoint3d::kOrigin);
    AcGeMatrix3d& setToScaling(double,const AcGePoint3d& = AcGePoint3d::kOrigin);
    AcGeMatrix3d& setToTranslation(const AcGeVector3d&);
    AcGeMatrix3d& setToWorldToPlane(const AcGePlane&);
    AcGeMatrix3d& setToWorldToPlane(const AcGeVector3d&);
    AcGeMatrix3d& setTranslation(const AcGeVector3d&);
    AcGeMatrix3d& transposeIt();
    AcGeVector3d translation() const;
    Adesk::Boolean inverse(AcGeMatrix3d&,double) const;
    Adesk::Boolean isScaledOrtho(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isSingular(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isUniScaledOrtho(const AcGeTol& = AcGeContext::gTol) const;
    bool isEqualTo(const AcGeMatrix3d&,const AcGeTol& = AcGeContext::gTol) const;
    double det() const;
    double norm() const;
    double scale() const;
    void getCoordSystem(AcGePoint3d&,AcGeVector3d&,AcGeVector3d&,AcGeVector3d&) const;

    AcGeMatrix3d operator*(const AcGeMatrix3d&) const;
    AcGeMatrix3d& operator*=(const AcGeMatrix3d&);
    bool operator!=(const AcGeMatrix3d&) const;
    bool operator==(const AcGeMatrix3d&) const;
    double operator()(unsigned int,unsigned int) const;
    double& operator()(unsigned int,unsigned int);

    static AcGeMatrix3d alignCoordSys(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGeVector3d&);
    static AcGeMatrix3d mirroring(const AcGeLine3d&);
    static AcGeMatrix3d mirroring(const AcGePlane&);
    static AcGeMatrix3d mirroring(const AcGePoint3d&);
    static AcGeMatrix3d planeToWorld(const AcGePlane&);
    static AcGeMatrix3d planeToWorld(const AcGeVector3d&);
    static AcGeMatrix3d projection(const AcGePlane&,const AcGeVector3d&);
    static AcGeMatrix3d rotation(double,const AcGeVector3d&,const AcGePoint3d& = AcGePoint3d::kOrigin);
    static AcGeMatrix3d scaling(double,const AcGePoint3d& = AcGePoint3d::kOrigin);
    static AcGeMatrix3d translation(const AcGeVector3d&);
    static AcGeMatrix3d worldToPlane(const AcGePlane&);
    static AcGeMatrix3d worldToPlane(const AcGeVector3d&);
};
