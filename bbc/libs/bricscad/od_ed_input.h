// od_ed_input.h : OdEdInputPointManager, OdEdInputPointMonitor, OdEdInputPointFilter,
//                 OdEdInputContextReactor classes definition

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "od_api_exports.h"

#include "RxObject.h"
#include "IdArrays.h"
#include "Ge/GeIntArray.h"
#include "Ge/GePoint3dArray.h"

class OdGiViewportDraw;
class OdApDocument;
class OdGePoint3d;
class OdEdInputPointMonitor;
class OdEdInputPointFilter;
class OdEdInputContextReactor;
class OdEdSSGetFilter;
class OdEdSSGetFilter2;
class OdEdPreselectReactor;

namespace OdEd
{

enum EPointHistory
{
    eDidNotPick     = 0,
    eTablet         = 1,
    eNotDigitizer   = 1 << 1,
    eLastPt         = 1 << 2,
    eGripped        = 1 << 3,
    eCartSnapped    = 1 << 4,
    eOrtho          = 1 << 5,
    eCyclingPt      = 1 << 6,
    eOsnapped       = 1 << 7,
    ePolarAngle     = 1 << 8,
    eAligned        = 1 << 10,
    eAppFiltered    = 1 << 11,
    eForcedPick     = 1 << 12,
    eUsedPickBox    = 1 << 13,
    eUsedOsnapBox   = 1 << 14,
    ePickAborted    = 1 << 15,
    ePickMask       = eUsedPickBox | eUsedOsnapBox | ePickAborted,
    eXPending       = 1 << 16,
    eYPending       = 1 << 17,
    eZPending       = 1 << 18,
    eCoordPending   = eXPending | eYPending | eZPending,
    eFromKeyboard   = 1 << 19,
    eNotInteractive = 1 << 20
};

enum EPromptStatus
{
    eNone     =  5000, // RTNONE
    eNormal   =  5100, // RTNORM
    eError    = -5001, // RTERROR
    eCancel   = -5002, // RTCAN
    eRejected = -5003, // RTREJ
    eFailed   = -5004, // RTFAIL
    eKeyword  = -5005, // RTKWORD
    eDirect   = -5999
};

}


class OdEdInputPointManager
{
public:
    virtual ~OdEdInputPointManager() noexcept = default;
    virtual OdResult registerPointFilter(OdEdInputPointFilter* filter) = 0;
    virtual OdResult revokePointFilter() = 0;
    virtual OdEdInputPointFilter* currentPointFilter() const = 0;
    virtual OdResult addPointMonitor(OdEdInputPointMonitor* monitor) = 0;
    virtual OdResult removePointMonitor(OdEdInputPointMonitor* monitor) = 0;
    virtual OdResult addInputContextReactor(OdEdInputContextReactor* reactor) = 0;
    virtual OdResult removeInputContextReactor(OdEdInputContextReactor* reactor) = 0;
    virtual OdResult addSSGetFilter(OdEdSSGetFilter* filter) = 0;
    virtual OdResult addSSGetFilter(OdEdSSGetFilter2* filter) = 0;
    virtual OdResult removeSSGetFilter(OdEdSSGetFilter* filter) = 0;
    virtual OdResult removeSSGetFilter(OdEdSSGetFilter2* filter) = 0;
    virtual OdResult addPreselectReactor(OdEdPreselectReactor* reactor) = 0;
    virtual OdResult removePreselectReactor(OdEdPreselectReactor* reactor) = 0;
    virtual OdResult disableSystemCursorGraphics() = 0;
    virtual OdResult enableSystemCursorGraphics() = 0;
    virtual int systemCursorDisableCount() const = 0;
    virtual void turnOffForcedPick() = 0;
    virtual void turnOnForcedPick() = 0;
    virtual int forcedPickCount() const = 0;
};


class ODAPI OdEdInputPointMonitor : public OdRxObject
{
public:
    ODRX_DECLARE_MEMBERS(OdEdInputPointMonitor);

    virtual OdResult monitorInputPoint(
        bool&                               updateTooltip,
        OdString&                           additionalTooltip,
        OdGiViewportDraw*                   pVectorizer,
        OdApDocument*                       pDoc,
        bool                                isPointValid,
        int                                 pointHistory,
        const OdGePoint3d&                  lastPt,
        const OdGePoint3d&                  rawPt,
        const OdGePoint3d&                  gripPt,
        const OdGePoint3d&                  staticSnapPt,
        const OdGePoint3d&                  flyoverSnapPt,
        int                                 osmode,
        const OdRxObjectPtrArray&           customOsmode,
        int                                 osmodeOverride,
        const OdRxObjectPtrArray&           custOsmodeOverride,
        const OdDbObjectIdArray&            coveredObjs,
        const OdArray<OdDbObjectIdArray>&   nestCoveredObjs,
        const OdGsMarkerArray&              selMarkers,
        const OdDbObjectIdArray&            snapObjects,
        const OdArray<OdDbObjectIdArray>&   nestSnapObjs,
        const OdGsMarkerArray&              snapObjsSelMarkers,
        const OdGeCurve3dPtrArray&          alignCurves,
        const OdGePoint3d&                  point,
        const OdString&                     curTooltip) = 0;

    virtual bool excludeFromOsnapCalculation(
        const OdDbObjectIdArray& entity, OdGsMarker selMarker)
    {
        return false;
    }
};

typedef OdSmartPtr<OdEdInputPointMonitor> OdEdInputPointMonitorPtr;


class ODAPI OdEdInputPointFilter : public OdRxObject
{
public:
    ODRX_DECLARE_MEMBERS(OdEdInputPointFilter);

    virtual OdResult processInputPoint(
        bool&                               pointChanged,
        OdGePoint3d&                        updatedPoint,
        bool&                               showOsnapSign,
        bool&                               changeTooltip,
        OdString&                           newTooltip,
        bool&                               repeatInput,
        OdGiViewportDraw*                   pVectorizer,
        OdApDocument*                       pDoc,
        bool                                isPointValid,
        int                                 pointHistory,
        const OdGePoint3d&                  lastPt,
        const OdGePoint3d&                  rawPt,
        const OdGePoint3d&                  gripPt,
        const OdGePoint3d&                  staticSnapPt,
        const OdGePoint3d&                  flyoverSnapPt,
        int                                 osmode,
        const OdRxObjectPtrArray&           customOsmode,
        int                                 osmodeOverride,
        const OdRxObjectPtrArray&           custOsmodeOverride,
        const OdDbObjectIdArray&            coveredObjs,
        const OdArray<OdDbObjectIdArray>&   nestCoveredObjs,
        const OdGsMarkerArray&              selMarkers,
        const OdDbObjectIdArray&            snapObjects,
        const OdArray<OdDbObjectIdArray>&   nestSnapObjs,
        const OdGsMarkerArray&              snapObjsSelMarkers,
        const OdGeCurve3dPtrArray&          alignCurves,
        const OdGePoint3d&                  point,
        const OdString&                     curTooltip) = 0;

    virtual OdEdInputPointFilter* revokeInputFilter(OdEdInputPointFilter* revoked) { return this; }
};

typedef OdSmartPtr<OdEdInputPointFilter> OdEdInputPointFilterPtr;

struct resbuf;

class OdEdInputContextReactor
{
public:
    virtual ~OdEdInputContextReactor() noexcept = default;

    virtual void beginGetAngle(const OdGePoint3d* startPt, const OdChar* prompt,
        int initgetCtrlBits, const OdChar* keyWordList) {}
    virtual void endGetAngle(OdEd::EPromptStatus, double& retAngle, const OdChar*& retKeyWord) {}

    virtual void beginGetColor(const int* defColor, const OdChar* prompt,
        int initgetCtrlBits, const OdChar* keyWordList) {}
    virtual void endGetColor(OdEd::EPromptStatus, int& retColor, const OdChar*& retKeyWord) {}

    virtual void beginGetCorner(const OdGePoint3d* startPt, const OdChar* prompt,
        int initgetCtrlBits, const OdChar* keyWordList) {}
    virtual void endGetCorner(OdEd::EPromptStatus, OdGePoint3d& retCorner, const OdChar*& retKeyWord) {}

    virtual void beginGetDistance(const OdGePoint3d* startPt, const OdChar* prompt,
        int initgetCtrlBits, const OdChar* keyWordList) {}
    virtual void endGetDistance(OdEd::EPromptStatus, double& retDistance, const OdChar*& retKeyWord) {}

    virtual void beginGetInteger(const int* defInteger, const OdChar* prompt,
        int initgetCtrlBits, const OdChar* keyWordList) {}
    virtual void endGetInteger(OdEd::EPromptStatus, int& retInteger, const OdChar*& retKeyWord) {}

    virtual void beginGetKeyword(const OdChar* prompt, int initgetCtrlBits, const OdChar* keyWordList) {}
    virtual void endGetKeyword (OdEd::EPromptStatus, const OdChar*& retKeyWord) {}

    virtual void beginGetOrientation(const OdGePoint3d* startPt, const OdChar* prompt,
        int initgetCtrlBits, const OdChar* keyWordList) {}
    virtual void endGetOrientation(OdEd::EPromptStatus, double& retOrientation, const OdChar*& retKeyWord) {}

    virtual void beginGetPoint(const OdGePoint3d* startPt, const OdChar* prompt,
        int initgetCtrlBits, const OdChar* keyWordList) {}
    virtual void endGetPoint(OdEd::EPromptStatus, const OdGePoint3d& retPoint, const OdChar*& retKeyWord) {}

    virtual void beginGetReal(const double* defReal, const OdChar* prompt,
        int initgetCtrlBits, const OdChar* keyWordList) {}
    virtual void endGetReal(OdEd::EPromptStatus, double& retReal, const OdChar*& retKeyWord) {}

    virtual void beginGetScaleFactor(const OdGePoint3d* startPt, const OdChar* prompt,
        int initgetCtrlBits, const OdChar* keyWordList) {}
    virtual void endGetScaleFactor(OdEd::EPromptStatus, double& retScaleFactor, const OdChar*& retKeyWord) {}

    virtual void beginGetString(const OdChar* prompt, int initgetCtrlBits) {}
    virtual void endGetString (OdEd::EPromptStatus, OdChar* retString) {}

    virtual void beginEntsel(const OdChar* prompt, int initgetCtrlBits, const OdChar* keyWordList) {}
    virtual void endEntsel(OdEd::EPromptStatus, OdDbObjectId& retEntity,
        OdGePoint3d& retPoint, const OdChar*& retKeyWord) {}

    virtual void beginNentsel(const OdChar* prompt, bool usePickPt, int initgetCtrlBits, const OdChar* keyWordList) {}
    virtual void endNentsel(OdEd::EPromptStatus, OdDbObjectId retEntity, const OdGePoint3d& pickPt,
        const OdGeMatrix3d& retEcToWc, const resbuf* retNestedBlocks, const OdChar*& retKeyWord) {}

    virtual void beginSSGet(const OdChar* prompt, int initgetCtrlBits, const OdChar* keyWordList,
        const OdChar* selMode, const OdGePoint3dArray& selPoints, const resbuf* filter) {}
    virtual void endSSGet(OdEd::EPromptStatus, const OdDbObjectIdArray& retSS) {}

    virtual void beginDragSequence(const OdChar* prompt) {}
    virtual void endDragSequence(OdEd::EPromptStatus, OdGePoint3d& retPoint, OdGeVector3d& retVector) {}

    virtual void beginQuiescentState() {}
    virtual void endQuiescentState() {}
};
