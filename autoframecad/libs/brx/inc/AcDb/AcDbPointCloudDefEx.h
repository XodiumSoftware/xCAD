// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class PointCloudDefExImp;
typedef struct tagBITMAPINFO BITMAPINFO;

static const ACHAR* kpPointCloudExDictionaryName = ACRX_T("ACAD_POINTCLOUD_EX_DICT");

class BRX_IMPORTEXPORT AcDbPointCloudDefEx : public AcDbObject
{
public:
    enum PropState
    {
        kNone = -1,
        kSome = 0,
        kAll = 1
    };

    enum Property
    {
        kColor = 1,
        kIntensity = 2,
        kClassification = 3,
        kNormal = 4,
        kSegmentation = 5,
        kGeoGraphic = 6
    };

    ACRX_DECLARE_MEMBERS(AcDbPointCloudDefEx);

    AcDbPointCloudDefEx();
    ~AcDbPointCloudDefEx();

    static Adesk::Int32 classVersion();
    static Acad::ErrorStatus createPointCloudExDictionary(AcDbDatabase*, AcDbObjectId&);
    static AcDbObjectId pointCloudExDictionary(AcDbDatabase*);
    static AcDbDictionary* getPointCloudExDictionary(AcDbPointCloudDefEx*);

    Acad::ErrorStatus load();
    Acad::ErrorStatus unload();
    Adesk::Boolean isLoaded() const;
    Adesk::Int32 entityCount(Adesk::Boolean* = nullptr) const;
    Acad::ErrorStatus setSourceFileName(const ACHAR*);
    const ACHAR* sourceFileName() const;
    Acad::ErrorStatus setActiveFileName(const ACHAR*);
    const ACHAR* activeFileName() const;
    const ACHAR* fileType() const;
    Adesk::UInt64 totalPointsCount() const;
    Adesk::Int32 totalRegionsCount() const;
    Adesk::Int32 totalScansCount() const;
    double defaultWidth() const;
    double defaultLength() const;
    double defaultHeight() const;
    PropState hasProperty(Property) const;
    Acad::ErrorStatus createThumbnailBitmap(BITMAPINFO*&, Adesk::Int32, Adesk::Int32) const;
    AcDbExtents extents() const;
    const ACHAR* coordinateSystemName() const;
    const ACHAR* getRcsFilePath(const AcString&) const;
    void getAllRcsFilePaths(AcStringArray&) const;
};
