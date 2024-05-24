// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"
#include "AcDb/AcDbGlobal.h"
#include "Misc/AcArray.h"
#include "AcDb/AcDbSubentId.h"

class AcDbDatabase;
class AcDbEntity;
class AcDbDwgFiler;
class AcDbAuditInfo;
class AcDbDxfFiler;

/** _ */
class BRX_EXPORT AcDbAssocPersSubentId: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAssocPersSubentId);

    AcDbAssocPersSubentId();
    virtual ~AcDbAssocPersSubentId();

    virtual bool isNull() const = 0;
    virtual bool isEqualTo(const AcDbEntity*, AcDbDatabase*, const AcDbAssocPersSubentId*) const;
    virtual AcDb::SubentType subentType(const AcDbEntity*, AcDbDatabase*) const = 0;

    virtual int transientSubentCount(const AcDbEntity*, AcDbDatabase*) const;
    virtual Acad::ErrorStatus getTransientSubentIds(const AcDbEntity*, AcDbDatabase*, AcDbSubentIdArray&) const;

    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual Acad::ErrorStatus mirror(const AcDbEntity*, AcDbDatabase*);
    virtual Acad::ErrorStatus audit(AcDbAuditInfo*);

    virtual Acad::ErrorStatus release(AcDbEntity*, AcDbDatabase*) const;

    static Acad::ErrorStatus createObjectAndDwgInFields(AcDbDatabase*, AcDbDwgFiler*,  AcDbAssocPersSubentId*&);
    static Acad::ErrorStatus createObjectAndDxfInFields(AcDbDxfFiler*, AcDbAssocPersSubentId*&);
};
