// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcDbPointCloudCropStateManagerImp;
class AcDbPointCloudEx;
class PointCloudExImp;
class PointCloudCropStateRoundtripManager;

class BRX_IMPORTEXPORT AcDbPointCloudCropStateManager
{
public:
    Acad::ErrorStatus restoreCropState(const AcString&);
    Acad::ErrorStatus getAllCropStates(AcArray<AcString>&) const;
    Acad::ErrorStatus removeCropState(const AcString&);
    Acad::ErrorStatus renameCropState(const AcString&, const AcString&);
    Acad::ErrorStatus addCropState(const AcString&);
    AcString currentCropState() const;

private:
    AcDbPointCloudCropStateManager();
    AcDbPointCloudCropStateManager(AcDbPointCloudEx*);
    virtual ~AcDbPointCloudCropStateManager();

private:
    AcDbPointCloudCropStateManagerImp* m_pImpCropStatesManager;
    friend PointCloudExImp;
    friend PointCloudCropStateRoundtripManager;
};
