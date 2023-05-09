// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcAp/AcApGlobal.h"
#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

#include "AcEd/AcEdInputPoint.h"
#include "AcEd/AcEdInputPointMonitorResult.h"

class AcGeCurve3d;
class AcGePoint3d;
class AcGiViewportDraw;
class AcApDocument;
class AcDbCustomOsnapMode;

/** _ */
class BRX_IMPORTEXPORT AcEdInputPointMonitor: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcEdInputPointMonitor);

    virtual Acad::ErrorStatus monitorInputPoint(
        bool&,
        ACHAR*&,
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

    virtual Acad::ErrorStatus monitorInputPoint(const AcEdInputPoint&, AcEdInputPointMonitorResult&);

    virtual bool excludeFromOsnapCalculation(const AcDbObjectIdArray&, Adesk::GsMarker);
};
