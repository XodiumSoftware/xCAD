// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class AcDbAlignment: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAlignment);

    virtual Acad::ErrorStatus getAlignment(AcDbEntity*,const AcArray< AcDbObjectIdArray,AcArrayObjectCopyReallocator<AcDbObjectIdArray> >&,const AcGePoint3d&,const AcGeVector3d&,AcGePoint3d&,AcGeVector3d&) = 0;
};
