// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeContext.h"
#include "AcGe/AcGeLibVersion.h"
#include "Misc/AcArray.h"

//common forward declarations
class AcGeAugPolyline3d;
class AcGeBoundBlock2d;
class AcGeBoundBlock3d;
class AcGeBoundedPlane;
class AcGeCircArc2d;
class AcGeCircArc3d;
class AcGeCompositeCurve2d;
class AcGeCompositeCurve3d;
class AcGeCone;
class AcGeCubicSplineCurve2d;
class AcGeCubicSplineCurve3d;
class AcGeCurve2d;
class AcGeCurve3d;
class AcGeCurveBoundary;
class AcGeCurveCurveInt2d;
class AcGeCurveCurveInt3d;
class AcGeCylinder;
class AcGeEllipArc2d;
class AcGeEllipArc3d;
class AcGeEntity2d;
class AcGeEntity3d;
class AcGeExternalBoundedSurface;
class AcGeExternalCurve2d;
class AcGeExternalCurve3d;
class AcGeExternalSurface;
class AcGeFiler;
class AcGeInterval;
class AcGeKnotVector;
class AcGeLibVersion;
class AcGeLine2d;
class AcGeLine3d;
class AcGeLinearEnt2d;
class AcGeLinearEnt3d;
class AcGeLineSeg2d;
class AcGeLineSeg3d;
class AcGeMatrix2d;
class AcGeMatrix3d;
class AcGeNurbCurve2d;
class AcGeNurbCurve3d;
class AcGeNurbSurface;
class AcGeOffsetCurve2d;
class AcGeOffsetCurve3d;
class AcGeOffsetSurface;
class AcGePlanarEnt;
class AcGePlane;
class AcGePoint2d;
class AcGePoint3d;
class AcGePointOnCurve2d;
class AcGePointOnCurve3d;
class AcGePointOnSurface;
class AcGePolyline2d;
class AcGePolyline3d;
class AcGePosition2d;
class AcGePosition3d;
class AcGeRay2d;
class AcGeRay3d;
class AcGeScale2d;
class AcGeScale3d;
class AcGeSphere;
class AcGeSurface;
class AcGeTol;
class AcGeTorus;
class AcGeVector2d;
class AcGeVector3d;

typedef AcArray<void*> AcGeVoidPointerArray;
typedef AcArray<int> AcGeIntArray;
typedef AcArray<Adesk::IntPtr> AcGeIntPtrArray;
typedef AcArray<double> AcGeDoubleArray;

struct AcGe
{
    enum
    {
        eGood = 0,
        eBad
    };

    enum AcGeIntersectError
    {
        kXXOk = 0,
        kXXIndexOutOfRange,
        kXXWrongDimensionAtIndex,
        kXXUnknown
    };

    enum AcGeXConfig
    {
        kNotDefined = 1,
        kUnknown = 2,
        kLeftRight = 4,
        kRightLeft = 8,
        kLeftLeft = 16,
        kRightRight = 32,
        kPointLeft = 64,
        kPointRight = 128,
        kLeftOverlap = 256,
        kOverlapLeft = 512,
        kRightOverlap = 1024,
        kOverlapRight = 2048,
        kOverlapStart = 4096,
        kOverlapEnd = 8192,
        kOverlapOverlap = 16384
    };

    enum BooleanType
    {
        kUnion = 0,
        kSubtract,
        kCommon
    };

    enum ClipCondition
    {
        kInvalid = 0,
        kAllSegmentsInside,
        kSegmentsIntersect,
        kAllSegmentsOutsideZeroWinds,
        kAllSegmentsOutsideOddWinds,
        kAllSegmentsOutsideEvenWinds
    };

    enum ClipError
    {
        eOk = 0,
        eInvalidClipBoundary,
        eNotInitialized
    };

    enum csiConfig
    {
        kXUnknown = 0,
        kXOut,
        kXIn,
        kXTanOut,
        kXTanIn,
        kXCoincident,
        kXCoincidentUnbounded
    };

    enum EntityId
    {
        kEntity2d = 0,
        kEntity3d,
        kPointEnt2d,
        kPointEnt3d,
        kPosition2d,
        kPosition3d,
        kPointOnCurve2d,
        kPointOnCurve3d,
        kPointOnSurface,
        kBoundedPlane,
        kCircArc2d,
        kCircArc3d,
        kConic2d,
        kConic3d,
        kCurve2d,
        kCurve3d,
        kEllipArc2d,
        kEllipArc3d,
        kLine2d,
        kLine3d,
        kLinearEnt2d,
        kLinearEnt3d,
        kLineSeg2d,
        kLineSeg3d,
        kPlanarEnt,
        kPlane,
        kRay2d,
        kRay3d,
        kSurface,
        kSphere,
        kCylinder,
        kTorus,
        kCone,
        kSplineEnt2d,
        kPolyline2d,
        kAugPolyline2d,
        kNurbCurve2d,
        kDSpline2d,
        kCubicSplineCurve2d,
        kSplineEnt3d,
        kPolyline3d,
        kAugPolyline3d,
        kNurbCurve3d,
        kDSpline3d,
        kCubicSplineCurve3d,
        kTrimmedCrv2d,
        kCompositeCrv2d,
        kCompositeCrv3d,
        kExternalSurface,
        kNurbSurface,
        kTrimmedSurface,
        kOffsetSurface,
        kEnvelope2d,
        kCurveBoundedSurface,
        kExternalCurve3d,
        kExternalCurve2d,
        kSurfaceCurve2dTo3d,
        kSurfaceCurve3dTo2d,
        kExternalBoundedSurface,
        kCurveCurveInt2d,
        kCurveCurveInt3d,
        kBoundBlock2d,
        kBoundBlock3d,
        kOffsetCurve2d,
        kOffsetCurve3d,
        kPolynomCurve3d,
        kBezierCurve3d,
        kObject,
        kFitData3d,
        kHatch,
        kTrimmedCurve2d,
        kTrimmedCurve3d,
        kCurveSampleData,
        kEllipCone,
        kEllipCylinder,
        kIntervalBoundBlock,
        kClipBoundary2d,
        kExternalObject,
        kCurveSurfaceInt,
        kSurfaceSurfaceInt
    };

    enum ErrorCondition
    {
        kOk = 0,
        k0This,
        k0Arg1,
        k0Arg2,
        kPerpendicularArg1Arg2,
        kEqualArg1Arg2,
        kEqualArg1Arg3,
        kEqualArg2Arg3,
        kLinearlyDependentArg1Arg2Arg3,
        kArg1TooBig,
        kArg1OnThis,
        kArg1InsideThis
    };

    enum ExternalEntityKind
    {
        kAcisEntity = 0,
        kExternalEntityUndefined
    };

    enum NurbSurfaceProperties
    {
        kOpen = 1,
        kClosed = 2,
        kPeriodic = 4,
        kRational = 8,
        kNoPoles = 16,
        kPoleAtMin = 32,
        kPoleAtMax = 64,
        kPoleAtBoth = 128
    };

    enum OffsetCrvExtType
    {
        kFillet = 0,
        kChamfer,
        kExtend
    };

    enum PointContainment
    {
        kInside = 0,
        kOutside,
        kOnBoundary
    };

    enum ssiConfig
    {
        kSSIUnknown = 0,
        kSSIOut,
        kSSIIn,
        kSSICoincident
    };

    enum ssiType
    {
        kSSITransverse = 0,
        kSSITangent,
        kSSIAntiTangent
    };

    enum KnotParameterization
    {
        kChord     = 0,
        kSqrtChord = 1,
        kUniform   = 2,
        kCustomParameterization = 15,
        kNotDefinedKnotParam    = 16,
    };

    //BRX START
    BRX_IMPORTEXPORT
    //BRX END
    static const AcGeLibVersion gLibVersion;

}; //struct AcGe

typedef AcGe::AcGeIntersectError AcGeIntersectError;
typedef AcGe::AcGeXConfig AcGeXConfig;
typedef AcGe::EntityId EntityId;
typedef AcGe::ErrorCondition AcGeError;
typedef AcGe::ExternalEntityKind ExternalEntityKind;
typedef AcGe::NurbSurfaceProperties NurbSurfaceProperties;
typedef AcGe::PointContainment PointContainment;
typedef AcGe::KnotParameterization KnotParameterization;

const AcGe::KnotParameterization kChord                  = AcGe::KnotParameterization::kChord;
const AcGe::KnotParameterization kSqrtChord              = AcGe::KnotParameterization::kSqrtChord;
const AcGe::KnotParameterization kUniform                = AcGe::KnotParameterization::kUniform;
const AcGe::KnotParameterization kCustomParameterization = AcGe::KnotParameterization::kCustomParameterization;
const AcGe::KnotParameterization kNotDefinedKnotParam    = AcGe::KnotParameterization::kNotDefinedKnotParam;

const AcGe::AcGeIntersectError kXXIndexOutOfRange = AcGe::kXXIndexOutOfRange;
const AcGe::AcGeIntersectError kXXOk = AcGe::kXXOk;
const AcGe::AcGeIntersectError kXXUnknown = AcGe::kXXUnknown;
const AcGe::AcGeIntersectError kXXWrongDimensionAtIndex = AcGe::kXXWrongDimensionAtIndex;
const AcGe::AcGeXConfig kLeftLeft = AcGe::kLeftLeft;
const AcGe::AcGeXConfig kLeftOverlap = AcGe::kLeftOverlap;
const AcGe::AcGeXConfig kLeftRight = AcGe::kLeftRight;
const AcGe::AcGeXConfig kNotDefined = AcGe::kNotDefined;
const AcGe::AcGeXConfig kOverlapEnd = AcGe::kOverlapEnd;
const AcGe::AcGeXConfig kOverlapLeft = AcGe::kOverlapLeft;
const AcGe::AcGeXConfig kOverlapOverlap = AcGe::kOverlapOverlap;
const AcGe::AcGeXConfig kOverlapRight = AcGe::kOverlapRight;
const AcGe::AcGeXConfig kOverlapStart = AcGe::kOverlapStart;
const AcGe::AcGeXConfig kPointLeft = AcGe::kPointLeft;
const AcGe::AcGeXConfig kPointRight = AcGe::kPointRight;
const AcGe::AcGeXConfig kRightLeft = AcGe::kRightLeft;
const AcGe::AcGeXConfig kRightOverlap = AcGe::kRightOverlap;
const AcGe::AcGeXConfig kRightRight = AcGe::kRightRight;
const AcGe::AcGeXConfig kUnknown = AcGe::kUnknown;
const AcGe::EntityId kAugPolyline2d = AcGe::kAugPolyline2d;
const AcGe::EntityId kAugPolyline3d = AcGe::kAugPolyline3d;
const AcGe::EntityId kBezierCurve3d = AcGe::kBezierCurve3d;
const AcGe::EntityId kBoundBlock2d = AcGe::kBoundBlock2d;
const AcGe::EntityId kBoundBlock3d = AcGe::kBoundBlock3d;
const AcGe::EntityId kBoundedPlane = AcGe::kBoundedPlane;
const AcGe::EntityId kCircArc2d = AcGe::kCircArc2d;
const AcGe::EntityId kCircArc3d = AcGe::kCircArc3d;
const AcGe::EntityId kClipBoundary2d = AcGe::kClipBoundary2d;
const AcGe::EntityId kCompositeCrv2d = AcGe::kCompositeCrv2d;
const AcGe::EntityId kCompositeCrv3d = AcGe::kCompositeCrv3d;
const AcGe::EntityId kCone = AcGe::kCone;
const AcGe::EntityId kConic2d = AcGe::kConic2d;
const AcGe::EntityId kConic3d = AcGe::kConic3d;
const AcGe::EntityId kCubicSplineCurve2d = AcGe::kCubicSplineCurve2d;
const AcGe::EntityId kCubicSplineCurve3d = AcGe::kCubicSplineCurve3d;
const AcGe::EntityId kCurve2d = AcGe::kCurve2d;
const AcGe::EntityId kCurve3d = AcGe::kCurve3d;
const AcGe::EntityId kCurveBoundedSurface = AcGe::kCurveBoundedSurface;
const AcGe::EntityId kCurveCurveInt2d = AcGe::kCurveCurveInt2d;
const AcGe::EntityId kCurveCurveInt3d = AcGe::kCurveCurveInt3d;
const AcGe::EntityId kCurveSampleData = AcGe::kCurveSampleData;
const AcGe::EntityId kCurveSurfaceInt = AcGe::kCurveSurfaceInt;
const AcGe::EntityId kCylinder = AcGe::kCylinder;
const AcGe::EntityId kDSpline2d = AcGe::kDSpline2d;
const AcGe::EntityId kDSpline3d = AcGe::kDSpline3d;
const AcGe::EntityId kEllipArc2d = AcGe::kEllipArc2d;
const AcGe::EntityId kEllipArc3d = AcGe::kEllipArc3d;
const AcGe::EntityId kEllipCone = AcGe::kEllipCone;
const AcGe::EntityId kEllipCylinder = AcGe::kEllipCylinder;
const AcGe::EntityId kEntity2d = AcGe::kEntity2d;
const AcGe::EntityId kEntity3d = AcGe::kEntity3d;
const AcGe::EntityId kEnvelope2d = AcGe::kEnvelope2d;
const AcGe::EntityId kExternalBoundedSurface = AcGe::kExternalBoundedSurface;
const AcGe::EntityId kExternalCurve2d = AcGe::kExternalCurve2d;
const AcGe::EntityId kExternalCurve3d = AcGe::kExternalCurve3d;
const AcGe::EntityId kExternalObject = AcGe::kExternalObject;
const AcGe::EntityId kExternalSurface = AcGe::kExternalSurface;
const AcGe::EntityId kFitData3d = AcGe::kFitData3d;
const AcGe::EntityId kHatch = AcGe::kHatch;
const AcGe::EntityId kIntervalBoundBlock = AcGe::kIntervalBoundBlock;
const AcGe::EntityId kLine2d = AcGe::kLine2d;
const AcGe::EntityId kLine3d = AcGe::kLine3d;
const AcGe::EntityId kLinearEnt2d = AcGe::kLinearEnt2d;
const AcGe::EntityId kLinearEnt3d = AcGe::kLinearEnt3d;
const AcGe::EntityId kLineSeg2d = AcGe::kLineSeg2d;
const AcGe::EntityId kLineSeg3d = AcGe::kLineSeg3d;
const AcGe::EntityId kNurbCurve2d = AcGe::kNurbCurve2d;
const AcGe::EntityId kNurbCurve3d = AcGe::kNurbCurve3d;
const AcGe::EntityId kNurbSurface = AcGe::kNurbSurface;
const AcGe::EntityId kObject = AcGe::kObject;
const AcGe::EntityId kOffsetCurve2d = AcGe::kOffsetCurve2d;
const AcGe::EntityId kOffsetCurve3d = AcGe::kOffsetCurve3d;
const AcGe::EntityId kOffsetSurface = AcGe::kOffsetSurface;
const AcGe::EntityId kPlanarEnt = AcGe::kPlanarEnt;
const AcGe::EntityId kPlane = AcGe::kPlane;
const AcGe::EntityId kPointEnt2d = AcGe::kPointEnt2d;
const AcGe::EntityId kPointEnt3d = AcGe::kPointEnt3d;
const AcGe::EntityId kPointOnCurve2d = AcGe::kPointOnCurve2d;
const AcGe::EntityId kPointOnCurve3d = AcGe::kPointOnCurve3d;
const AcGe::EntityId kPointOnSurface = AcGe::kPointOnSurface;
const AcGe::EntityId kPolyline2d = AcGe::kPolyline2d;
const AcGe::EntityId kPolyline3d = AcGe::kPolyline3d;
const AcGe::EntityId kPolynomCurve3d = AcGe::kPolynomCurve3d;
const AcGe::EntityId kPosition2d = AcGe::kPosition2d;
const AcGe::EntityId kPosition3d = AcGe::kPosition3d;
const AcGe::EntityId kRay2d = AcGe::kRay2d;
const AcGe::EntityId kRay3d = AcGe::kRay3d;
const AcGe::EntityId kSphere = AcGe::kSphere;
const AcGe::EntityId kSplineEnt2d = AcGe::kSplineEnt2d;
const AcGe::EntityId kSplineEnt3d = AcGe::kSplineEnt3d;
const AcGe::EntityId kSurface = AcGe::kSurface;
const AcGe::EntityId kSurfaceCurve2dTo3d = AcGe::kSurfaceCurve2dTo3d;
const AcGe::EntityId kSurfaceCurve3dTo2d = AcGe::kSurfaceCurve3dTo2d;
const AcGe::EntityId kSurfaceSurfaceInt = AcGe::kSurfaceSurfaceInt;
const AcGe::EntityId kTorus = AcGe::kTorus;
const AcGe::EntityId kTrimmedCrv2d = AcGe::kTrimmedCrv2d;
const AcGe::EntityId kTrimmedCurve2d = AcGe::kTrimmedCurve2d;
const AcGe::EntityId kTrimmedCurve3d = AcGe::kTrimmedCurve3d;
const AcGe::EntityId kTrimmedSurface = AcGe::kTrimmedSurface;
const AcGe::ErrorCondition k0Arg1 = AcGe::k0Arg1;
const AcGe::ErrorCondition k0Arg2 = AcGe::k0Arg2;
const AcGe::ErrorCondition k0This = AcGe::k0This;
const AcGe::ErrorCondition kArg1InsideThis = AcGe::kArg1InsideThis;
const AcGe::ErrorCondition kArg1OnThis = AcGe::kArg1OnThis;
const AcGe::ErrorCondition kArg1TooBig = AcGe::kArg1TooBig;
const AcGe::ErrorCondition kEqualArg1Arg2 = AcGe::kEqualArg1Arg2;
const AcGe::ErrorCondition kEqualArg1Arg3 = AcGe::kEqualArg1Arg3;
const AcGe::ErrorCondition kEqualArg2Arg3 = AcGe::kEqualArg2Arg3;
const AcGe::ErrorCondition kLinearlyDependentArg1Arg2Arg3 = AcGe::kLinearlyDependentArg1Arg2Arg3;
const AcGe::ErrorCondition kOk = AcGe::kOk;
const AcGe::ErrorCondition kPerpendicularArg1Arg2 = AcGe::kPerpendicularArg1Arg2;
const AcGe::ExternalEntityKind kAcisEntity = AcGe::kAcisEntity;
const AcGe::ExternalEntityKind kExternalEntityUndefined = AcGe::kExternalEntityUndefined;
const AcGe::NurbSurfaceProperties kClosed = AcGe::kClosed;
const AcGe::NurbSurfaceProperties kNoPoles= AcGe::kNoPoles;
const AcGe::NurbSurfaceProperties kOpen = AcGe::kOpen;
const AcGe::NurbSurfaceProperties kPeriodic = AcGe::kPeriodic;
const AcGe::NurbSurfaceProperties kPoleAtBoth = AcGe::kPoleAtBoth;
const AcGe::NurbSurfaceProperties kPoleAtMax = AcGe::kPoleAtMax;
const AcGe::NurbSurfaceProperties kPoleAtMin = AcGe::kPoleAtMin;
const AcGe::NurbSurfaceProperties kRational = AcGe::kRational;
const AcGe::PointContainment kInside = AcGe::kInside;
const AcGe::PointContainment kOnBoundary = AcGe::kOnBoundary;
const AcGe::PointContainment kOutside = AcGe::kOutside;
const int eBad = AcGe::eBad;
const int eGood = AcGe::eGood;

AcGePoint2d& asPnt2d(const double*);
AcGePoint3d& asPnt3d(const double*);
AcGeVector2d& asVec2d(const double*);
AcGeVector3d& asVec3d(const double*);
double* asDblArray(const AcGePoint2d&);
double* asDblArray(const AcGePoint3d&);
double* asDblArray(const AcGeVector2d&);
double* asDblArray(const AcGeVector3d&);
