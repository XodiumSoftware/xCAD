// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbPlotSettings.h"

/** _ */
class BRX_IMPORTEXPORT AcDbPlotSettingsValidator
{
public:
    virtual Acad::ErrorStatus canonicalMediaNameList(AcDbPlotSettings*,AcArray<const ACHAR*>&) = 0;
    virtual Acad::ErrorStatus getLocaleMediaName(AcDbPlotSettings*,const ACHAR*,const ACHAR*&) = 0;
    virtual Acad::ErrorStatus getLocaleMediaName(AcDbPlotSettings*,int,const ACHAR*&) = 0;
    virtual Acad::ErrorStatus plotDeviceList(AcArray<const ACHAR*>&) = 0;
    virtual Acad::ErrorStatus plotStyleSheetList(AcArray<const ACHAR*>&) = 0;
    virtual Acad::ErrorStatus setCanonicalMediaName(AcDbPlotSettings*,const ACHAR*) = 0;
    virtual Acad::ErrorStatus setClosestMediaName(AcDbPlotSettings*,const double,const double,const PlotPaperUnits,Adesk::Boolean) = 0;
    virtual Acad::ErrorStatus setCurrentStyleSheet(AcDbPlotSettings*,const ACHAR*) = 0;
    virtual Acad::ErrorStatus setCustomPrintScale(AcDbPlotSettings*,const double,const double) = 0;
    virtual Acad::ErrorStatus setDefaultPlotConfig(AcDbPlotSettings*) = 0;
    virtual Acad::ErrorStatus setPlotCentered(AcDbPlotSettings*,Adesk::Boolean) = 0;
    virtual Acad::ErrorStatus setPlotCfgName(AcDbPlotSettings*,const ACHAR*,const ACHAR* = NULL) = 0;
    virtual Acad::ErrorStatus setPlotOrigin(AcDbPlotSettings*,const double,const double) = 0;
    virtual Acad::ErrorStatus setPlotPaperUnits(AcDbPlotSettings*,const PlotPaperUnits) = 0;
    virtual Acad::ErrorStatus setPlotRotation(AcDbPlotSettings*,const PlotRotation) = 0;
    virtual Acad::ErrorStatus setPlotType(AcDbPlotSettings*,const PlotType) = 0;
    virtual Acad::ErrorStatus setPlotViewName(AcDbPlotSettings*,const ACHAR*) = 0;
    virtual Acad::ErrorStatus setPlotWindowArea(AcDbPlotSettings*,const double,const double,const double,const double) = 0;
    virtual Acad::ErrorStatus setStdScale(AcDbPlotSettings*,const double) = 0;
    virtual Acad::ErrorStatus setStdScaleType(AcDbPlotSettings*,const StdScaleType) = 0;
    virtual Acad::ErrorStatus setUseStandardScale(AcDbPlotSettings*,Adesk::Boolean) = 0;
    virtual void refreshLists(AcDbPlotSettings*) = 0;
    virtual void setZoomToPaperOnUpdate(AcDbPlotSettings*,Adesk::Boolean) = 0;
};
