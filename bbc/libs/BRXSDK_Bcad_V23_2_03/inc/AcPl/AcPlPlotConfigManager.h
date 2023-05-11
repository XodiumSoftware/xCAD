// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/AcArray.h"

class AcPlPlotConfig;
class AcPlPlotConfigInfo;

/** _ */
class __declspec(novtable) AcPlPlotConfigManager
{
public:

    enum RefreshCode
    {
        kAll = 0,
        kRefreshDevicesList,
        kRefreshStyleList,
        kRefreshSystemDevicesList,
        kRefreshPC3DevicesList
    };

    enum StdConfigs
    {
        kNoneDevice = 0,
        kDefaultWindowsSysPrinter,
        kDWF6ePlot,
        kDWFePlotOptForPlotting,
        kDWFePlotOptForViewing,
        kPublishToWebDWF,
        kPublishToWebJPG,
        kPublishToWebPNG
    };

    enum StyTypes
    {
        kUndefined = 0,
        kRegular = 1,
        kTranslation = 2,
        kColorDep = 4,
        kAllTypes = 7
    };

    virtual Acad::ErrorStatus getCurrentConfig(AcPlPlotConfig*&);
    virtual Acad::ErrorStatus setCurrentConfig(AcPlPlotConfig*&,const ACHAR*);
    virtual bool getDevicesList(AcArray< AcPlPlotConfigInfo,AcArrayObjectCopyReallocator<AcPlPlotConfigInfo> >&);
    virtual bool getStyleList(AcArray<ACHAR*>&,long = kAllTypes);
    virtual const ACHAR* getStdConfigName(StdConfigs);
    virtual void refreshList(RefreshCode = kAll);
};
