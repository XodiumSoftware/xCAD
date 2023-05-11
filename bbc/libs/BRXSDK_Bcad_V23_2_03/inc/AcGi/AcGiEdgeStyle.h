// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmColor.h"

/** _ */
class BRX_IMPORTEXPORT AcGiEdgeStyle: public AcRxObject
{
public:
    enum EdgeModel
    {
        kNoEdges = 0,
        kIsolines,
        kFacetEdges
    };

    enum EdgeModifier
    {
        kNoEdgeModifiers = 0,
        kOverhang = 1,
        kJitter = 2,
        kWidth = 4,
        kColor = 8,
        kHaloGap = 16,
        kAlwaysOnTop = 64,
        kOpacity = 128
    };

    enum EdgeStyle
    {
        kNoEdgeStyle = 0,
        kVisible = 1,
        kSilhouette = 2,
        kObscured = 4,
        kIntersection = 8
    };

    enum EdgeStyleApply
    {
        kDefault = 0,
        kAll
    };

    enum JitterAmount
    {
        kJitterLow = 1,
        kJitterMedium,
        kJitterHigh
    };

    enum Linetype
    {
        kSolid = 1,
        kDashed,
        kDotted,
        kShortDash,
        kMediumDash,
        kLongDash,
        kDoubleShortDash,
        kDoubleMediumDash,
        kDoubleLongDash,
        kMediumLongDash,
        kSparseDot
    };

    ACRX_DECLARE_MEMBERS(AcGiEdgeStyle);

    AcGiEdgeStyle();
    AcGiEdgeStyle(const AcGiEdgeStyle&);
    virtual ~AcGiEdgeStyle();

    virtual AcCmColor& edgeColor();
    virtual AcCmColor& intersectionColor();
    virtual AcCmColor& obscuredColor();
    virtual AcCmColor& silhouetteColor();
    virtual AcGiEdgeStyle& operator=(const AcGiEdgeStyle&);
    virtual bool hidePrecision() const;
    virtual bool isEdgeModifierFlagSet(EdgeModifier) const;
    virtual bool isEdgeStyleFlagSet(EdgeStyle) const;
    virtual bool operator==(const AcGiEdgeStyle&) const;
    virtual const AcCmColor& edgeColor() const;
    virtual const AcCmColor& intersectionColor() const;
    virtual const AcCmColor& obscuredColor() const;
    virtual const AcCmColor& silhouetteColor() const;
    virtual double creaseAngle() const;
    virtual double opacityLevel() const;
    virtual EdgeModel edgeModel() const;
    virtual EdgeStyleApply edgeStyleApply() const;
    virtual int edgeWidth() const;
    virtual int haloGap() const;
    virtual int overhangAmount() const;
    virtual JitterAmount jitterAmount() const;
    virtual Linetype intersectionLinetype() const;
    virtual Linetype obscuredLinetype() const;
    virtual short silhouetteWidth() const;
    virtual unsigned long edgeModifiers() const;
    virtual unsigned long edgeStyles() const;
    virtual unsigned short isolines() const;
    virtual void set(const AcGiEdgeStyle&);
    virtual void setCreaseAngle(double);
    virtual void setEdgeColor(const AcCmColor&,bool);
    virtual void setEdgeModel(EdgeModel);
    virtual void setEdgeModifierFlag(EdgeModifier,bool);
    virtual void setEdgeModifiers(unsigned long);
    virtual void setEdgeStyleApply(EdgeStyleApply);
    virtual void setEdgeStyleFlag(EdgeStyle,bool);
    virtual void setEdgeStyles(unsigned long);
    virtual void setEdgeWidth(int,bool);
    virtual void setHaloGap(int,bool);
    virtual void setHidePrecision(bool);
    virtual void setIntersectionColor(const AcCmColor&);
    virtual void setIntersectionLinetype(Linetype);
    virtual void setIsolines(unsigned short);
    virtual void setJitterAmount(JitterAmount,bool);
    virtual void setObscuredColor(const AcCmColor&);
    virtual void setObscuredLinetype(Linetype);
    virtual void setOpacityLevel(double,bool);
    virtual void setOverhangAmount(int,bool);
    virtual void setSilhouetteColor(const AcCmColor&);
    virtual void setSilhouetteWidth(short);
};
