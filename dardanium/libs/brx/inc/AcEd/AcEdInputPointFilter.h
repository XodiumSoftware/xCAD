// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcAp/AcApGlobal.h"
#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

#include "AcEd/AcEdInputPoint.h"
#include "AcEd/AcEdInputPointFilterResult.h"

class AcGeCurve3d;
class AcGePoint3d;
class AcGiViewportDraw;

/** _ */
class BRX_IMPORTEXPORT AcEdInputPointFilter: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcEdInputPointFilter);

    virtual Acad::ErrorStatus processInputPoint(
        bool&,
        AcGePoint3d&,
        bool&,
        bool&,
        ACHAR*&,
        bool&,
        AcGiViewportDraw*,
        AcApDocument*,
        bool,
        int,
        const AcGePoint3d&,
        const AcGePoint3d&,
        const AcGePoint3d&,
        const AcGePoint3d&,
        const AcGePoint3d&,
        AcDb::OsnapMask,
        const AcArray<AcDbCustomOsnapMode*>&,
        AcDb::OsnapMask,
        const AcArray<AcDbCustomOsnapMode*>&,
        const AcDbObjectIdArray&,
        const AcArray< AcDbObjectIdArray,AcArrayObjectCopyReallocator<AcDbObjectIdArray> >&,
        const AcArray<Adesk::GsMarker>&,
        const AcDbObjectIdArray&,
        const AcArray< AcDbObjectIdArray,AcArrayObjectCopyReallocator<AcDbObjectIdArray> >&,
        const AcArray<Adesk::GsMarker>&,
        const AcArray<AcGeCurve3d*>&,
        const AcGePoint3d&,
        const ACHAR*);

    virtual Acad::ErrorStatus processInputPoint(const AcEdInputPoint&, AcEdInputPointFilterResult&);

    virtual AcEdInputPointFilter* revokeInputFilter(AcEdInputPointFilter*);
};
