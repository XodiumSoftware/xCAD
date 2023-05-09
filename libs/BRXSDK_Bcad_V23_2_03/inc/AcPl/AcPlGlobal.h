// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"
#include "AcPl/AcPlDSDData.h"

//common forward declarations
class AcDbPlotSettings;
class AcPlHostAppServices;
class AcPlPlotConfig;
class AcPlPlotConfigManager;
class AcPlPlotProgressDialog;
class AcPlPlotReactorMgr;
class AcPlDSDData;

enum DeviceType
{
    kUninitialized = -1,
    kSystemPrinter =  0,
    kPC3File,
    kOneOffConfig
};

enum PreviewStatus
{
    kNormal = 0,
    kPlot,
    kCancel,
    kNext,
    kPrevious
};

enum ProcessPlotState
{
    kNotPlotting = 0,
    kForegroundPlotting,
    kBackgroundPlotting
};

struct ACPL_PREVIEWENDPLOT
{
    PreviewStatus nStatus;
};

Acad::ErrorStatus AcPlSetHostAppServices(AcPlHostAppServices*);
AcPlHostAppServices* AcPlGetHostAppServices();

AcPlPlotConfigManager* __stdcall acplPlotConfigManagerPtr();
#define acplPlotConfigManager acplPlotConfigManagerPtr()

ProcessPlotState __stdcall acplProcessPlotState();

typedef void (*ACPLPLTPRGHELPPROC)(AcPlPlotProgressDialog*);
AcPlPlotProgressDialog* __stdcall acplCreatePlotProgressDialog(HWND,bool = false,int = 1,ACPLPLTPRGHELPPROC = NULL,bool = true);

AcPlPlotReactorMgr* __stdcall acplPlotReactorMgrPtr();
#define acplPlotReactorMgr acplPlotReactorMgrPtr()

void acplPublishExecute(AcPlDSDData, AcPlPlotConfig*, bool);
