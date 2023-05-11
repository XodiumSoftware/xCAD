// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxOverrule.h"


/** _ */
class BRX_IMPORTEXPORT AcDbOsnapOverrule : public AcRxOverrule
{
public:
    ACRX_DECLARE_MEMBERS(AcDbOsnapOverrule);

    AcDbOsnapOverrule();

    virtual Acad::ErrorStatus getOsnapPoints(const AcDbEntity*, AcDb::OsnapMode, Adesk::GsMarker, const AcGePoint3d&,
        const AcGePoint3d&, const AcGeMatrix3d&, AcGePoint3dArray&, AcDbIntArray&);
    virtual Acad::ErrorStatus getOsnapPoints(const AcDbEntity*, AcDb::OsnapMode, Adesk::GsMarker, const AcGePoint3d&,
        const AcGePoint3d&, const AcGeMatrix3d&, AcGePoint3dArray&, AcDbIntArray&, const AcGeMatrix3d&);
    virtual bool isContentSnappable(const AcDbEntity*);
};
