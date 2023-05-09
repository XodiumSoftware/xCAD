// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcAp/AcApGlobal.h"
#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

class AcGePoint3d;
class AcGiViewportDraw;
class AcEdInputPointImp;

/** _ */
class BRX_IMPORTEXPORT AcEdInputPoint
{
public:
    const AcArray<AcDbCustomOsnapMode*>& customOsnapModes() const;
    const AcArray<AcDbCustomOsnapMode*>& customOsnapOverrides() const;

    const AcDb::OsnapMask osnapMask() const;
    const AcDb::OsnapMask osnapOverrides() const;

    const AcGePoint3d& osnappedPoint() const;
    const AcGePoint3d& cartesianSnappedPoint() const;
    const AcGePoint3d& grippedPoint() const;
    const AcGePoint3d& rawPoint() const;
    const AcGePoint3d& lastPoint() const;
    const AcGePoint3d& computedPoint() const;

    const AcArray<Adesk::GsMarker>& keyPointGsSelectionMark() const;
    const AcArray<Adesk::GsMarker>& gsSelectionMark() const;

    const AcDbObjectIdArray& keyPointEntities() const;
    const AcDbObjectIdArray& pickedEntities() const;

    const AcArray<AcGeCurve3d*>& alignmentPaths() const;

    const AcArray< AcDbObjectIdArray, AcArrayObjectCopyReallocator< AcDbObjectIdArray > >& nestedPickedEntities() const;
    const AcArray< AcDbObjectIdArray, AcArrayObjectCopyReallocator< AcDbObjectIdArray > >& nestedKeyPointEntities() const;

    AcGiViewportDraw* drawContext() const;
    const ACHAR* tooltipString() const;
    AcApDocument* document() const;
    bool pointComputed() const;
    int  history() const;

private:
    AcEdInputPoint();
    AcEdInputPoint(const AcEdInputPoint&);
    AcEdInputPoint& operator=(const AcEdInputPoint&);

private:
    friend class AcEdInputPointImp;
    AcEdInputPoint(AcEdInputPointImp*);
    AcEdInputPointImp* m_pBrxImp;
};
