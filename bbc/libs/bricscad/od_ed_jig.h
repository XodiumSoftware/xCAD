// od_ed_jig.h : OdEdJig class definition

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "od_api_exports.h"

#include "DbDimData.h"

class OdEdJigImpl;

class ODAPI OdEdJig: public OdRxObject
{
public:
    volatile bool m_keepFrameImageFlag;

    ODRX_DECLARE_MEMBERS(OdEdJig);

    enum EUserInputControls
    {
        eGovernedByOrthoMode          = 1,
        eNullResponseAccepted         = 1 << 1,
        eDontEchoCancelForCtrlC       = 1 << 2,
        eDontUpdateLastPoint          = 1 << 3,
        eNoDwgLimitsChecking          = 1 << 4,
        eNoZeroResponseAccepted       = 1 << 5,
        eNoNegativeResponseAccepted   = 1 << 6,
        eAccept3dCoordinates          = 1 << 7,
        eAcceptMouseUpAsPoint         = 1 << 8,
        eAnyBlankTerminatesInput      = 1 << 9,
        eInitialBlankTerminatesInput  = 1 << 10,
        eAcceptOtherInputString       = 1 << 11,
        eGovernedByUCSDetect          = 1 << 12,
        eNoZDirectionOrtho            = 1 << 13,
        eImpliedFaceForUCSChange      = 1 << 14, //not yet used
        eUseBasePointElevation        = 1 << 15, //not yet used
        eDisableDirectDistanceInput   = 1 << 16,
        eIgnoreGridSnap               = 1 << 17
    };

    enum EDragStatus
    {
        eModeless = -17,
        eNoChange = -6,
        eCancel   = -4,
        eOther    = -3,
        eNull     = -1,
        eNormal   = 0,
        eKW1,
        eKW2,
        eKW3,
        eKW4,
        eKW5,
        eKW6,
        eKW7,
        eKW8,
        eKW9
    };

    enum ECursorType
    {
        eNoSpecialCursor = -1,
        eCrosshair = 0,
        eRectCursor,
        eRubberBand,
        eNotRotated,
        eTargetBox,
        eRotatedCrosshair,
        eCrosshairNoRotate,
        eInvisible,
        eEntitySelect,
        eParallelogram,
        eEntitySelectNoPersp,
        ePkfirstOrGrips,
        eCrosshairDashed
    };

    OdEdJig();
    virtual ~OdEdJig();

    EDragStatus drag();
    OdDbObjectId append();

    virtual EDragStatus sampler();
    virtual void afterDraw();

    virtual bool update();
    virtual OdDbEntity* entity() const;
    virtual OdDbDimDataPtrArray* dimData(const double scale);
    virtual OdResult setDimValue(const OdDbDimData* data, const double value);

    EDragStatus acquireAngle(double& angle);
    EDragStatus acquireAngle(double& angle, const OdGePoint3d& basePoint);
    EDragStatus acquireDist(double& distance);
    EDragStatus acquireDist(double& distance, const OdGePoint3d& basePoint);
    EDragStatus acquirePoint(OdGePoint3d& point);
    EDragStatus acquirePoint(OdGePoint3d& point, const OdGePoint3d& basePoint);
    EDragStatus acquireString(OdChar* s);

    const OdChar* keywordList();
    void setKeywordList(const OdChar* keywords);

    const OdChar* dispPrompt();
    void setDispPrompt(const OdChar*, ...);

    ECursorType specialCursorType();
    void setSpecialCursorType(ECursorType type);

    EUserInputControls userInputControls();
    void setUserInputControls(EUserInputControls controls);
    
    bool supportsRenderTraits() const;

private:
    OdEdJigImpl* m_impl;
};
