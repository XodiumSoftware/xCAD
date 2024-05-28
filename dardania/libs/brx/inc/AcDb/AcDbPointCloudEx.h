// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcPointCloudItem.h"

class CPoint;
class PointCloudExImp;
class AcDbPointCloudCrop;
class AcDbPointCloudExLimitBox;
class PointCloudPerfMonitor;
class IAcDbPointCloudAttributeFilter;
class IAcDbPointCloudDataBuffer;
class IAcDbPointCloudPointProcessor;
class IAcDbPointCloudSpatialFilter;
class IAcDbPointCloudAttributeFilter;
class AcPointCloudExtractedCylinder;
class AcDbPointCloudCropStateManager;
class AcDbPointCloudCropStateManagerImp;

class BRX_IMPORTEXPORT AcDbPointCloudEx : public AcDbEntity
{
public:
    enum PointCloudOSnapMode
    {
        kOsModePNod = 0,
        kOsModePNea = 1,
        kOsModePPer = 2,
        kOsModePEdgeNea = 3,
        kOsModePEdgePer = 4,
        kOsModePInt = 5,
        kOsModePCL = 6,
        kOsModePCorner = 7
    };

    enum StylizationType
    {
        kTrueColor = 1,
        kSingleColor = 2,
        kNormalRamp = 3,
        kHeightRamp = 4,
        kIntensityRamp = 5,
        kClassificationRamp = 6,
        // BRX only
        kIntensityGamma = 101,
        kIntensityShadow = 102,
        kPlaneDeviationRamp = 103,
        // BRX internal
        kTempRegion = 201
    };

    enum DispOptionOutOfRange
    {
        kUseMinMaxColors = 0,
        kUseRGBScanColors = 1,
        kHidePoints = 2
    };

public:
    ACRX_DECLARE_MEMBERS(AcDbPointCloudEx);
    AcDbPointCloudEx();
    ~AcDbPointCloudEx();

public:
    void setPointCloudDefExId(const AcDbObjectId&);
    AcDbObjectId pointCloudDefExId() const;
    void setReactorId(const AcDbObjectId&);
    AcDbObjectId reactorId() const;
    bool locked()const;
    void setLocked(bool);
    double scale() const;
    Acad::ErrorStatus setScale(double);
    double rotation() const;
    Acad::ErrorStatus setRotation(double);
    AcGePoint3d location() const;
    Acad::ErrorStatus setLocation(const AcGePoint3d&);
    void getNativeCloudExtent(AcDbExtents&) const;
    unsigned int getVisiblePointCount() const;
    unsigned int getLoadedVisiblePointCount() const;
    unsigned int getDisplayedVisiblePointCount() const;
    PointCloudPerfMonitor* getPointCloudPerfMonitor();
    bool setActiveFileName(const ACHAR*);
    bool getActiveFileName(AcString&) const;
    AcString getPointCloudName() const;
    Acad::ErrorStatus setPointCloudName(const AcString&);
    int getCroppingCount() const;
    AcDbPointCloudCrop* getPointCloudCropping(int);
    const AcDbPointCloudCrop* getPointCloudCroppingConst(int) const;
    void addCroppingBoundary(const AcDbPointCloudCrop&);
    Acad::ErrorStatus clearCropping();
    Acad::ErrorStatus removeLastCropping();
    bool getCroppingInvert() const;
    Acad::ErrorStatus setCroppingInvert(bool);
    void setInCreatingCroppingMode(bool );
    bool showCropped() const;
    Acad::ErrorStatus setShowCropped(bool);
    Acad::ErrorStatus setStylizationType(StylizationType);
    StylizationType stylizationType() const;
    AcString getCurrentColorScheme() const;
    Acad::ErrorStatus setCurrentColorScheme(const AcString&);
    AcString getColorSchemeForStylization(StylizationType) const;
    Acad::ErrorStatus setColorSchemeForStylization(const AcString&, StylizationType);
    bool showIntensityAsGradient() const;
    void setShowIntensityAsGradient(bool);
    Adesk::Int32 minIntensity() const;
    Adesk::Int32 maxIntensity() const;
    Acad::ErrorStatus setMinMaxIntensity(Adesk::Int32 min, Adesk::Int32 max);
    DispOptionOutOfRange intensityOutOfRangeBehavior() const;
    void setIntensityOutOfRangeBehavior(DispOptionOutOfRange);
    bool showElevationAsGradient() const;
    void setShowElevationAsGradient(bool);
    double minElevation() const;
    double maxElevation() const;
    Acad::ErrorStatus setMinMaxElevation(double, double);
    bool elevationApplyToFixedRange() const;
    void setElevationApplyToFixedRange(bool);
    DispOptionOutOfRange elevationOutOfRangeBehavior() const;
    void setElevationOutOfRangeBehavior(DispOptionOutOfRange);
    void getLimitBox(AcDbPointCloudExLimitBox&) const;
    Acad::ErrorStatus setLimitBox(const AcDbPointCloudExLimitBox&);
    void resetLimitBox();
    void setHighlightLimitboxBoundary(bool);
    const AcPointCloudItemArray* getPointCloudDataList() const;
    AcPointCloudItem* findScanItem(const AcString&);
    AcPointCloudItem* findRegionItem(Adesk::Int32);
    void setScanVisibility(const AcString&, bool);
    void setAllScansVisibility(bool);
    void setRegionVisibility(Adesk::Int32, bool);
    void setAllRegionsVisibility(bool, bool = false);
    void setAllScansVisibilityByRegion(Adesk::Int32, bool);
    bool getScanViewInfo(const AcString&, AcGePoint3d&, AcDbExtents&) const;
    void resetScanRegionVisibility();
    void setAllScanHighlight(bool);
    void setAllRegionHighlight(bool, bool = false);
    void applyGeoLocation(bool = false, const AcString& = ACRX_T(""));
    void updateGeoLocation();
    void clearGeoLocation();
    bool geolocate() const;
    Acad::ErrorStatus getCustomOsnapInfo(PointCloudOSnapMode, const AcGePoint3d&, const AcGePoint3d&, const AcGeMatrix3d&, AcGePoint3dArray&);
    Acad::ErrorStatus getPointDataByPointCount(IAcDbPointCloudDataBuffer*&, Adesk::UInt32, IAcDbPointCloudSpatialFilter* pSpatialFilter,
        IAcDbPointCloudAttributeFilter*, Adesk::UInt32, Adesk::UInt32) const;
    Acad::ErrorStatus traverseAllPointData(IAcDbPointCloudPointProcessor*, IAcDbPointCloudSpatialFilter*, Adesk::UInt32, int) const;
    Acad::ErrorStatus addSpatialFilter(IAcDbPointCloudSpatialFilter*);
    Acad::ErrorStatus removeSpatialFilter(IAcDbPointCloudSpatialFilter*);
    void  clearSpatialFilters();
    Acad::ErrorStatus addAttributeFilter(IAcDbPointCloudAttributeFilter*);
    Acad::ErrorStatus removeAttributeFilter(IAcDbPointCloudAttributeFilter*);
    void  clearAttributeFilters();
    bool  getPlaneOrPointAt(const AcGeMatrix3d&, const AcGePoint3d&, AcGePoint3dArray&);
    bool  getPlaneBoundaryAt(const AcGeMatrix3d&, const AcGePoint3d&, AcGePoint3dArray&);
    void* getQuery();
    void objectToWorldMatrix(AcGeMatrix3d&) const;
    Acad::ErrorStatus getCandidatePlane(const CPoint&, AcGePlane&, double&, double&, double&, void*&) const;
    Acad::ErrorStatus getCylinderAt(const AcGeMatrix3d&, const AcGePoint3d&, AcGePoint3d&, AcGeVector3d&, double&, double&);
    const AcDbPointCloudCropStateManager* cropStatesManagerConst() const;
    AcDbPointCloudCropStateManager* cropStatesManager();
    Acad::ErrorStatus getMinDistPrecision(double&) const;
    Acad::ErrorStatus getPointDataByPrecision(IAcDbPointCloudDataBuffer*&, double, IAcDbPointCloudSpatialFilter* = NULL,
        IAcDbPointCloudAttributeFilter* = NULL, Adesk::UInt32 = 0, Adesk::UInt32 = 1000000u) const;
    Acad::ErrorStatus getEstimatedPointCountByPrecision(Adesk::UInt64&, double, IAcDbPointCloudSpatialFilter* = NULL, IAcDbPointCloudAttributeFilter* = NULL) const;
    Acad::ErrorStatus getCylinderAt(const AcGeMatrix3d&, const AcGePoint3d&, AcPointCloudExtractedCylinder&);
    Acad::ErrorStatus detectPointBelonger(const AcGePoint3d&, AcString&, Adesk::UInt16&) const;
    Acad::ErrorStatus getPointDataBySegment(IAcDbPointCloudDataBuffer*&, const AcString&, Adesk::UInt16, Adesk::UInt32) const;
    Acad::ErrorStatus getPointDataByPointCount(IAcDbPointCloudDataBuffer*&, Adesk::UInt32, const AcStringArray&, IAcDbPointCloudSpatialFilter*,
        IAcDbPointCloudAttributeFilter*, Adesk::UInt32, Adesk::UInt32) const;
    Acad::ErrorStatus traverseAllPointData(IAcDbPointCloudPointProcessor*, IAcDbPointCloudSpatialFilter*, Adesk::UInt32, int, const AcStringArray&) const;

private:
    PointCloudExImp* m_pImp;
    friend AcDbPointCloudCropStateManagerImp;
};
