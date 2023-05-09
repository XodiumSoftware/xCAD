// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
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
