// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxOverrule.h"


/** _ */
class BRX_IMPORTEXPORT AcDbVisibilityOverrule : public AcRxOverrule
{
public:
    ACRX_DECLARE_MEMBERS(AcDbVisibilityOverrule);

    AcDbVisibilityOverrule();

    virtual Acad::ErrorStatus setVisibility(AcDbEntity*, AcDb::Visibility, Adesk::Boolean = true);
    virtual AcDb::Visibility visibility(const AcDbEntity*);
};
