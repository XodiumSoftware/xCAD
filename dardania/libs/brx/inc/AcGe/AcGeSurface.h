// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeEntity3d.h"
#include "AcGe/AcGeInterval.h"

/** _ */
class BRX_IMPORTEXPORT AcGeSurface: public AcGeEntity3d
{
protected:
    AcGeSurface();
    AcGeSurface(const AcGeSurface&);

public:
    AcGePoint2d paramOf(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    AcGePoint3d closestPointTo(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    AcGePoint3d evalPoint(const AcGePoint2d&) const;
    AcGePoint3d evalPoint(const AcGePoint2d&,int,AcGeVector3dArray&) const;
    AcGePoint3d evalPoint(const AcGePoint2d&,int,AcGeVector3dArray&,AcGeVector3d&) const;
    AcGeSurface& reverseNormal();
    Adesk::Boolean isClosedInU(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isClosedInV(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isNormalReversed() const;
    Adesk::Boolean isOn(const AcGePoint3d&,AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOn(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    double distanceTo(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    void getClosestPointTo(const AcGePoint3d&,AcGePointOnSurface&,const AcGeTol& = AcGeContext::gTol) const;
    void getEnvelope(AcGeInterval&,AcGeInterval&) const;

    AcGeSurface& operator=(const AcGeSurface&);
};
