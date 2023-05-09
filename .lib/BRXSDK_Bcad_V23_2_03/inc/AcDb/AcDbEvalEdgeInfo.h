// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEvalGraph.h"

/** _ */
class BRX_IMPORTEXPORT AcDbEvalEdgeInfo
{
public:
    AcDbEvalEdgeInfo();
    AcDbEvalEdgeInfo(AcDbEvalNodeId,AcDbEvalNodeId,long,unsigned long);

    AcDbEvalNodeId from() const;
    AcDbEvalNodeId to() const;
    bool isInvertible() const;
    bool isSuppressed() const;
    unsigned long refCount() const;

    bool operator==(const AcDbEvalEdgeInfo&) const;
};
