// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbObjectReactor: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbObjectReactor);

protected:
    AcDbObjectReactor();

public:
    virtual void cancelled(const AcDbObject*);
    virtual void copied(const AcDbObject*,const AcDbObject*);
    virtual void erased(const AcDbObject*, Adesk::Boolean);
    virtual void goodbye(const AcDbObject*);
    virtual void modified(const AcDbObject*);
    virtual void modifiedXData(const AcDbObject*);
    virtual void modifyUndone(const AcDbObject*);
    virtual void objectClosed(const AcDbObjectId);
    virtual void openedForModify(const AcDbObject*);
    virtual void reappended(const AcDbObject*);
    virtual void subObjModified(const AcDbObject*,const AcDbObject*);
    virtual void unappended(const AcDbObject*);
};
