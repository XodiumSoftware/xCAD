// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
