// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
    virtual void objectErased(const AcDbDatabase*,const AcDbObject*,Adesk::Boolean);
    virtual void objectModified(const AcDbDatabase*,const AcDbObject*);
    virtual void objectOpenedForModify(const AcDbDatabase*,const AcDbObject*);
    virtual void objectReAppended(const AcDbDatabase*,const AcDbObject*);
    virtual void objectUnAppended(const AcDbDatabase*,const AcDbObject*);
    virtual void proxyResurrectionCompleted(const AcDbDatabase*,const ACHAR*,AcDbObjectIdArray&);
};
