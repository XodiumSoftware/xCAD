// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_IMPORTEXPORT AcDbDynamicUCSPE: public AcRxObject
{
public:
    enum Flags
    {
        kDefault = 0
    };

    ACRX_DECLARE_MEMBERS(AcDbDynamicUCSPE);

    virtual Acad::ErrorStatus getCandidatePlanes(AcArray<AcGePlane>&,double&,double&,double&,AcDbEntity*,const AcDbSubentId&,const AcGePlane&,Flags = kDefault) const = 0;
};
