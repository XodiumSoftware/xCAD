// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxOverrule.h"


/** _ */
class BRX_IMPORTEXPORT AcDbPropertiesOverrule : public AcRxOverrule
{
public:
    ACRX_DECLARE_MEMBERS(AcDbPropertiesOverrule);

    AcDbPropertiesOverrule();

    virtual Acad::ErrorStatus getClassID(const AcDbObject*, CLSID*);
    virtual void list(const AcDbEntity*);
};
