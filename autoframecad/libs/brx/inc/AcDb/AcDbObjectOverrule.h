// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxOverrule.h"

class AcDbIdMapping;

/** _ */
class BRX_IMPORTEXPORT AcDbObjectOverrule : public AcRxOverrule
{
public:
    ACRX_DECLARE_MEMBERS(AcDbObjectOverrule);

    AcDbObjectOverrule();

    virtual Acad::ErrorStatus cancel(AcDbObject*);
    virtual Acad::ErrorStatus close(AcDbObject*);
    virtual Acad::ErrorStatus deepClone(const AcDbObject*, AcDbObject*, AcDbObject*&, AcDbIdMapping&, Adesk::Boolean = true);
    virtual Acad::ErrorStatus erase(AcDbObject*, Adesk::Boolean);
    virtual Acad::ErrorStatus open(AcDbObject*, AcDb::OpenMode);
    virtual Acad::ErrorStatus wblockClone(const AcDbObject*, AcRxObject*, AcDbObject*&, AcDbIdMapping&, Adesk::Boolean = true);
};
