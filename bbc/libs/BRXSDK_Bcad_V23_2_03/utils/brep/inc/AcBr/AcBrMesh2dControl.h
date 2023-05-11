// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
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