// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcPl/AcPlObject.h"

class AcDbPlotSettings;
class AcPlPlotConfig;

/** _ */
class AcPlPlotInfo: public AcPlObject
{
public:
    enum MergeStatus
    {
        kNoChanges = 0,
        kPlotCfgName = 1,
        kPlotPaperMargins = 2,
        kPlotPaperSize = 4,
        kCanonicalMediaName = 8,
        kPlotOrigin = 16,
        kPlotPaperUnits = 32,
        kPlotViewportBorders = 64,
        kPlotPlotStyles = 128,
        kShowPlotStyles = 256,
        kPlotRotation = 512,
        kPlotCentered = 1024,
        kPlotHidden = 2048,
        kShadePlot = 4096,
        kShadePlotResLevel = 8192,
        kShadePlotCustomDPI = 16384,
        kPlotType = 32768,
        kPlotWindowArea = 65536,
        kPlotViewName = 131072,
        kScale = 262144,
        kCurrentStlyeSheet = 524288,
        kScaleLineWeights = 1048576,
        kPrintLineWeights = 2097152,
        kDrawViewportsFirst = 4194304
    };

    ACRX_DECLARE_MEMBERS(AcPlPlotInfo);

    AcPlPlotInfo();
    virtual ~AcPlPlotInfo();

    Acad::ErrorStatus copyFrom(const AcRxObject*);
    Acad::ErrorStatus setValidatedSettings(const AcDbPlotSettings*);
    AcDbObjectId layout() const;
    bool isCompatibleDocument(const AcPlPlotInfo*) const;
    bool isValidated() const;
    const AcDbPlotSettings* overrideSettings() const;
    const AcDbPlotSettings* validatedSettings() const;
    const AcPlPlotConfig* deviceOverride() const;
    const AcPlPlotConfig* validatedConfig() const;
    unsigned long mergeStatus() const;
    void setDeviceOverride(const AcPlPlotConfig*);
    void setLayout(AcDbObjectId&);
    void setOverrideSettings(const AcDbPlotSettings*);
    void setValidatedConfig(const AcPlPlotConfig*);
};
