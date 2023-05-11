// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"
#include "AcDb/AcDbDimData.h"

/** _ */
class BRX_IMPORTEXPORT AcEdJig: public AcRxObject
{
public:
    enum CursorType
    {
        kNoSpecialCursor = -1,
        kCrosshair,
        kRectCursor,
        kRubberBand,
        kNotRotated,
        kTargetBox,
        kRotatedCrosshair,
        kCrosshairNoRotate,
        kInvisible,
        kEntitySelect,
        kParallelogram,
        kEntitySelectNoPersp,
        kPkfirstOrGrips,
        kCrosshairDashed
    };

    enum DragStatus
    {
        kModeless = -17,
        kNoChange = -6,
        kCancel = -4,
        kOther = -3,
        kNull = -1,
        kNormal,
        kKW1,
        kKW2,
        kKW3,
        kKW4,
        kKW5,
        kKW6,
        kKW7,
        kKW8,
        kKW9
    };

    enum UserInputControls
    {
        kGovernedByOrthoMode = 1,
        kNullResponseAccepted = 2,
        kDontEchoCancelForCtrlC = 4,
        kDontUpdateLastPoint = 8,
        kNoDwgLimitsChecking = 16,
        kNoZeroResponseAccepted = 32,
        kNoNegativeResponseAccepted = 64,
        kAccept3dCoordinates = 128,
        kAcceptMouseUpAsPoint = 256,
        kAnyBlankTerminatesInput = 512,
        kInitialBlankTerminatesInput = 1024,
        kAcceptOtherInputString = 2048,
        kGovernedByUCSDetect = 4096,
        kNoZDirectionOrtho = 8192,
        kImpliedFaceForUCSChange = 16384,
        kUseBasePointElevation = 32768,
        kDisableDirectDistanceInput = 65536
    };

    ACRX_DECLARE_MEMBERS(AcEdJig);

    AcEdJig();
    virtual ~AcEdJig();

    virtual Acad::ErrorStatus setDimValue(const AcDbDimData*,const double);
    virtual AcDbDimDataPtrArray* dimData(const double);
    virtual AcDbEntity* entity() const;
    virtual Adesk::Boolean update();
    virtual DragStatus sampler();

    AcDbObjectId append();
    CursorType specialCursorType();
    UserInputControls userInputControls();
    const ACHAR* dispPrompt();
    const ACHAR* keywordList();
    DragStatus acquireAngle(double&);
    DragStatus acquireAngle(double&,const AcGePoint3d&);
    DragStatus acquireDist(double&);
    DragStatus acquireDist(double&,const AcGePoint3d&);
    DragStatus acquirePoint(AcGePoint3d&);
    DragStatus acquirePoint(AcGePoint3d&,const AcGePoint3d&);
    DragStatus acquireString(ACHAR*);
    DragStatus drag();
    void setDispPrompt(const ACHAR*,...);
    void setKeywordList(const ACHAR*);
    void setSpecialCursorType(CursorType);
    void setUserInputControls(UserInputControls);
};
