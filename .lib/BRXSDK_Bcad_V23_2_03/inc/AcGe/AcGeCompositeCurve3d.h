// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeCurve3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCompositeCurve3d: public AcGeCurve3d
{
public:
    AcGeCompositeCurve3d();
    //BRX START
    ~AcGeCompositeCurve3d();
    //BRX END

    AcGeCompositeCurve3d(const AcGeCompositeCurve3d&);
    AcGeCompositeCurve3d(const AcGeVoidPointerArray&);
    AcGeCompositeCurve3d(const AcGeVoidPointerArray&,const AcGeIntArray&);

    AcGeCompositeCurve3d& setCurveList(const AcGeVoidPointerArray&);
    AcGeCompositeCurve3d& setCurveList(const AcGeVoidPointerArray&,const AcGeIntArray&);
    double globalToLocalParam(double,int&) const;
    double localToGlobalParam(double,int) const;
    void getCurveList(AcGeVoidPointerArray&) const;

    AcGeCompositeCurve3d& operator=(const AcGeCompositeCurve3d&);
};
