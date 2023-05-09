// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDbPointCloudEx.h"
#include "AcPointCloudExtractProfileCurve.h"

class BRX_IMPORTEXPORT ExtractOption
{
public:
    enum ExtractionType
    {
        kOutLine,
        kAllLine
    };

public:
    ExtractionType m_extractionType;
    unsigned int m_processPoints;
    double m_fillGap;
    unsigned int m_snapAngle;
    double m_minSegLength;
    bool m_useLineSegmentOnly;

    ExtractOption();
};

class BRX_IMPORTEXPORT IPointCloudExtracProgressCallback
{
public:
    IPointCloudExtracProgressCallback(void) {}
    virtual ~IPointCloudExtracProgressCallback(void) {}

    virtual void updateProgress(int) = 0;
    virtual void updateCaption(const AcString&) = 0;
    virtual bool cancelled() const = 0;
    virtual void cancel() = 0;
    virtual void updateRemainTime(double) = 0;
    virtual void end() = 0;
};

class BRX_IMPORTEXPORT AcPointCloudExtractor
{
public:
    static Acad::ErrorStatus extract(AcDbPointCloudEx*, const AcGeVector3d&, const AcGeVector3d&,
        AcGePoint3d, const ExtractOption&, AcPointCloudExtractResult&, IPointCloudExtracProgressCallback* = 0);
    static AcDbObjectIdArray appendLineProfile(const AcPointCloudExtractResult&, AcDbObjectId, AcString, AcCmColor);
    static AcDbObjectIdArray appendPolylineProfile(const AcPointCloudExtractResult&, AcDbObjectId, AcString, AcCmColor, double);
};
