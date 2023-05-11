// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmGlobal.h"
#include "AcCm/AcCmTransparency.h"
#include "AcDb/AcDbObjectId.h"
#include "AcGi/AcGiGlobal.h"
#include "AcRx/AcRxObject.h"

class AcGiFill;

/** _ */
class BRX_IMPORTEXPORT AcGiSubEntityTraits: public AcRxObject
{
public:
    enum DrawFlags
    {
        kNoDrawFlags                     = 0x0,
        kDrawBackfaces                   = 0x1,
        kDrawHatchGroup                  = 0x2,
        kDrawFrontfacesOnly              = 0x4,
        kDrawGradientFill                = 0x8,
        kDrawSolidFill                   = 0x10,
        kDrawNoLineWeight                = 0x20,
        kDrawNoOptimization              = 0x40,
        kDrawUseAcGiEntityForDgnLineType = 0x80,
        kDrawFillTextBoundaryStart       = 0x100,
        kDrawFillTextBoundaryEnd         = 0x200,
        kDrawFillSelectionWindow         = 0x400,
        kDrawNoForceByLayer              = 0x800,
        
        // BricsCAD / Teigha specific flags (the range before 0x8000 is reserved)
        kDrawContourFill                 = 0x08000,     // Teigha(R) for .dgn files specific.
        kDisableLayoutCache              = 0x10000,     // Disable metafile caching for layout switching.
        kDrawBoundaryForClipping         = 0x20000,     // Draw (rough) boundary of object to be checked
                                                        // when clipping is performed, set by vectorizer.
        kDrawBoundaryForClippingDrw      = 0x40000,     // Draw (rough) boundary of object to be checked
                                                        // when clipping is performed, set by a drawable.
        kClipSetIsEmpty                  = 0x80000,
        kDrawPolygonFill                 = 0x100000,    // Fill in all modes if FillAlways mode enabled.
        kExcludeFromViewExt              = 0x200000,    // Don't use extents of the entity when calculating total extents.
        kDrawDgLsPolyWithoutBreaks       = 0x400000,    // Draw polylines/polygons with Dgn Line Style without segmentation.
        kPolygonProcessing               = 0x800000,    // Polygon filling logic must be applied for shell primitive.
        kDisableAutoGenerateNormals      = 0x1000000,   // Avoid automatic generation of normals for mesh/shell primitives.
        kDisableFillModeCheck            = 0x2000000,   // Avoid checking of OdGiContext::fillMode during filling of geometry primitives.
        kDrawUnderlayReference           = 0x4000000,   // Draw underlay reference object.
        kAuxModelerGeom                  = 0x8000000,
        kDisableDisplayClipping          = 0x10000000,
        kDisableColorMerge               = 0x20000000,
        // BRX specific; should be ignored by BRX applications for custom entities in their worldDraw/viewportDraw fucntions
        kRegenTypeDependent2dDraw        = 0x40000000,  // can follow after kAcGiRenderCommand, to generate edges and isolines
    };

    enum ShadowFlags
    {
        kShadowsCastAndReceive = 0,
        kShadowsDoesNotCast    = 1,
        kShadowsDoesNotReceive = 2,
        kShadowsIgnore = kShadowsDoesNotCast | kShadowsDoesNotReceive
    };

    ACRX_DECLARE_MEMBERS(AcGiSubEntityTraits);

    AcGiSubEntityTraits();
    AcGiSubEntityTraits(const AcGiSubEntityTraits&);

    virtual Acad::ErrorStatus edgeStyleOverride(AcGiEdgeStyleMask&,AcGiEdgeStyle&) const;
    virtual Acad::ErrorStatus setDrawFlags(Adesk::UInt32);
    virtual Acad::ErrorStatus setEdgeStyleOverride(AcGiEdgeStyleMask,const AcGiEdgeStyle&);
    virtual Acad::ErrorStatus setShadowFlags(ShadowFlags);
    virtual AcCmEntityColor trueColor() const = 0;
    virtual AcDb::LineWeight lineWeight() const = 0;
    virtual AcDb::PlotStyleNameType getPlotStyleNameId(AcDbObjectId&) const;
    virtual AcDbObjectId layerId() const = 0;
    virtual AcDbObjectId lineTypeId() const = 0;
    virtual AcDbObjectId materialId() const;
    virtual AcDbObjectId visualStyle() const;
    virtual AcGiFillType fillType() const = 0;
    virtual Adesk::UInt16 color() const = 0;
    virtual Adesk::UInt32 drawFlags() const;
    virtual bool sectionable() const;
    virtual bool selectionGeom() const;
    virtual const AcGiMapper* mapper() const;
    virtual double lineTypeScale() const = 0;
    virtual double thickness() const = 0;
    virtual ShadowFlags shadowFlags() const;
    virtual void setColor(const Adesk::UInt16) = 0;
    virtual void setFillType(const AcGiFillType) = 0;
    virtual void setLayer(const AcDbObjectId) = 0;
    virtual void setLineType(const AcDbObjectId) = 0;
    virtual void setLineTypeScale(double = 1.0) = 0;
    virtual void setLineWeight(const AcDb::LineWeight) = 0;
    virtual void setMapper(const AcGiMapper*);
    virtual void setMaterial(const AcDbObjectId);
    virtual void setPlotStyleName(AcDb::PlotStyleNameType,const AcDbObjectId& = AcDbObjectId::kNull);
    virtual void setSectionable(bool);
    virtual void setSelectionGeom(bool);
    virtual void setSelectionMarker(const Adesk::LongPtr) = 0;
    virtual void setThickness(double) = 0;
    virtual void setTrueColor(const AcCmEntityColor&) = 0;
    virtual void setVisualStyle(const AcDbObjectId);

    virtual AcCmTransparency transparency() const;
    virtual void setTransparency(const AcCmTransparency&);

    virtual const AcGiFill* fill() const;
    virtual void setFill(const AcGiFill*);
};
