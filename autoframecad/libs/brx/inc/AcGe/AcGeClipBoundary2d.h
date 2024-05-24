// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
