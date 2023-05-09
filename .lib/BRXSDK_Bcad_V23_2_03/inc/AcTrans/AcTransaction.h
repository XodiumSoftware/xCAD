// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcTransaction: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcTransaction);

    virtual Acad::ErrorStatus getAllObjects(AcDbVoidPtrArray&) = 0;
    virtual Acad::ErrorStatus getObject(AcDbObject*&,AcDbObjectId,AcDb::OpenMode,bool = false) = 0;
    virtual Acad::ErrorStatus markObjectPageable(AcDbObject*) = 0;
};
