// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbPolyline.h"
#include "AcGi/AcGiClipBoundary.h"
#include "AcGi/AcGiPolyline.h"
#include "AcGi/AcGiLineAttributes.h"

class AcGiGdiDrawObject;
class AcGiImageBGRA32;

typedef enum
{
  kAcGiWorldPosition = 0,
  kAcGiViewportPosition = 1,
  kAcGiScreenPosition = 2,
  kAcGiScreenLocalOriginPosition = 3,
  kAcGiWorldWithScreenOffsetPosition = 4,
} AcGiPositionTransformBehavior;

typedef enum
{
  kAcGiWorldScale = 0,
  kAcGiViewportScale = 1,
  kAcGiScreenScale = 2,
  kAcGiViewportLocalOriginScale = 3,
  kAcGiScreenLocalOriginScale = 4,
} AcGiScaleTransformBehavior;

typedef enum
{
  kAcGiWorldOrientation  = 0,
  kAcGiScreenOrientation = 1,
  kAcGiZAxisOrientation  = 2,
} AcGiOrientationTransformBehavior;

/** _ */
class BRX_IMPORTEXPORT AcGiGeometry: public AcRxObject
{
public:
    enum TransparencyMode
    {
      kTransparencyOff  = 0,
      kTransparency1Bit = 1,
      kTransparency8Bit = 2,
    };

    ACRX_DECLARE_MEMBERS(AcGiGeometry);

    virtual Adesk::Boolean circle(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&) const = 0;
    virtual Adesk::Boolean circle(const AcGePoint3d&,const double,const AcGeVector3d&) const = 0;
    virtual Adesk::Boolean circularArc(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const AcGiArcType = kAcGiArcSimple) const = 0;
    virtual Adesk::Boolean circularArc(const AcGePoint3d&,const double,const AcGeVector3d&,const AcGeVector3d&,const double,const AcGiArcType = kAcGiArcSimple) const = 0;
    virtual Adesk::Boolean draw(AcGiDrawable*) const = 0;
    virtual Adesk::Boolean mesh(const Adesk::UInt32,const Adesk::UInt32,const AcGePoint3d*,const AcGiEdgeData* = NULL,const AcGiFaceData* = NULL,const AcGiVertexData* = NULL,const bool = true) const = 0;
    virtual Adesk::Boolean pline(const AcDbPolyline&,Adesk::UInt32 = 0,Adesk::UInt32 = 0) const = 0;
    virtual Adesk::Boolean polygon(const Adesk::UInt32,const AcGePoint3d*) const = 0;
    virtual Adesk::Boolean polyline(const Adesk::UInt32,const AcGePoint3d*,const AcGeVector3d* = NULL,Adesk::LongPtr = -1) const = 0;
    virtual Adesk::Boolean polypoint(const Adesk::UInt32,const AcGePoint3d*,const AcGeVector3d* = NULL,const Adesk::LongPtr* = NULL) const;
    virtual Adesk::Boolean popModelTransform() = 0;
    virtual Adesk::Boolean pushClipBoundary(AcGiClipBoundary*) = 0;
    virtual Adesk::Boolean pushModelTransform(const AcGeMatrix3d&) = 0;
    virtual Adesk::Boolean pushModelTransform(const AcGeVector3d&) = 0;
    virtual Adesk::Boolean ray(const AcGePoint3d&,const AcGePoint3d&) const = 0;
    virtual Adesk::Boolean shell(const Adesk::UInt32,const AcGePoint3d*,const Adesk::UInt32,const Adesk::Int32*,const AcGiEdgeData* = NULL,const AcGiFaceData* = NULL,const AcGiVertexData* = NULL,const struct resbuf* = NULL,const bool = true) const = 0;
    virtual Adesk::Boolean text(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,const ACHAR*,const Adesk::Int32,const Adesk::Boolean,const AcGiTextStyle&) const = 0;
    virtual Adesk::Boolean text(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,const double,const double,const double,const ACHAR*) const = 0;
    virtual Adesk::Boolean worldLine(const AcGePoint3d*);
    virtual Adesk::Boolean xline(const AcGePoint3d&,const AcGePoint3d&) const = 0;
    virtual void getModelToWorldTransform(AcGeMatrix3d&) const = 0;
    virtual void getWorldToModelTransform(AcGeMatrix3d&) const = 0;
    virtual void popClipBoundary() = 0;
    virtual AcGeMatrix3d pushPositionTransform(AcGiPositionTransformBehavior, const AcGePoint3d&) = 0;
    virtual AcGeMatrix3d pushPositionTransform(AcGiPositionTransformBehavior, const AcGePoint2d&) = 0;
    virtual AcGeMatrix3d pushScaleTransform(AcGiScaleTransformBehavior, const AcGePoint3d&) = 0;
    virtual AcGeMatrix3d pushScaleTransform(AcGiScaleTransformBehavior, const AcGePoint2d&) = 0;
    virtual AcGeMatrix3d pushOrientationTransform(AcGiOrientationTransformBehavior) = 0;

    virtual Adesk::Boolean rowOfDots(int, const AcGePoint3d&, const AcGeVector3d&) const = 0;
    virtual Adesk::Boolean ellipticalArc(const AcGePoint3d&, const AcGeVector3d&,
                                         double, double, double, double, double,
                                         AcGiArcType = kAcGiArcSimple) const = 0;

    virtual Adesk::Boolean image(const AcGiImageBGRA32&, const AcGePoint3d&,
                                 const AcGeVector3d&, const AcGeVector3d&,
                                 AcGiGeometry::TransparencyMode = AcGiGeometry::kTransparency8Bit) const = 0;

    virtual Adesk::Boolean ownerDraw(AcGiGdiDrawObject*, const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&) const;

    virtual Adesk::Boolean polyPolygon(const Adesk::UInt32,
                                       const Adesk::UInt32*,
                                       const AcGePoint3d*,
                                       const Adesk::UInt32*,
                                       const AcGePoint3d*,
                                       const AcCmEntityColor* = NULL,
                                       const AcGiLineType* = NULL,
                                       const AcCmEntityColor* = NULL,
                                       const AcCmTransparency* = NULL) const = 0;

    virtual Adesk::Boolean polyline(const AcGiPolyline&) const = 0;
    virtual Adesk::Boolean polyPolyline(Adesk::UInt32, const AcGiPolyline*) const = 0;

    virtual Adesk::Boolean edge(const AcArray<AcGeCurve2d*>&) const = 0;
};
