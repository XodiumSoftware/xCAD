// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeCurve2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCompositeCurve2d: public AcGeCurve2d
{
public:
    AcGeCompositeCurve2d();
    //BRX START
    ~AcGeCompositeCurve2d();
    //BRX END

    AcGeCompositeCurve2d(const AcGeCompositeCurve2d&);
    AcGeCompositeCurve2d(const AcGeVoidPointerArray&);
    AcGeCompositeCurve2d(const AcGeVoidPointerArray&,const AcGeIntArray&);

    AcGeCompositeCurve2d& setCurveList(const AcGeVoidPointerArray&);
    AcGeCompositeCurve2d& setCurveList(const AcGeVoidPointerArray&,const AcGeIntArray&);
    double globalToLocalParam(double,int&) const;
    double localToGlobalParam(double,int) const;
    void getCurveList(AcGeVoidPointerArray&) const;

    AcGeCompositeCurve2d& operator=(const AcGeCompositeCurve2d&);
};
