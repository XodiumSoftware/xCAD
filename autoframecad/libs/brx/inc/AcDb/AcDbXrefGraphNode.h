// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGraphNode.h"
#include "AcDb/AcDbObjectId.h"

/** _ */
class BRX_IMPORTEXPORT AcDbXrefGraphNode: public AcDbGraphNode
{
public:
    AcDbXrefGraphNode(const ACHAR* = NULL,const AcDbObjectId& = AcDbObjectId::kNull,AcDbDatabase* = NULL,AcDb::XrefStatus = AcDb::kXrfResolved);
    virtual ~AcDbXrefGraphNode();

    Acad::ErrorStatus setName(const ACHAR*);
    AcDb::XrefNotificationStatus xrefNotificationStatus() const;
    AcDb::XrefStatus xrefStatus() const;
    AcDbDatabase* database() const;
    AcDbObjectId btrId() const;
    bool isNested() const;
    const ACHAR* name() const;
    void setBtrId(const AcDbObjectId&);
    void setDatabase(AcDbDatabase*);
    void setxData(void*);
    void setXrefNotificationStatus(AcDb::XrefNotificationStatus);
    void setXrefStatus(AcDb::XrefStatus);
    void* xData();
};
