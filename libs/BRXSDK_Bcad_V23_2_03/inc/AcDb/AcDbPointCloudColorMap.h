// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class AcDbPointCloudMgr;
class PointCloudColorMapImp;
class PointCloudColorRampImp;
class PointCloudClassificationColorRampImp;

class BRX_IMPORTEXPORT AcPointCloudColorSchemeCollectionReactor
{
public:
    virtual void PointCloudColorSchemeCollectionChanged(class AcDbPointCloudColorMap* colorMap) = 0;
    virtual ~AcPointCloudColorSchemeCollectionReactor();
};

class BRX_IMPORTEXPORT AcDbPointCloudColorRamp
{
public:
    AcDbPointCloudColorRamp();
    ~AcDbPointCloudColorRamp();
    Adesk::Int32 numColors() const;
    Acad::ErrorStatus setNumColors(Adesk::Int32);
    AcCmEntityColor color(int) const;
    void setColor(int, AcCmEntityColor);
    bool visibility(int) const;
    void setVisibility(int, bool);
    void setFrom(const AcDbPointCloudColorRamp*);
    const AcString name() const;
    Acad::ErrorStatus setName(const AcString&);

    Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);

private:
    PointCloudColorRampImp* m_pImp;
    friend PointCloudColorMapImp;
};

class BRX_IMPORTEXPORT AcDbPointCloudClassificationColorRamp
{
public:
    AcDbPointCloudClassificationColorRamp();
    ~AcDbPointCloudClassificationColorRamp();
    Adesk::Int32 numColors() const;
    AcCmEntityColor color(int) const;
    void setColor(int, AcCmEntityColor);
    bool visibility(int) const;
    void setVisibility(int, bool);
    void setFrom(const AcDbPointCloudClassificationColorRamp*);
    const AcString name() const;
    Acad::ErrorStatus setName(const AcString&);

private:
    Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);

private:
    PointCloudClassificationColorRampImp* m_pImp;
    friend PointCloudColorMapImp;
};

class BRX_IMPORTEXPORT AcDbPointCloudColorMap : public AcDbObject
{
    friend PointCloudColorMapImp;
    friend AcDbPointCloudMgr;

    static const Adesk::UInt16 kCurrentObjectVersion;

public:
    ACRX_DECLARE_MEMBERS(AcDbPointCloudColorMap);
    static Acad::ErrorStatus getColorMap(AcDbObjectId&, AcDbDatabase*, bool = true);
    ~AcDbPointCloudColorMap();
    void addColorSchemeCollectionReactor(AcPointCloudColorSchemeCollectionReactor*);
    void removeColorSchemeCollectionReactor(AcPointCloudColorSchemeCollectionReactor*);
    void notifyColorSchemeCollectionChanged() const;
    const AcString defaultIntensityColorScheme() const;
    bool setDefaultIntensityColorScheme(const AcString);
    const AcString defaultElevationColorScheme() const;
    bool setDefaultElevationColorScheme(const AcString);
    const AcString defaultClassificationColorScheme() const;
    bool setDefaultClassificationColorScheme(const AcString);
    AcArray<AcString> colorSchemeGUIDs() const;
    bool colorScheme(const wchar_t*, AcDbPointCloudColorRamp&) const;
    bool hasColorScheme(const wchar_t*) const;
    bool setColorScheme(const wchar_t*, const AcDbPointCloudColorRamp&);
    bool deleteColorScheme(const wchar_t*);
    AcArray<AcString> classificationSchemeGUIDs() const;
    bool classificationScheme(const wchar_t*, AcDbPointCloudClassificationColorRamp&) const;
    bool hasClassificationScheme(const wchar_t*) const;
    bool setClassificationScheme(const wchar_t*, const AcDbPointCloudClassificationColorRamp&);
    bool deleteClassificationScheme(const wchar_t*);
    void getColorSchemeInUse(AcArray<AcString>&) const;
    void getClassificationColorSchemeInUse(AcArray<AcString>&) const;
    Acad::ErrorStatus dwgInFields(AcDbDwgFiler*) override;
    Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const override;
    Acad::ErrorStatus dxfInFields(AcDbDxfFiler*) override;
    Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const override;
    Acad::ErrorStatus subClose() override;

private:
    AcDbPointCloudColorMap();
    AcDbPointCloudColorMap(bool);

private:
    PointCloudColorMapImp* m_pImp;
};
