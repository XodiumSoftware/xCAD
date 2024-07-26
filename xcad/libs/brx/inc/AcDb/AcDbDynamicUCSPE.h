// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
