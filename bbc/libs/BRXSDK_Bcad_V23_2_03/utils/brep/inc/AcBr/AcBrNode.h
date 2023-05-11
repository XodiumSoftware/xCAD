// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrMeshEntity.h"

class AcBrNode;
class AcGePoint3d;

class AcBrNode: public AcBrMeshEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcBrNode);

    AcBrNode();
    AcBrNode(const AcBrNode&);
    ~AcBrNode();

    AcBr::ErrorStatus getPoint(AcGePoint3d&) const;

    AcBrNode& operator=(const AcBrNode&);
};
