// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#ifdef _WIN32
#pragma warning(disable:4251)
#include <tchar.h>
#endif

#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <memory>


#ifdef _WIN32
  #ifdef BMODELER_API
  #define BM_IMPORTEXPORT __declspec(dllexport)
  #else
  #define BM_IMPORTEXPORT __declspec(dllimport)
  #endif
#else  // Linux,Max
  #ifdef BMODELER_API
  #define BM_IMPORTEXPORT __attribute__((visibility("default")))
  #else
  #define BM_IMPORTEXPORT // extern ?
  #endif
#endif // !_WIN32


#ifndef _T
  #define _T(x) L##x
#endif


class AcGeVector3d;

namespace AModeler
{

class Body;
class Circle3d;
class CircleCurve;
class ConeSurface;
class Curve;
class CylinderSurface;
class Darray;
class Edge;
class Entity;
class Face;
class HideIntegerTransform;
class Interval1d;
class Interval2d;
class Interval3d;
class IntInterval1d;
class IntInterval2d;
class IntInterval3d;
class IntPoint2d;
class IntPoint3d;
class IntVector2d;
class IntVector3d;
class Line3d;
class MorphingMap;
class MorphingMapElem;
class OutputPolylineCallback;
class OutputTriangleCallback;
class Plane;
class Point2d;
class Point3d;
class PolygonVertexData;
class SaveRestoreCallback;
class SaveToSatCallback;
class SphereSurface;
class Surface;
class TopologyChangeCallback;
class TorusSurface;
class Transf3d;
class TriangleCache;
class Vector2d;
class Vector3d;
class Vertex;
class VertexSurfaceData;

typedef unsigned Flag;

enum BodyInterferenceType
{
    kBodiesDoNotInterfere = 0,
    kBodiesTouch,
    kBodiesInterfere
};

enum BoolOperType
{
    kBoolOperUnite = 0,
    kBoolOperSubtract,
    kBoolOperIntersect
};

enum Color
{
    kColorInvisible = -1,
    kColor1 = 1,
    kColor2,
    kColor3,
    kColor4
};

enum ErrorCode
{
    eOk = 0,
    eFail,
    eViewPointLiesInsideScene,
    eBadBodyGeometry,
    eBadSurfaceType,
    eBadCurveType,
    eBadInput,
    eNullVector,
    eNullNormalVector,
    eBadPlane,
    eBadLine,
    eBadAxis,
    eBadTransform,
    ePointLiesInPlane,
    eInputBodiesMustNotBeNegated,
    eRadiusMustBePositive,
    eRadiusMustBeNonNegative,
    eRadiusMustNotBeZero,
    eApproximationMustBeAtLeastFour,
    eScaleFactorMustBePositive,
    eAngleMustNotBeZero,
    eBodyPointerIsNull,
    eFacePointerIsNull,
    eEdgePointerIsNull,
    eVertexPointerIsNull,
    ePolygonPointerIsNull,
    eProfilePolygonPointerIsNull,
    ePathPolygonPointerIsNull,
    eBodyIsNegative,
    eIntervalIsNull,
    eFileNameIsNull,
    eBadFile,
    eIncorrectFile,
    eFilePointerIsNull,
    eFileOpenError,
    eFileReadError,
    eFileWriteError,
    eSaveError,
    eRestoreError,
    eBadDataRestored,
    eFileIsNewerThanCurrentVersionOfModeler,
    eBoxSizesMustNotBeZero,
    eMajorRadiusMustBeGreaterThanMinorRadius,
    eInnerRadiusMustBeSmallerThanOuterRadius,
    eInnerRadiusCanBeZeroOnlyIfOuterRadiusIsZero,
    eViewPointCoincidesWithTargetPoint,
    eEpsilonMustBePositive,
    eCallbackObjectPointerIsNull,
    ePickingNotPossible,
    eAtLeast4NonCoplanarPointsRequired,
    ePointsDoNotDefineConvexPolyhedron,
    eApexMustNotLieInPolygon,
    eExtrusionVectorMustNotBeParallelToPolygon,
    eAxisOfRevolutionMustLieInPolygonPlane,
    eAxisOfRevolutionIntersectsPolygon,
    eBadNormal,
    eBadPolygon,
    ePolygonIsSelfIntersectingOrTouching,
    eBadRelativePolygonPosition,
    eCannotCreateFillet,
    eBadArcCenter,
    eRadiusTooSmall,
    eFilletRadiusMustBePositive,
    eCannotFilletVerticesBelongingToArcs,
    eFirstAndLastVertexInEndpointRevolutionMustNotBeFilleted,
    eArcBetweenLastAndFirstVertexNotAllowedForEndpointRevolution,
    eEntitiesSectionNotFoundInDxfFile,
    ePolylineEntityNotFoundInDxfFile,
    ePolylineMustBeClosed,
    e3dPolylineOrMeshNotAllowed,
    eBadDxfFile,
    ePointsAreColinearOrCoincident,
    eSourceArgumentsAreColinearOrCoincident,
    eDestinationArgumentsAreColinearOrCoincident,
    ePointsAreCoplanar,
    eChamferingDistanceMustBePositive,
    eOnlyManifoldEdgesCanBeFilletedAndChamfered,
    eOnlyStraightAndCircularEdgesCanBeFilletedAndChamfered,
    ePlanarEdgesCannotBeFilletedAndChamfered,
    eAtLeastOneEdgeExpected,
    eFilletRadiusTooLarge,
    eChamferDistanceTooLarge,
    eCannotFilletEdge,
    eCannotMitreEdgesOfDifferentConvexity,
    eTooComplexMixedConvexityCap,
    eNotYetImplemented,
    eCircleIsNotValid,
    eBaseNormalPerpendicularToAxisVector,
    eEndCentersMustHaveEqualDistance,
    eFaceMustNotBelongToABody,
    eFaceHasNoEdges,
    eOneSidedFaceExpected,
    eProfileFacesMustHaveTheSameNumberOfEdges,
    eAtLeastTwoProfilesExpected,
    eBodyProfileMustContainExactlyOneFace,
    eProfileFaceHasNoEdges,
    eBadMorphingMap,
    eEdgesOfFirstProfileCannotBeMarkedApproximating,
    eBaseSizesMustBePositive,
    eTopCircleMustLieAboveBaseRectangle,
    eFilletByRadiusOrArcByBulgeTypeExpected,
    eArcByRadiusTypeExpected,
    eArc3dTypeExpected,
    eCannotCreateTouchingCircle,
    eNonPlanarPolygon,
    eNonPlanarProfileFace,
    eFaceMustHaveAtLeastThreeEdges,
    ePolygonPointsCoincide,
    eBadPath,
    eBadProfileAndPathOrientation,
    eFirstPathPointMustLieInStartProfilePlane,
    eLastPathPointMustLieInEndProfilePlane,
    eWidthTooSmall,
    eHeightTooSmall,
    eEndProfileNotAllowedWhenPathIsClosed,
    eScaleFactorNotAllowedWhenPathIsClosed,
    eTwistAngleNotAllowedWhenPathIsClosed,
    eMorphingMustBeIdentityWhenPathIsClosed,
    eExtrusionBodyLooksSelfIntersecting,
    eMorphingMapRequiresEndProfile,
    eNegativeIndexInMorphingMap,
    eFixedPointMustLieInPolygonPlane,
    eTriStripsMayBeGeneratedOnlyWhenCachingTriangles,
    eStartProfileNormalHasOppositeDirectionThanFirstPathSegment,
    eEndProfileNormalHasOppositeDirectionThanLastPathSegment,
    eStartProfileIsParallelWithFirstPathSegment,
    eEndProfileIsParallelWithLastPathSegment,
    eProfilePolygonMustContainAtLeastOnePoint,
    eArcByRadiusNotAllowedForPathPolygons_UseArc3d,
    eArcByBulgeNotAllowedForPathPolygons_UseArc3d,
    eNumberOfLinearSegmentsMustBeAtLeastOne,
    eZeroBulgeNotAllowed,
    eFixedPointMustLieInStartProfilePlane,
    eBodyCannotBeClosed,
    ePolygonNormalNotPerpendicularToPolygonPlane,
    eSizeMustBePositive,
    ePointerIsNull,
    eToleranceMustBePositive,
    eValueMustBePositive,
    ePartnerEdgesOfNonManifoldEdgeCannotBeOrdered,
    eNonManifoldEdgesMustHaveEvenNumberOfPartners,
    eFaceMustHaveManifoldEdgesOnly,
    eStitchingFacesDidNotProduceAValidBody,
    eFaceCanNotBeMoved,
    eManifoldEdgeExpected,
    eEdgeSharedByTwoDifferentFacesExpected,
    eCoplanarFacesExpected,
    eInvalidVector,
    eAngleMustBePositive,
    eMinNumberOfFacesInSurfaceMustBeAtLeastTwo,
    eUnspecifiedCurveTypeExpected,
    eInvalidTerrainBody,
    eHeightMustBePositive,
    eCannotCreateLoopOfEdges,
    eTerrainSurfaceContainsHole,
    eBadIndexInMorphingMap,
    eStartProfileIsWrong,
    eEndProfileIsWrong,
    eExtrusionPathIsWrong,
    eStartProfileMustHaveOnlySingleLoop,
    eEndProfileMustHaveOnlySingleLoop,
    eInternalError = 1000
};

enum HiddenLineDrawingImprove
{
    kNoDrawingImprove = 0,
    kConnectDrawingImprove,
    kArcReconstructDrawingImprove
};

enum HiddenLinesDisplay
{
    kHiddenLinesInvisible = 0,
    kHiddenLinesDashed,
    kHiddenLinesVisible
};

enum OnOff
{
    kOff = 0,
    kOn
};

enum PointInBodyLocation
{
    kPointOutsideBody = 0,
    kPointAtVertex,
    kPointOnEdge,
    kPointInFace,
    kPointInsideBody
};

enum PointInPolygonLocation
{
    kPointInPolygonFace = -3,
    kPointOnPolygonEdge,
    kPointAtPolygonVertex,
    kPointOutsidePolygon,
    kPointBehindPolygonVertex,
    kPointBehindPolygonEdge,
    kPointBehindPolygonFace
};

enum RayBodyIntersection
{
    kRayDoesNotIntersect = 0,
    kRayPointAtVertex,
    kRayPointOnEdge,
    kRayPointInFace,
    kRayIntersectsVertex,
    kRayIntersectsEdge,
    kRayIntersectsFace
};

enum TriangulationType
{
    kGenerateTriangles = 0,
    kGenerateQuadrilaterals,
    kGenerateTriStrips,
    kGenerateTriStripsPerSurface
};

BM_IMPORTEXPORT extern Color gDefaultColor;
BM_IMPORTEXPORT extern const double kDeg2Rad;
BM_IMPORTEXPORT extern const double kEpsZero;
BM_IMPORTEXPORT extern const double kHalfPi;
BM_IMPORTEXPORT extern const double kMaxReal;
BM_IMPORTEXPORT extern const double kMinReal;
BM_IMPORTEXPORT extern const double kPi;
BM_IMPORTEXPORT extern const double kTwoPi;
BM_IMPORTEXPORT extern double gEpsAbs;
BM_IMPORTEXPORT extern double gEpsAbsSqrd;
BM_IMPORTEXPORT extern double gEpsNor;
BM_IMPORTEXPORT extern double gEpsNorSqrd;

BM_IMPORTEXPORT Body createWallCornerBody(const Point2d&,const Point2d&,const Point2d&,bool,double,double,double,Color,Plane&,Plane&,bool&,bool&);
BM_IMPORTEXPORT Body operator*(const Transf3d&,Body&);
BM_IMPORTEXPORT bool areCoplanar(Point3d,Point3d,Point3d,Point3d);
BM_IMPORTEXPORT bool doIntersect(const Point2d&,const Point2d&,const Point2d&,const Point2d&);
BM_IMPORTEXPORT bool isPolygonSelfIntersecting(const Point3d[],int,int,int);
BM_IMPORTEXPORT bool keepInputBodiesWhenBooleanOperationsFail();
BM_IMPORTEXPORT bool odd(int);
//BM_IMPORTEXPORT bool operator&&(double,Interval1d);         // not yet implemented
BM_IMPORTEXPORT bool operator&&(const Point2d,Interval2d);
//BM_IMPORTEXPORT bool operator&&(int, IntInterval1d);        // not yet implemented
//BM_IMPORTEXPORT bool operator&&(IntPoint2d,IntInterval2d);  // not yet implemented
//BM_IMPORTEXPORT bool operator&&(IntPoint3d,IntInterval3d);  // not yet implemented
BM_IMPORTEXPORT bool operator&&(Point3d,Interval3d);
BM_IMPORTEXPORT bool profilesOrdered(const Body&,const Body&);
BM_IMPORTEXPORT bool setAdjustEpsAbsInFlatIntersections(bool);
BM_IMPORTEXPORT Color defaultColor();
BM_IMPORTEXPORT double arcToBulge(const Point2d&,const Point2d&,const Point2d&,const Point2d&);
BM_IMPORTEXPORT double det(Point2d,Point2d);
BM_IMPORTEXPORT double det(Point3d,Point3d,Point3d);
BM_IMPORTEXPORT double det(Vector2d,Vector2d);
BM_IMPORTEXPORT double det(Vector3d,Vector3d,Vector3d);
BM_IMPORTEXPORT double epsAbs();
BM_IMPORTEXPORT double epsAbsSqrd();
BM_IMPORTEXPORT double epsNor();
BM_IMPORTEXPORT double epsNorSqrd();
BM_IMPORTEXPORT double sqr(double);
BM_IMPORTEXPORT Edge* breakEdge(Body&,const Point3d&);
BM_IMPORTEXPORT Edge* breakEdge(Body&,const Point3d&,const Point3d&);
BM_IMPORTEXPORT Edge* findEdge(const Body&,const Point3d&,const Point3d&);
BM_IMPORTEXPORT Edge* makeEdgeLoop(const Circle3d&,int,int,Face*,Face*,Body*);
BM_IMPORTEXPORT Edge* makeEdgeLoop(Vertex*[],Curve*[],Edge*[],int,int,Face*,Face*);
BM_IMPORTEXPORT Edge* me(Face*,Face*,Vertex*,Vertex*);
BM_IMPORTEXPORT ErrorCode checkPolygon(const Point3d[],int,const Plane&,const Vector3d&);
BM_IMPORTEXPORT Flag FLAG(unsigned int);
BM_IMPORTEXPORT int deviationToApprox(double);
BM_IMPORTEXPORT int getValidityCheckingLevel();
BM_IMPORTEXPORT int isSubset(Flag,Flag);
BM_IMPORTEXPORT int nextIndex(int,int);
BM_IMPORTEXPORT int prevIndex(int,int);
BM_IMPORTEXPORT int round(double);
BM_IMPORTEXPORT int setValidityCheckingLevel(int);
BM_IMPORTEXPORT int sign(double);
BM_IMPORTEXPORT Point2d intersect(const Point2d&,const Vector2d,const Point2d&,const Vector2d,bool&);
BM_IMPORTEXPORT Point2d operator*(double,Point2d);
BM_IMPORTEXPORT Point2d projectPointOnLine(Point2d,Point2d,Vector2d);
BM_IMPORTEXPORT Point3d operator*(double,Point3d);
BM_IMPORTEXPORT PointInBodyLocation operator&&(const Point3d&,const Body&);
BM_IMPORTEXPORT PointInPolygonLocation pointInPolygonTest(IntPoint3d,Face*,int* = NULL);
//BM_IMPORTEXPORT Vector3d operator*(double,Vector3d); //inline
BM_IMPORTEXPORT Vector3d& asVector3d(AcGeVector3d&);
BM_IMPORTEXPORT Vertex* findVertex(const Body&,const Point3d&);
BM_IMPORTEXPORT void adjustEpsAbsByObject(const Interval3d&);
BM_IMPORTEXPORT void appendDxfExtension(const wchar_t[],wchar_t[]);
BM_IMPORTEXPORT void assertFunction(int,wchar_t*,int,wchar_t* = NULL);
BM_IMPORTEXPORT void bulgeToCircle(const Point2d&,const Point2d&,double,Point2d&,double&);
BM_IMPORTEXPORT void checkFaceAgainstAxis(Face*,const Line3d&);
BM_IMPORTEXPORT void checkMorphingMap(const MorphingMap&,int,int);
BM_IMPORTEXPORT void checkProfile(const Body&);
BM_IMPORTEXPORT void deleteVertexData(PolygonVertexData*[],int,bool);
BM_IMPORTEXPORT void dxfPolylineToAugmentedPolygon(FILE*,int,Point3d*&,PolygonVertexData**&,int&,Vector3d&);
BM_IMPORTEXPORT void extremeVertices(const Body&,const Vector3d&,Vertex*&,Vertex*&);
BM_IMPORTEXPORT void findFace(const Body&,const Plane&,Darray&);
BM_IMPORTEXPORT void getAllConnectedEdgesSharingVertex(const Edge*,Darray&);
BM_IMPORTEXPORT void makeIndexToEdgeMap(int,const Body&,const MorphingMap&,Darray&);
BM_IMPORTEXPORT void operator*=(double&,const Transf3d&);
BM_IMPORTEXPORT void printEdge(Edge*);
BM_IMPORTEXPORT void printFace(Face*);
BM_IMPORTEXPORT void printTriangle(Edge*[],int);
BM_IMPORTEXPORT void printVertex(Vertex*);
BM_IMPORTEXPORT void setDefaultColor(Color);
BM_IMPORTEXPORT void setEpsAbs(double);
BM_IMPORTEXPORT void setEpsNor(double);
BM_IMPORTEXPORT void setKeepInputBodiesWhenBooleanOperationsFail(bool);
BM_IMPORTEXPORT void setMaxEpsAbs(double);
BM_IMPORTEXPORT void splitMorphingMap(const Body&,const Body&,const MorphingMap&,Body&,MorphingMap&,MorphingMap&,MorphingMap&);
BM_IMPORTEXPORT wchar_t* errorString(ErrorCode);
BM_IMPORTEXPORT void disableExceptionForError(unsigned int);
BM_IMPORTEXPORT void enableExceptionForError(unsigned int);
BM_IMPORTEXPORT bool isExceptionDisabledForError(unsigned int);
BM_IMPORTEXPORT void checkError(bool, ErrorCode);

// edge flags
const Flag AEF = FLAG(0);
const Flag BEF = FLAG(1);
const Flag PICKEF = FLAG(2);

// face + body flags
const Flag CONVEXFF = FLAG(1);
const Flag DAEBF = FLAG(4);
const Flag DASHBF = FLAG(2);
const Flag DBEBF = FLAG(5);
const Flag FFF = FLAG(0);
const Flag IPBF = FLAG(0);
const Flag NEGBF = FLAG(1);
const Flag NONMANIFOLD_VF = FLAG(1);
const Flag PICKVF = FLAG(0);
const Flag WFBF = FLAG(3);
const int kHideIntMax = (INT_MAX/4)-4;
const int kMaxApprox = 128;
const int kMinApprox = 4;
const int kTooBigInt = 10000000;

#define SetValidityCheckingLevel setValidityCheckingLevel

} // namespace AModeler
