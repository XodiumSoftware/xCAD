// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiDisplayStyle.h"
#include "AcGi/AcGiEdgeStyle.h"
#include "AcGi/AcGiFaceStyle.h"
#include "AcGi/AcGiVariant.h"

namespace AcGiVisualStyleOperations
{
    enum Operation
    {
        kInvalidOperation = -1,
        kInherit          = 0,
        kSet              = 1,
        kDisable          = 2,
        kEnable           = 3,
    };
} // namespace AcGiVisualStyleOperations

namespace AcGiVisualStyleProperties
{
    enum Property
    {
        kInvalidProperty = -1,
        // Face properties
        kFaceLightingModel = 0,
        kFaceLightingQuality,
        kFaceColorMode,
        kFaceModifiers,
        kFaceOpacity,
        kFaceSpecular,
        kFaceMonoColor,
        // Edge properties
        kEdgeModel,    
        kEdgeStyles,    
        kEdgeIntersectionColor,  
        kEdgeObscuredColor,    
        kEdgeObscuredLinePattern,  
        kEdgeIntersectionLinePattern,
        kEdgeCreaseAngle,
        kEdgeModifiers,
        kEdgeColor,
        kEdgeOpacity,
        kEdgeWidth,
        kEdgeOverhang,
        kEdgeJitterAmount,
        kEdgeSilhouetteColor,
        kEdgeSilhouetteWidth,
        kEdgeHaloGap,
        kEdgeIsolines,
        kEdgeHidePrecision,
        // Display properties
        kDisplayStyles,
        kDisplayBrightness,
        kDisplayShadowType,
        kUseDrawOrder,
        kViewportTransparency,
        kLightingEnabled,
        kPosterizeEffect,
        kMonoEffect,
        kBlurEffect,
        kPencilEffect,
        kBloomEffect,
        kPastelEffect,
        kBlurAmount,
        kPencilAngle,
        kPencilScale,
        kPencilPattern,
        kPencilColor,
        kBloomThreshold,
        kBloomRadius,
        kTintColor,
        kFaceAdjustment,
        kPostContrast,
        kPostBrightness,
        kPostPower,
        kTintEffect,
        kBloomIntensity,
        kColor,
        kTransparency,
        kEdgeWiggleAmount,
        kEdgeTexturePath,
        kDepthOfField,
        kFocusDistance,
        kFocusWidth,
        kPropertyCount,
        kPropertyCountPre2013 = kUseDrawOrder,
    };

    // Edge properties
    enum  EdgeModel
    {
        kNoEdges    = 0,
        kIsolines   = 1,
        kFacetEdges = 2,
    };
    enum EdgeStyles
    {
        kNoEdgeStyle      = 0x0,
        kVisibleFlag      = 0x1,
        kSilhouetteFlag   = 0x2,
        kObscuredFlag     = 0x4,
        kIntersectionFlag = 0x8,
    };
    enum EdgeLinePattern
    {
        kSolid            = 1,
        kDashedLine       = 2,
        kDotted           = 3,
        kShortDash        = 4,
        kMediumDash       = 5,
        kLongDash         = 6,
        kDoubleShortDash  = 7,
        kDoubleMediumDash = 8,
        kDoubleLongDash   = 9,
        kMediumLongDash   = 10,
        kSparseDot        = 11,
    };
    enum EdgeJitterAmount
    {
        kJitterLow  = 1,
        kJitterHigh = 2,
    };
    enum EdgeWiggleAmount
    {
        kWiggleLow    = 1,
        kWiggleMedium = 2,
        kWiggleHigh   = 3,
    };
    enum EdgeModifiers
    {
        kNoEdgeModifiers  = 0x0000,
        kEdgeOverhangFlag = 0x0001,
        kEdgeJitterFlag   = 0x0002,
        kEdgeWidthFlag    = 0x0004,
        kEdgeColorFlag    = 0x0008,
        kEdgeHaloGapFlag  = 0x0010,
        kAlwaysOnTopFlag  = 0x0020,
        kEdgeOpacityFlag  = 0x0040,
        kEdgeWiggleFlag   = 0x0080,
        kEdgeTextureFlag  = 0x0100,
    };

    // Face properties
    enum FaceColorMode
    {
        kNoColorMode     = 0,
        kObjectColor     = 1,
        kBackgroundColor = 2,
        kMono            = 3,
        kTint            = 4,
        kDesaturate      = 5,
    };
    enum FaceLightingQuality
    {
        kNoLighting        = 0,
        kPerFaceLighting   = 1,
        kPerVertexLighting = 2,
        kPerPixelLighting  = 3,
    };
    enum FaceLightingModel
    {
        kInvisible = 0,
        kConstant  = 1,
        kPhong     = 2,
        kGooch     = 3,
        kZebra     = 4,
    };
    enum FaceModifiers
    {
        kNoFaceModifiers = 0,
        kFaceOpacityFlag = 1,
        kSpecularFlag    = 2,
    };

    // Display properties
    enum DisplayShadowType
    {
        kShadowsNone           = 0,
        kShadowsGroundPlane    = 1,
        kShadowsFull           = 2,
        kShadowsFullAndGround  = 3,
    };
    enum DisplayStyles
    {
        kNoDisplayStyle  =  0,
        kBackgroundsFlag =  1,
        kLightingFlag    =  2,
        kMaterialsFlag   =  4,
        kTexturesFlag    =  8,
    };
} // namespace AcGiVisualStyleProperties


/** _ */
class BRX_IMPORTEXPORT AcGiVisualStyle: public AcRxObject
{
private:
    AcGiDisplayStyle m_displayStyle;
    AcGiEdgeStyle m_edgeStyle;
    AcGiFaceStyle m_faceStyle;

public:
    typedef AcGiVisualStyleProperties::Property Property;
    typedef AcGiVisualStyleOperations::Operation Operation;
    enum Type
    {
        kFlat = 0,
        kFlatWithEdges,
        kGouraud,
        kGouraudWithEdges,
        k2DWireframe,
        k3DWireframe,
        kHidden,
        kBasic,
        kRealistic,
        kConceptual,
        kCustom,
        kDim,
        kBrighten,
        kThicken,
        kLinePattern,
        kFacePattern,
        kColorChange,
        kFaceOnly,
        kEdgeOnly,
        kDisplayOnly,
        kJitterOff,
        kOverhangOff,
        kEdgeColorOff,
        kShadesOfGray,
        kSketchy,
        kXRay,
        kShadedWithEdges,
        kShaded,
        kByViewport,
        kByLayer,
        kByBlock,
        kEmptyStyle
    };

    ACRX_DECLARE_MEMBERS(AcGiVisualStyle);

    AcGiVisualStyle();
    AcGiVisualStyle(Type);
    AcGiVisualStyle(const AcGiVisualStyle&);
    ~AcGiVisualStyle();

    AcGiDisplayStyle& displayStyle();
    AcGiEdgeStyle& edgeStyle();
    AcGiFaceStyle& faceStyle();
    const AcGiDisplayStyle& displayStyle() const;
    const AcGiEdgeStyle& edgeStyle() const;
    const AcGiFaceStyle& faceStyle() const;
    void configureForType(Type);
    void setDisplayStyle(const AcGiDisplayStyle&);
    void setEdgeStyle(const AcGiEdgeStyle&);
    void setFaceStyle(const AcGiFaceStyle&);

    AcGiVisualStyle& operator=(const AcGiVisualStyle&);
    bool operator==(const AcGiVisualStyle&) const;

    Type type() const;
    bool setType(Type);

    //V17
    static AcGiVariant::VariantType propertyType(Property prop);
    virtual Operation operation(Property) const;
    virtual bool traitFlag(Property, Adesk::UInt32) const;
    virtual bool setTraitFlag(Property, Adesk::UInt32, bool = true);
    virtual const AcGiVariant& trait (Property, Operation* = NULL) const;
    virtual bool setTrait(Property, Operation);
    virtual bool setTrait(Property, const AcGiVariant*, Operation = AcGiVisualStyleOperations::kSet);
    virtual bool setTrait(Property, int, Operation = AcGiVisualStyleOperations::kSet);
    virtual bool setTrait(Property, bool,Operation = AcGiVisualStyleOperations::kSet);
    virtual bool setTrait(Property, double, Operation = AcGiVisualStyleOperations::kSet);
    virtual bool setTrait(Property, double, double, double, Operation = AcGiVisualStyleOperations::kSet);
    virtual bool setTrait(Property, const AcCmColor*, Operation = AcGiVisualStyleOperations::kSet);
    virtual bool setTrait(Property, const AcString*,  Operation = AcGiVisualStyleOperations::kSet);
};
