// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrBrep;
class AcBrComplex;

class AcBrBrepComplexTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrBrepComplexTraverser);

    AcBrBrepComplexTraverser();
    AcBrBrepComplexTraverser(const AcBrBrepComplexTraverser&);
    ~AcBrBrepComplexTraverser();

    AcBr::ErrorStatus getBrep(AcBrBrep&) const;
    AcBr::ErrorStatus getComplex(AcBrComplex&) const;
    AcBr::ErrorStatus setBrep(const AcBrBrep&);
    AcBr::ErrorStatus setBrepAndComplex(const AcBrComplex&);
    AcBr::ErrorStatus setComplex(const AcBrComplex&);

    AcBrBrepComplexTraverser& operator=(const AcBrBrepComplexTraverser&);
};