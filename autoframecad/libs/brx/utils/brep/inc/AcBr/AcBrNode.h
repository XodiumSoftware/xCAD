// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
