// Copyright (C) Menhirs NV. All rights reserved.
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