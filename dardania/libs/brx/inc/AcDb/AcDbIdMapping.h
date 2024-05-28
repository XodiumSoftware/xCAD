// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
