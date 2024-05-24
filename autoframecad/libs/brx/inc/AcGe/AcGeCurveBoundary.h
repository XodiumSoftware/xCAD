// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeGlobal.h"

class BrxAcGeCurveBoundaryData;

/** _ */
class BRX_IMPORTEXPORT AcGeCurveBoundary
{
public:
    AcGeCurveBoundary();
    AcGeCurveBoundary(const AcGeCurveBoundary&);
    AcGeCurveBoundary(int,const AcGeEntity3d* const*,const AcGeCurve2d* const*,Adesk::Boolean*,Adesk::Boolean*,Adesk::Boolean = Adesk::kTrue);
    ~AcGeCurveBoundary();

    AcGeCurveBoundary& set(int,const AcGeEntity3d* const*,const AcGeCurve2d* const*,Adesk::Boolean*,Adesk::Boolean*,Adesk::Boolean = Adesk::kTrue);
    AcGeCurveBoundary& setToOwnCurves();
    Adesk::Boolean isDegenerate() const;
    Adesk::Boolean isDegenerate(AcGePosition3d&,AcGeCurve2d**) const;
    Adesk::Boolean isOwnerOfCurves() const;
    int numElements() const;
    void getContour(int&,AcGeEntity3d***,AcGeCurve2d***,Adesk::Boolean**,Adesk::Boolean**) const;

    AcGeCurveBoundary& operator=(const AcGeCurveBoundary&);

protected:
    friend BrxAcGeCurveBoundaryData;
    BrxAcGeCurveBoundaryData* m_pBrxImp = nullptr;
};
