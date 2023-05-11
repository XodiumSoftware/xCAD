// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcPl/AcPlPlotLogger.h"
#include "DMM/AcDMMEPlotProperty.h"
#include "DMM/AcDMMResourceInfo.h"
#include "Misc/Ac3dDwfNavTreeNode.h"

/** _ */
class BRX_IMPORTEXPORT AcDMMSheetReactorInfo
{
public:
    enum PlotArea
    {
        kDisplay = 0,
        kExtents,
        kLimits,
        kView,
        kWindow,
        kLayout
    };

    enum PlotMediaUnits
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

protected:
    AcDMMSheetReactorInfo() {}
public:
    virtual ~AcDMMSheetReactorInfo() {}

    virtual Ac3dDwfNavTreeNode* get3dDwfNavigationTreeNode() = 0;
    virtual AcDbDatabase* database() const = 0;
    virtual AcDbObjectId plotLayoutId() const = 0;
    virtual AcPlPlotLogger* GetPlotLogger() = 0;
    virtual bool areLinesHidden() const = 0;
    virtual bool arePlottingLineWeights() const = 0;
    virtual bool areScalingLineWeights() const = 0;
    virtual bool isModelLayout() const = 0;
    virtual bool isPlotJobCancelled() const = 0;
    virtual bool isScaleSpecified() const = 0;
    virtual bool publishingTo3DDwf() const = 0;
    virtual bool set3dDwfNavigationTreeNode(const Ac3dDwfNavTreeNode*) = 0;
    virtual const ACHAR* canonicalMediaName() const = 0;
    virtual const ACHAR* configuration() const = 0;
    virtual const ACHAR* plotToFileName() const = 0;
    virtual const ACHAR* plotToFilePath() const = 0;
    virtual const ACHAR* UniqueLayoutId() = 0;
    virtual const ACHAR* viewPlotted() const = 0;
    virtual double displayMaxX() const = 0;
    virtual double displayMaxY() const = 0;
    virtual double displayMinX() const = 0;
    virtual double displayMinY() const = 0;
    virtual double drawingScale() const = 0;
    virtual double effectivePlotOffsetX() const = 0;
    virtual double effectivePlotOffsetY() const = 0;
    virtual double layoutBoundsMaxX() const = 0;
    virtual double layoutBoundsMaxY() const = 0;
    virtual double layoutBoundsMinX() const = 0;
    virtual double layoutBoundsMinY() const = 0;
    virtual double layoutMarginMaxX() const = 0;
    virtual double layoutMarginMaxY() const = 0;
    virtual double layoutMarginMinX() const = 0;
    virtual double layoutMarginMinY() const = 0;
    virtual double maxBoundsX() const = 0;
    virtual double maxBoundsY() const = 0;
    virtual double originX() const = 0;
    virtual double originY() const = 0;
    virtual double paperScale() const = 0;
    virtual double plotBoundsMaxX() const = 0;
    virtual double plotBoundsMaxY() const = 0;
    virtual double plotBoundsMinX() const = 0;
    virtual double plotBoundsMinY() const = 0;
    virtual double plotWindowMaxX() const = 0;
    virtual double plotWindowMaxY() const = 0;
    virtual double plotWindowMinX() const = 0;
    virtual double plotWindowMinY() const = 0;
    virtual double printableBoundsX() const = 0;
    virtual double printableBoundsY() const = 0;
    virtual double stepsPerInch() const = 0;
    virtual int effectivePlotOffsetXdevice() const = 0;
    virtual int effectivePlotOffsetYdevice() const = 0;
    virtual PlotArea plotArea() const = 0;
    virtual PlotMediaUnits plotMediaUnits() const = 0;
    virtual PlotRotation plotRotation() const = 0;
    virtual void AddPageProperties(AcDMMEPlotPropertyVec) = 0;
    virtual void AddPageResources(AcDMMResourceVec) = 0;
};