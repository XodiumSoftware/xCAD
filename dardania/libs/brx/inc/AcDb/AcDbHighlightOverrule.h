// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
