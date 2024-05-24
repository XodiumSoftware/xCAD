// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeCurve2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeLinearEnt2d: public AcGeCurve2d
{
protected:
    AcGeLinearEnt2d();
    AcGeLinearEnt2d(const AcGeLinearEnt2d&);

public:
    AcGePoint2d pointOnLine() const;
    AcGeVector2d direction() const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt2d&,AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isColinearTo(const AcGeLinearEnt2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isParallelTo(const AcGeLinearEnt2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isPerpendicularTo(const AcGeLinearEnt2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean overlap(const AcGeLinearEnt2d&,AcGeLinearEnt2d*&,const AcGeTol& = AcGeContext::gTol) const;
    void getLine(AcGeLine2d&) const;
    void getPerpLine(const AcGePoint2d&,AcGeLine2d&) const;

    AcGeLinearEnt2d& operator=(const AcGeLinearEnt2d&);
};
