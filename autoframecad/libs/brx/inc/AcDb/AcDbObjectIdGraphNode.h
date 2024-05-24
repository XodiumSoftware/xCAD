// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGraphNode.h"
#include "AcDb/AcDbObjectId.h"

/** _ */
class AcDbObjectIdGraphNode: public AcDbGraphNode
{
private:
    AcDbObjectId m_id;

public:
    AcDbObjectIdGraphNode(const AcDbObjectId);
    virtual ~AcDbObjectIdGraphNode();

    AcDbObjectId id() const;
};
