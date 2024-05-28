// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeCurve2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeOffsetCurve2d: public AcGeCurve2d
{
public:
    AcGeOffsetCurve2d(const AcGeCurve2d&,double);
    AcGeOffsetCurve2d(const AcGeOffsetCurve2d&);

    AcGeMatrix2d transformation() const;
    AcGeOffsetCurve2d& setCurve(const AcGeCurve2d&);
    AcGeOffsetCurve2d& setOffsetDistance(double);
    Adesk::Boolean paramDirection() const;
    const AcGeCurve2d* curve() const;
    double offsetDistance() const;

    AcGeOffsetCurve2d& operator=(const AcGeOffsetCurve2d&);
};