// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

enum AcGiLineType
{
    kLineTypeSolid = 0,
    kDashed,
    kDotted,
    kDash_Dot,
    kShort_Dash,
    kMedium_Dash,
    kLong_Dash,
    kShort_Dash_X2,
    kMedium_Dash_X2,
    kLong_Dash_X2,
    kMedium_Long_Dash,
    kMedium_Dash_Short_Dash_Short_Dash,
    kLong_Dash_Short_Dash,
    kLong_Dash_Dot_Dot,
    kLong_Dash_Dot,
    kMedium_Dash_Dot_Short_Dash_Dot,
    kSparse_Dot,
    kISO_Dash,
    kISO_Dash_Space,
    kISO_Long_Dash_Dot,
    kISO_Long_Dash_Double_Dot,
    kISO_Long_Dash_Triple_Dot,
    kISO_Dot,
    kISO_Long_Dash_Short_Dash,
    kISO_Long_Dash_Double_Short_Dash,
    kISO_Dash_Dot,
    kISO_Double_Dash_Dot,
    kISO_Dash_Double_Dot,
    kISO_Double_Dash_Double_Dot,
    kISO_Dash_Triple_Dot,
    kISO_Double_Dash_Triple_Dot,
    kLineTypeNone,
    kSolid_6_Pixels_Blank_6_Pixels,
    kDense_Dot
};

enum AcGiLineJoinStyle
{
    kMiterJoin = 0,
    kBevelJoin,
    kRoundJoin,
    kDiamondJoin
};

enum AcGiLineEndStyle
{
    kButtCap = 0,
    kSquareCap,
    kRoundCap,
    kDiamondCap
};

enum AcGiLineFillStyle
{
    kFillStyleSolid = 0,
    kCheckerboard,
    kCrosshatch,
    kDiamonds,
    kHorizontal_Bars,
    kSlant_Left,
    kSlant_Right,
    kSquare_Dots,
    kVertical_Bars,
    kUser_Defined
};

/** _ */
class BRX_IMPORTEXPORT AcGiLineAttributes
{
public:
    virtual ~AcGiLineAttributes() {}

    virtual AcGiLineAttributes* clone() const = 0;
    virtual AcGiLineEndStyle getEndstyle() const = 0;
    virtual AcGiLineFillStyle getFillstyle() const = 0;
    virtual AcGiLineJoinStyle getJoinstyle() const = 0;
    virtual AcGiLineType getLinetype() const = 0;
    virtual AcDb::LineWeight getLineweight() const = 0;
    virtual bool hasCustomLineweight() const = 0;
    virtual bool isLinetypeAdaptive() const = 0;
    virtual bool isLineWeightByLayer() const = 0;
    virtual bool isLineweightDefault() const = 0;
    virtual void setCustomLineweight(bool) = 0;
    virtual void setEndstyle(AcGiLineEndStyle) = 0;
    virtual void setFillstyle(AcGiLineFillStyle) = 0;
    virtual void setJoinstyle(AcGiLineJoinStyle) = 0;
    virtual void setLinetype(AcGiLineType) = 0;
    virtual void setLinetypeAdaptive(bool) = 0;
    virtual void setLineweight(AcDb::LineWeight) = 0;
    virtual void setLineWeightByLayer(bool) = 0;
    virtual void setLineweightDefault() = 0;
};
