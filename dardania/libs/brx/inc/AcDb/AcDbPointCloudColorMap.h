// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcDbPointCloudColorMap;
class AcDbPointCloudColorMapImp;

class BRX_IMPORTEXPORT AcPointCloudColorSchemeCollectionReactor
{
public:
    AcPointCloudColorSchemeCollectionReactor();
    virtual ~AcPointCloudColorSchemeCollectionReactor();

    virtual void PointCloudColorSchemeCollectionChanged(AcDbPointCloudColorMap* colorMap) = 0;

private:
    friend AcDbPointCloudColorMapImp;
    class Imp;
    Imp* m_pImp;
};

class BRX_IMPORTEXPORT AcDbPointCloudColorRamp
{
public:
    AcDbPointCloudColorRamp();
    ~AcDbPointCloudColorRamp();

    AcCmEntityColor color(int) const;
    const AcString name() const;
    Adesk::Int32 numColors() const;
    void setColor(int, AcCmEntityColor);
    void setFrom(const AcDbPointCloudColorRamp*);
    Acad::ErrorStatus setName(const AcString&);
    Acad::ErrorStatus setNumColors(Adesk::Int32);
    void setVisibility(int, Adesk::Boolean);
    Adesk::Boolean visibility(int) const;

private:
    friend AcDbPointCloudColorMapImp;
    class Imp;
    Imp* m_pImp;
};

class BRX_IMPORTEXPORT AcDbPointCloudClassificationColorRamp
{
public:
    AcDbPointCloudClassificationColorRamp();
    ~AcDbPointCloudClassificationColorRamp();

    AcCmEntityColor color(int) const;
    const AcString name() const;
    Adesk::Int32 numColors() const;
    void setColor(int, AcCmEntityColor);
    void setFrom(const AcDbPointCloudClassificationColorRamp*);
    Acad::ErrorStatus setName(const AcString&);
    void setVisibility(int, Adesk::Boolean);
    Adesk::Boolean visibility(int) const;

private:
    friend AcDbPointCloudColorMapImp;
    class Imp;
    Imp* m_pImp;
};

class BRX_IMPORTEXPORT AcDbPointCloudColorMap : public AcDbObject
{
    static const Adesk::UInt16 kCurrentObjectVersion;

public:
    ACRX_DECLARE_MEMBERS(AcDbPointCloudColorMap);
    ~AcDbPointCloudColorMap();

    static Acad::ErrorStatus getColorMap(AcDbObjectId&, AcDbDatabase*, Adesk::Boolean = true);

    void addColorSchemeCollectionReactor(AcPointCloudColorSchemeCollectionReactor*);
    void removeColorSchemeCollectionReactor(AcPointCloudColorSchemeCollectionReactor*);
    void notifyColorSchemeCollectionChanged() const;

    const AcString defaultIntensityColorScheme() const;
    Adesk::Boolean setDefaultIntensityColorScheme(const AcString);
    const AcString defaultElevationColorScheme() const;
    Adesk::Boolean setDefaultElevationColorScheme(const AcString);
    const AcString defaultClassificationColorScheme() const;
    Adesk::Boolean setDefaultClassificationColorScheme(const AcString);
    AcStringArray colorSchemeGUIDs() const;
    Adesk::Boolean colorScheme(const ACHAR*, AcDbPointCloudColorRamp&) const;
    Adesk::Boolean hasColorScheme(const ACHAR*) const;
    Adesk::Boolean setColorScheme(const ACHAR*, const AcDbPointCloudColorRamp&);
    Adesk::Boolean deleteColorScheme(const ACHAR*);
    AcStringArray classificationSchemeGUIDs() const;
    Adesk::Boolean classificationScheme(const ACHAR*, AcDbPointCloudClassificationColorRamp&) const;
    Adesk::Boolean hasClassificationScheme(const ACHAR*) const;
    Adesk::Boolean setClassificationScheme(const ACHAR*, const AcDbPointCloudClassificationColorRamp&);
    Adesk::Boolean deleteClassificationScheme(const ACHAR*);
    void getColorSchemeInUse(AcStringArray&) const;
    void getClassificationColorSchemeInUse(AcStringArray&) const;

private:
    friend AcDbPointCloudColorMapImp;
    AcDbPointCloudColorMap();
};
