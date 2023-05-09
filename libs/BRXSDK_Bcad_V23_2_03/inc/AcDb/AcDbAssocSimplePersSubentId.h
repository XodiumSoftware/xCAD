// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbAssocPersSubentId.h"

/** _ */
class BRX_EXPORT AcDbAssocSimplePersSubentId : public AcDbAssocPersSubentId
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAssocSimplePersSubentId);

    AcDbAssocSimplePersSubentId(AcDbSubentId = kNullSubentId);

    void setSubentId(const AcDbSubentId&);

    virtual bool isNull() const override;
    virtual bool isEqualTo(const AcDbEntity*, AcDbDatabase*, const AcDbAssocPersSubentId*) const override;
    virtual AcDb::SubentType subentType(const AcDbEntity*, AcDbDatabase*) const override;

    virtual int transientSubentCount(const AcDbEntity*, AcDbDatabase*) const override;
    virtual Acad::ErrorStatus getTransientSubentIds(const AcDbEntity*, AcDbDatabase*, AcDbSubentIdArray&) const override;

    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const override;

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const override;

    virtual Acad::ErrorStatus copyFrom(const AcRxObject*) override;
    virtual Acad::ErrorStatus audit(AcDbAuditInfo*) override;

    virtual Acad::ErrorStatus release(AcDbEntity*, AcDbDatabase*) const override;
};
