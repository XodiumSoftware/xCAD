// Copyright (C) Menhirs NV. All rights reserved.
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
