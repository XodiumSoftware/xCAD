// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeGlobal.h"

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
};