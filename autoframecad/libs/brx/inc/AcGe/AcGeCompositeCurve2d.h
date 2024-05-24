// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
