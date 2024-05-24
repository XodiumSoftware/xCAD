// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxOverrule.h"


/** _ */
class BRX_IMPORTEXPORT AcDbTransformOverrule : public AcRxOverrule
{
public:
    ACRX_DECLARE_MEMBERS(AcDbTransformOverrule);

    AcDbTransformOverrule();

    virtual Adesk::Boolean cloneMeForDragging(AcDbEntity*);
    virtual Acad::ErrorStatus explode(const AcDbEntity*, AcDbVoidPtrArray&);
    virtual Acad::ErrorStatus getTransformedCopy(const AcDbEntity*, const AcGeMatrix3d&, AcDbEntity*&);
    virtual bool hideMeForDragging(const AcDbEntity*);
    virtual Acad::ErrorStatus transformBy(AcDbEntity*, const AcGeMatrix3d&);
};
