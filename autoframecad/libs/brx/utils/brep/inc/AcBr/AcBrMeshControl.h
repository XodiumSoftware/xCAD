// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrGlobal.h"

class AcRxObject;

class AcBrMeshControl: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcBrMeshControl);

protected:
    friend class BrxBrMeshControlImp;
    class BrxBrMeshControlImp* m_pBrxImp;

    AcBrMeshControl();
    AcBrMeshControl(const AcBrMeshControl&);
public:
    virtual ~AcBrMeshControl();

    AcBr::ErrorStatus getAngTol(double&) const;
    AcBr::ErrorStatus getDistTol(double&) const;
    AcBr::ErrorStatus getMaxNodeSpacing(double&) const;
    AcBr::ErrorStatus getMaxSubdivisions(Adesk::UInt32&) const;
    AcBr::ErrorStatus setAngTol(const double& = 0.0);
    AcBr::ErrorStatus setDistTol(const double& = 0.0);
    AcBr::ErrorStatus setMaxNodeSpacing(const double& = 0.0);
    AcBr::ErrorStatus setMaxSubdivisions(const Adesk::UInt32& = 0);
    Adesk::Boolean isEqualTo(const AcRxObject*) const;

protected:
    AcBrMeshControl& operator=(const AcBrMeshControl&);
};
