// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbPlaceHolder: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbPlaceHolder);

    AcDbPlaceHolder();
    virtual ~AcDbPlaceHolder();

    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;

protected:
    virtual Acad::ErrorStatus subWblockClone(AcRxObject*,AcDbObject*&,AcDbIdMapping&,Adesk::Boolean = Adesk::kTrue) const;
};
