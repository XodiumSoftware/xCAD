// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeEntity2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeClipBoundary2d: public AcGeEntity2d
{
public:
    AcGeClipBoundary2d();
    AcGeClipBoundary2d(const AcGeClipBoundary2d&);
    AcGeClipBoundary2d(const AcGePoint2dArray&);
    AcGeClipBoundary2d(const AcGePoint2d&,const AcGePoint2d&);

    AcGe::ClipError clipPolygon(const AcGePoint2dArray&,AcGePoint2dArray&,AcGe::ClipCondition&,AcGeIntArray* = NULL) const;
    AcGe::ClipError clipPolyline(const AcGePoint2dArray&,AcGePoint2dArray&,AcGe::ClipCondition&,AcGeIntArray* = NULL) const;
    AcGe::ClipError set(const AcGePoint2d&,const AcGePoint2d&);
    AcGe::ClipError set(const AcGePoint2dArray&);

    AcGeClipBoundary2d& operator=(const AcGeClipBoundary2d&);
};
