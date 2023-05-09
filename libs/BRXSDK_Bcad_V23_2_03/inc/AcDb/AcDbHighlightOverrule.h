// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxOverrule.h"


/** _ */
class BRX_IMPORTEXPORT AcDbHighlightOverrule : public AcRxOverrule
{
public:
    ACRX_DECLARE_MEMBERS(AcDbHighlightOverrule);

    AcDbHighlightOverrule();

    virtual Acad::ErrorStatus highlight(const AcDbEntity*, const AcDbFullSubentPath& = kNullSubent, const Adesk::Boolean = false);
    virtual Acad::ErrorStatus unhighlight(const AcDbEntity*, const AcDbFullSubentPath& = kNullSubent, const Adesk::Boolean = false);
};
