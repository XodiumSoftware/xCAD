// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

class AcDbAuditInfo;
class AcDbObject;

/** _ */
class BRX_IMPORTEXPORT AcDbAuditRecreatePE: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAuditRecreatePE);

    virtual bool redirect(AcDbObjectId&,AcDbObjectId,AcRxClass*,AcDbDatabase*,AcDbAuditInfo*);
    virtual bool replace(AcDbObject*&,AcDbObjectId,AcRxClass*,AcDbDatabase*,AcDbAuditInfo*);
};