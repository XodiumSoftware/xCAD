// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbPlotSettings: public AcDbObject
{
public:
    enum PlotPaperUnits
    {
        kInches = 0,
        kMillimeters,
        kPixels
    };

    enum PlotRotation
    {
        k0degrees = 0,
        k90degrees,
        k180degrees,
        k270degrees
    };

    enum PlotType
    {
        kDisplay = 0,
        kExtents,
        kLimits,
        kView,
        kWindow,
        kLayout
    };

    enum ShadePlotResLevel
    {
        kDraft = 0,
        kPreview,
        kNormal,
        kPresentation,
        kMaximum,
        kCustom
    };

    enum ShadePlotType
    {
        kAsDisplayed = 0,
        kWireframe,
        kHidden,
        kRendered,
        kVisualStyle,
        kRenderPreset
    };

    enum StdScaleType
    {
        kScaleToFit = 0,
        k1_128in_1ft,
        k1_64in_1ft,
        k1_32in_1ft,
        k1_16in_1ft,
        k3_32in_1ft,
        k1_8in_1ft,
        k3_16in_1ft,
        k1_4in_1ft,
        k3_8in_1ft,
        k1_2in_1ft,
        k3_4in_1ft,
        k1in_1ft,
        k3in_1ft,
        k6in_1ft,
        k1ft_1ft,
        k1_1,
        k1_2,
        k1_4,
        k1_5,
        k1_8,
        k1_10,
        k1_16,
        k1_20,
        k1_30,
        k1_40,
        k1_50,
        k1_100,
        k2_1,
        k4_1,
        k8_1,
        k10_1,
        k100_1,
        k1000_1,
        k1and1_2in_1ft
    };

    ACDB_DECLARE_MEMBERS(AcDbPlotSettings);

    AcDbPlotSettings();
    AcDbPlotSettings(bool);
    virtual ~AcDbPlotSettings();

    Acad::ErrorStatus addToPlotSettingsDict(AcDbDatabase*);
    Acad::ErrorStatus copyFrom(AcDbPlotSettings*);
    Acad::ErrorStatus getCanonicalMediaName(const ACHAR*&) const;
    Acad::ErrorStatus getCurrentStyleSheet(const ACHAR*&) const;
    Acad::ErrorStatus getCustomPrintScale(double&,double&) const;
    Acad::ErrorStatus getPlotCfgName(const ACHAR*&) const;
    Acad::ErrorStatus getPlotOrigin(double&,double&) const;
    Acad::ErrorStatus getPlotPaperMargins(double&,double&,double&,double&) const;
    Acad::ErrorStatus getPlotPaperSize(double&,double&) const;
    Acad::ErrorStatus getPlotSettingsName(ACHAR*&) const;
    Acad::ErrorStatus getPlotSettingsName(const ACHAR*&) const;
    Acad::ErrorStatus getPlotViewName(const ACHAR*&) const;
    Acad::ErrorStatus getPlotWindowArea(double&,double&,double&,double&) const;
    Acad::ErrorStatus getStdScale(double&) const;
    Acad::ErrorStatus setPlotSettingsName(const ACHAR*);
    Acad::ErrorStatus setShadePlot(const ShadePlotType,const AcDbObjectId);
    Acad::ErrorStatus setShadePlot(ShadePlotType);
    Acad::ErrorStatus setShadePlotCustomDPI(Adesk::Int16);
    Acad::ErrorStatus setShadePlotResLevel(ShadePlotResLevel);
    AcDbObjectId shadePlotId() const;
    Adesk::Boolean drawViewportsFirst() const;
    Adesk::Boolean modelType() const;
    Adesk::Boolean plotCentered() const;
    Adesk::Boolean plotHidden() const;
    Adesk::Boolean plotPlotStyles() const;
    Adesk::Boolean plotViewportBorders() const;
    Adesk::Boolean printLineweights() const;
    Adesk::Boolean scaleLineweights() const;
    Adesk::Boolean showPlotStyles() const;
    Adesk::Boolean useStandardScale() const;
    Adesk::Int16 shadePlotCustomDPI() const;
    bool plotAsRaster() const;
    bool plotWireframe() const;
    PlotPaperUnits plotPaperUnits() const;
    PlotRotation plotRotation() const;
    PlotType plotType() const;
    ShadePlotResLevel shadePlotResLevel() const;
    ShadePlotType shadePlot() const;
    StdScaleType stdScaleType() const;
    void setDrawViewportsFirst(Adesk::Boolean);
    void setPlotHidden(Adesk::Boolean);
    void setPlotPlotStyles(Adesk::Boolean);
    void setPlotViewportBorders(Adesk::Boolean);
    void setPrintLineweights(Adesk::Boolean);
    void setScaleLineweights(Adesk::Boolean);
    void setShowPlotStyles(Adesk::Boolean);
};

typedef AcDbPlotSettings::PlotPaperUnits PlotPaperUnits;
typedef AcDbPlotSettings::PlotRotation PlotRotation;
typedef AcDbPlotSettings::PlotType PlotType;
typedef AcDbPlotSettings::StdScaleType StdScaleType;
