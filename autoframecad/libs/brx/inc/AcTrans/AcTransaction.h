// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcTransaction: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcTransaction);

    Acad::ErrorStatus getAllObjects(AcDbVoidPtrArray&); // deprecated
    virtual Acad::ErrorStatus getAllObjects(AcArray<AcDbObject*>&) = 0; 
    virtual Acad::ErrorStatus getObject(AcDbObject*&,AcDbObjectId,AcDb::OpenMode,bool = false) = 0;
    virtual Acad::ErrorStatus markObjectPageable(AcDbObject*) = 0;
};
