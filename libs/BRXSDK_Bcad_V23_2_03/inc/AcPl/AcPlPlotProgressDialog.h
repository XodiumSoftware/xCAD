// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcPl/AcPlPlotProgress.h"

/** _ */
class AcPlPlotProgressDialog: public AcPlPlotProgress
{
public:
    enum PlotMSGIndex
    {
        kDialogTitle = 0,
        kSheetName,
        kSheetNameToolTip,
        kStatus,
        kSheetProgressCaption,
        kSheetSetProgressCaption,
        kMsgCancelling,
        kMsgCancellingCurrent,
        kCancelSheetBtnMsg,
        kCancelJobBtnMsg,
        kMsgCount
    };

    virtual bool getPlotMsgString(PlotMSGIndex,ACHAR*&) const = 0;
    virtual bool isSingleSheetPlot() const = 0;
    virtual bool onBeginPlot() = 0;
    virtual bool onBeginSheet() = 0;
    virtual bool onEndPlot() = 0;
    virtual bool onEndSheet() = 0;
    virtual bool setPlotMsgString(PlotMSGIndex,const ACHAR*) = 0;
    virtual void destroy() = 0;
};
