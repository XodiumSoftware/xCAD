// Copyright (C) Menhirs NV. All rights reserved.
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
