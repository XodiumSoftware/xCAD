// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGePoint3d.h"
#include "AcRx/AcRxProtocolReactor.h"

/** _ */
class AcDbBlockInsertionPoints : public AcRxProtocolReactor
{
public:
    ACRX_DECLARE_MEMBERS(AcDbBlockInsertionPoints);

    virtual Acad::ErrorStatus getInsertionPoints(const AcDbBlockTableRecord*,const AcDbBlockReference*,AcGePoint3dArray&,AcGeVector3dArray&) = 0;
};
