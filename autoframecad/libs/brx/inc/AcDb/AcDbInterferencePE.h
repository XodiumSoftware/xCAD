// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class AcDbInterferencePE: public AcRxObject
{
public:
    enum Flags
    {
        kDefault = 0
    };

    ACRX_DECLARE_MEMBERS(AcDbInterferencePE);

    virtual Acad::ErrorStatus createInterferenceObjects(AcArray<AcDbEntity*>&,AcDbEntity*,AcDbEntity*,unsigned int) const = 0;
};
