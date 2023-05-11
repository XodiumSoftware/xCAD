// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class AcPointCloudItemImp;
class AcPointCloudItem;
typedef AcPointCloudItem* PPointCloudItem;
typedef AcArray<AcPointCloudItem*> AcPointCloudItemArray;

class BRX_IMPORTEXPORT AcPointCloudItem
{
public:
    enum AcPointCloudItemType
    {
        kLegacyPointCloud = 0,
        kPointCloudProject,
        kIndividualScan,
        kScan,
        kRegion,
        kScanRootGroup,
        kRegionRootGroup,
        kUnassignedPoint
    };

public:
    AcPointCloudItem();
    ~AcPointCloudItem() {}
    AcPointCloudItem(const AcString&, const AcString&, int objectid, AcPointCloudItemType, bool = true, bool = false, AcString = ACRX_T(""));
    AcPointCloudItem(const AcPointCloudItem&);
    AcPointCloudItem& operator =  (const AcPointCloudItem&);

    static AcPointCloudItem* CreateFromCmdString(const ACHAR*);

public:
    void setName(const AcString&);
    AcString name() const;
    void setProjectName(const AcString&);
    AcString projectName() const;
    void setGuid(const AcString&);
    const AcString& guid() const;
    void setId(int);
    int id() const;
    void setVisibility(bool);
    bool visibility() const;
    void setHighlight(bool);
    bool highlight() const;
    void setColor(float, float, float);
    float red() const;
    float green() const;
    float blue() const;
    void setAdsName(const ads_name&);
    const ads_name& adsName() const;
    void setItemType(AcPointCloudItemType);
    AcPointCloudItemType itemType() const;

private:
    void copyItem(const AcPointCloudItem&);

private:
    AcPointCloudItemImp* m_pImp;
};
