// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrMeshControl.h"

class AcBrMesh2dControl: public AcBrMeshControl
{
public:
    ACRX_DECLARE_MEMBERS(AcBrMesh2dControl);

    AcBrMesh2dControl();
    AcBrMesh2dControl(const AcBrMesh2dControl&);
    ~AcBrMesh2dControl();

    AcBr::ErrorStatus getElementShape(AcBr::Element2dShape&) const;
    AcBr::ErrorStatus getMaxAspectRatio(double&) const;
    AcBr::ErrorStatus setElementShape(const AcBr::Element2dShape& = AcBr::kDefault);
    AcBr::ErrorStatus setMaxAspectRatio(const double& = 0.0);

    AcBrMesh2dControl& operator=(const AcBrMesh2dControl&);
};