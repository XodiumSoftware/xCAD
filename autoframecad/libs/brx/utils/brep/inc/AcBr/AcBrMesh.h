// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrMeshEntity.h"

class AcBrMesh: public AcBrMeshEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcBrMesh);

protected:
    friend class BrxBrMeshEntityImp;

    AcBrMesh();
    AcBrMesh(const AcBrMesh&);
public:
    virtual ~AcBrMesh();

protected:
    AcBrMesh& operator=(const AcBrMesh&);
};
