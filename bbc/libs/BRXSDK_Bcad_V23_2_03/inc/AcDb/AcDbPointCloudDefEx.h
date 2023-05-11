// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class PointCloudDefExImp;

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

    static int classVersion();
    static Acad::ErrorStatus createPointCloudExDictionary(AcDbDatabase*, AcDbObjectId&);
    static AcDbObjectId pointCloudExDictionary(AcDbDatabase*);
    static AcDbDictionary* getPointCloudExDictionary(AcDbPointCloudDefEx*);

    //Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
    //Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const override;
    //Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
    //Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const override;
    //Acad::ErrorStatus subErase(Adesk::Boolean) override;

    Acad::ErrorStatus load();
    Acad::ErrorStatus unload();
    Adesk::Boolean isLoaded() const;
    int entityCount(Adesk::Boolean* = 0) const;
    Acad::ErrorStatus setSourceFileName(const TCHAR*);
    const TCHAR* sourceFileName() const;
    Acad::ErrorStatus setActiveFileName(const TCHAR*);
    const TCHAR* activeFileName() const;
    const TCHAR* fileType() const;
    unsigned long long totalPointsCount() const;
    int totalRegionsCount() const;
    int totalScansCount() const;
    double defaultWidth() const;
    double defaultLength() const;
    double defaultHeight() const;
    PropState hasProperty(Property) const;
    Acad::ErrorStatus createThumbnailBitmap(BITMAPINFO*&, int, int) const;
    AcDbExtents extents() const;
    const TCHAR* coordinateSystemName() const;
    const TCHAR* getRcsFilePath(const AcString&) const;
    void getAllRcsFilePaths(AcStringArray&) const;

private:
    PointCloudDefExImp* m_pImp;
};
