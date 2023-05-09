// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbIdPair.h"
#include "AcRx/AcRxObject.h"


/** _ */
class BRX_IMPORTEXPORT AcDbIdMapping: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbIdMapping);

    AcDbIdMapping();
private:
    AcDbIdMapping(const AcDbIdMapping&);
public:
    virtual ~AcDbIdMapping();

    virtual Acad::ErrorStatus assign(const AcDbIdPair&);
    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual bool change(const AcDbIdPair&);
    virtual bool compute(AcDbIdPair&) const;
    virtual bool del(AcDbObjectId);

    Acad::ErrorStatus destDb(AcDbDatabase*&) const;
    Acad::ErrorStatus origDb(AcDbDatabase*&) const;
    Acad::ErrorStatus setDestDb(AcDbDatabase*);
    AcDb::DeepCloneType deepCloneContext() const;
    AcDb::DuplicateRecordCloning duplicateRecordCloning() const;
};
