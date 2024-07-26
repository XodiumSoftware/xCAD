// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
