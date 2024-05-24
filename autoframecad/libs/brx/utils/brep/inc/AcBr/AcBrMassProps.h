// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGePoint3d.h"
#include "AcGe/AcGeVector3d.h"

struct AcBrMassProps
{
    double mVolume;
    double mMass;
    AcGePoint3d mCentroid;
    double mRadiiGyration[3];
    double mMomInertia[3];
    double mProdInertia[3];
    double mPrinMoments[3];
    AcGeVector3d mPrinAxes[3];
};
