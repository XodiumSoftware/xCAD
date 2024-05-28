// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD Civil TinSurface functionality + interfaces

/*
* In BRX SDK V24, many classes and enums in the Civil API were renamed to
* improve consistency and readability.
*
* This old header file remains so that BRX client code based on BRX SDK V23
* continues to compile and run without error in later versions of the SDK.
* Starting with V24, all new BRX client code should directly include only
* the new header file(s).
*/

// forward to new headers
#include "BrxCvDbTinSurface.h"
#include "BrxCvDbCurve.h"

// define aliases for old type names that have been renamed
typedef BrxCvDbCurve AcDbCivilDbCurve;
typedef BrxCvDbTinSurface AcDbCivilTinSurface;
typedef BrxCvDbVolumeSurface AcDbCivilTinVolumeSurface;
typedef BrxCvDbTinSurfaceConstraint TinSurfaceConstraint;
typedef BrxCvDbTinSurfaceBoundary TinSurfaceBoundary;
typedef BrxCvDbTinSurfaceBreakline TinSurfaceBreakline;
typedef BrxCvDbTinSurfaceWall TinSurfaceWall;
typedef BrxCvDbGrading AcDbCivilTinGrading;
typedef BrxCvGradingRule TinGradingRule;
typedef BrxCvGradingSlopeOffsetRule TinSlopeOffsetRule;
typedef BrxCvGradingSlopeSurfaceRule TinSlopeSurfaceRule;
typedef BrxCvTinPoint AcCivilTinPoint;
typedef BrxCvTinTriangle AcCivilTinTriangle;

#define AcTinSurfaceConstraintArray BrxCvDbTinSurfaceConstraintArray
#define TinSurfaceTriangle BrxCvDbTinSurface::Triangle
#define AcTinTrianglesArray BrxCvDbTinSurface::TriangleArray

// redefine enum names
#define ETinVolumeSurfaceType EVolumeSurfaceType
#define ETinVolumeSurfaceType EVolumeSurfaceType
#define ETinGradingSide EGradingSide
#define ETinGradingType EGradingType
#define ETinSlopeFormat EGradingSlopeFormat
#define ETinGradingStatus EGradingStatus
#define ETinGradingCalculationMethod EGradingCalculationMethod
#define ETinGradingVisualStyle EGradingVisualStyle

// enums were moved inside class; promote them back into global namespace
typedef BrxCvDbTinSurface::ETinSurfaceStyle ETinSurfaceStyle;
typedef BrxCvDbTinSurface::ETinSurfaceMeshType ETinSurfaceMeshType;
typedef BrxCvDbTinSurface::ETinSurfaceIntersectType ETinSurfaceIntersectType;
typedef BrxCvDbTinSurface::ETinSurfaceSolidType ETinSurfaceSolidType;
typedef BrxCvDbTinSurfaceConstraint::ETinConstraintType ETinConstraintType;
typedef BrxCvDbTinSurfaceBreakline::ETinBreaklineType ETinBreaklineType;
typedef BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation ETinIntersectionElevation;
typedef BrxCvDbTinSurfaceWall::ETinWallType ETinWallType;
typedef BrxCvDbTinSurfaceWall::ETinWallSide ETinWallSide;
typedef BrxCvDbTinSurfaceBoundary::ETinBoundaryType ETinBoundaryType;
typedef BrxCvDbVolumeSurface::EVolumeSurfaceType EVolumeSurfaceType;
typedef BrxCvGradingRule::EGradingSide EGradingSide;
typedef BrxCvGradingRule::EGradingType EGradingType;
typedef BrxCvGradingRule::EGradingSlopeFormat EGradingSlopeFormat;
typedef BrxCvDbGrading::EGradingStatus EGradingStatus;
typedef BrxCvDbGrading::EGradingCalculationMethod EGradingCalculationMethod;
typedef BrxCvDbGrading::EGradingVisualStyle EGradingVisualStyle;
