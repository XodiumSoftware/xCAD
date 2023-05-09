// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"
#include "AcGe/AcGePoint2d.h"

//common forward declarations
class AcGiCommonDraw;
class AcGiContext;
class AcGiContextualColors;
class AcGiDrawable;
class AcGiDrawableTraits;
class AcGiEdgeData;
class AcGiEdgeStyle;
class AcGiFaceData;
class AcGiGeometry;
class AcGiMapper;
class AcGiMaterialColor;
class AcGiMaterialMap;
class AcGiMaterialTexture;
class AcGiSubEntityTraits;
class AcGiTextStyle;
class AcGiTransientManager;
class AcGiVertexData;
class AcGiViewport;
class AcGiViewportDraw;
class AcGiViewportGeometry;
class AcGiViewportTraits;
class AcGiVisualStyle;
class AcGiVisualStyleTraits;
class AcGiWorldDraw;
class AcGiWorldGeometry;

typedef unsigned int AcGiEdgeStyleMask;

#define ACGI_SERVICES ACRX_T("AcGiServices")

#define kAcGiSaveWorldDrawForR12 kAcGiForExplode

#define AcGiSelectionMarkerACADReserveEnd (-2147418113)
#define AcGiSelectionMarkerACADSelectionPreviewOn (-2147483646)
#define AcGiSelectionMarkerACADSelectionPreviewOff (-2147483647)
#define AcGiSelectionMarkerACADReserveStart (-2147483648)

enum AcGiArcType
{
    kAcGiArcSimple = 0,
    kAcGiArcSector,
    kAcGiArcChord
};

enum AcGiColorIntensity
{
    kAcGiMinColorIntensity = 0,
    kAcGiColorIntensity1,
    kAcGiColorIntensity2,
    kAcGiColorIntensity3,
    kAcGiColorIntensity4,
    kAcGiColorIntensity5,
    kAcGiColorIntensity6,
    kAcGiMaxColorIntensity
};

enum AcGiDeviationType
{
    kAcGiMaxDevForCircle = 0,
    kAcGiMaxDevForCurve,
    kAcGiMaxDevForBoundary,
    kAcGiMaxDevForIsoline,
    kAcGiMaxDevForFacet
};

enum AcGiEdgeStyleMaskValues
{
    kAcGiNoEdgeStyleMask = 0,
    kAcGiJitterMask = 1,
    kAcGiOverhangMask = 2,
    kAcGiEdgeColorMask = 4
};

enum AcGiFillType
{
    kAcGiFillAlways = 1,
    kAcGiFillNever
};

enum AcGiImageOrg
{
    kAcGiBitonal = 0,
    kAcGiPalette,
    kAcGiGray,
    kAcGiRGBA,
    kAcGiBGRA,
    kAcGiARGB,
    kAcGiABGR,
    kAcGiBGR,
    kAcGiRGB
};

enum AcGiImageOrient
{
    kAcGiXLeftToRightTopFirst = 0,
    kAcGiXLeftToRightBottomFirst,
    kAcGiXRightToLeftTopFirst,
    kAcGiXRightToLeftBottomFirst,
    kAcGiYTopToBottomLeftFirst,
    kAcGiYTopToBottomRightFirst,
    kAcGiYBottomToTopLeftFirst,
    kAcGiYBottomToTopRightFirst
};

enum AcGiMrDiagnosticBSPMode
{
    krDepth = 0,
    krSize
};

enum AcGiMrDiagnosticGridMode
{
    krObject = 0,
    krWorld,
    krCamera
};

enum AcGiMrDiagnosticMode
{
    krOff = 0,
    krGrid,
    krPhoton,
    krSamples,
    krBSP
};

enum AcGiMrDiagnosticPhotonMode
{
    krDensity = 0,
    krIrradiance
};

enum AcGiMrFilter
{
    krBox = 0,
    krTriangle,
    krGauss,
    krMitchell,
    krLanczos
};

enum AcGiMrShadowMode
{
    krSimple = 0,
    krSorted,
    krSegments
};

enum AcGiMrTileOrder
{
    krHilbert = 0,
    krSpiral,
    krLeftToRight,
    krRightToLeft,
    krTopToBottom,
    krBottomToTop
};

enum AcGiOrientationType
{
    kAcGiCounterClockwise = -1,
    kAcGiNoOrientation,
    kAcGiClockwise
};

enum AcGiRegenType
{
    eAcGiRegenTypeInvalid = 0,
    kAcGiStandardDisplay = 2,
    kAcGiHideOrShadeCommand,
    kAcGiRenderCommand,
    kAcGiShadedDisplay = kAcGiRenderCommand,
    kAcGiForExplode,
    kAcGiSaveWorldDrawForProxy,
};

enum AcGiRotationFilterType
{
    kDefaultRotationFilter = 0,
    kInterpolatedRotationFilter,
    kNearestRotationFilter
};

enum AcGiScaleFilterType
{
    kDefaultScaleFilter = 0,
    kNearestScaleFilter,
    kBellScaleFilter,
    kMitchellScaleFilter,
    kTriangleScaleFilter,
    kCubicScaleFilter,
    kBsplineScaleFilter,
    kLanczos3ScaleFilter
};

enum AcGiScaleType
{
    kDefaultScale = 0,
    kRelativeScale,
    kUnTransformedScale
};

enum AcGiVisibility
{
    kAcGiInvisible = 0,
    kAcGiVisible,
    kAcGiSilhouette
};

bool acgiIsValidClipBoundary(const AcGePoint2dArray&);
