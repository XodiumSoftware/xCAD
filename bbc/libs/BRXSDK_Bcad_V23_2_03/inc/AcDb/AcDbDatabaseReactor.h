// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectId.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbDatabaseReactor: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbDatabaseReactor);

    virtual void goodbye(const AcDbDatabase*);
    virtual void headerSysVarChanged(const AcDbDatabase*,const ACHAR*,Adesk::Boolean);
    virtual void headerSysVarWillChange(const AcDbDatabase*,const ACHAR*);
    virtual void objectAppended(const AcDbDatabase*,const AcDbObject*);
    virtual void objectErased(const AcDbDatabase*,const AcDbObject*,Adesk::Boolean = Adesk::kTrue);
    virtual void objectModified(const AcDbDatabase*,const AcDbObject*);
    virtual void objectOpenedForModify(const AcDbDatabase*,const AcDbObject*);
    virtual void objectReAppended(const AcDbDatabase*,const AcDbObject*);
    virtual void objectUnAppended(const AcDbDatabase*,const AcDbObject*);
    virtual void proxyResurrectionCompleted(const AcDbDatabase*,const ACHAR*,AcDbObjectIdArray&);
};
