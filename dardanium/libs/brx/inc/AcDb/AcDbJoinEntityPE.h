// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbJoinEntityPE : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbJoinEntityPE);

    virtual Acad::ErrorStatus joinEntity(AcDbEntity*, AcDbEntity*) const = 0;
    virtual Acad::ErrorStatus joinEntities(AcDbEntity*, const AcArray<AcDbEntity*>&, AcGeIntArray&) const = 0;
};
