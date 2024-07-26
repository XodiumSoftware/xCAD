// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class __declspec(novtable) AcPlPlotProgress
{
public:
    enum PlotCancelStatus
    {
        kPlotContinue = 0,
        kPlotCanceledByCaller,
        kPlotCanceledByCancelAllButton,
        kPlotCancelStatusCount
    };

    enum SheetCancelStatus
    {
        kSheetContinue = 0,
        kSheetCanceledByCancelButton,
        kSheetCanceledByCancelAllButton,
        kSheetCanceledByCaller,
        kSheetCancelStatusCount
    };

    virtual ~AcPlPlotProgress() noexcept = default;
    virtual bool getStatusMsgString(ACHAR*&) const = 0;
    virtual bool isPlotCancelled() const = 0;
    virtual bool isSheetCancelled() const = 0;
    virtual bool isVisible() const = 0;
    virtual bool setIsVisible(bool) = 0;
    virtual bool setStatusMsgString(const ACHAR*) = 0;
    virtual int plotProgressPos() const = 0;
    virtual int sheetProgressPos() const = 0;
    virtual PlotCancelStatus plotCancelStatus() const = 0;
    virtual SheetCancelStatus sheetCancelStatus() const = 0;
    virtual void getPlotProgressRange(int&,int&) const = 0;
    virtual void getSheetProgressRange(int&,int&) const = 0;
    virtual void heartbeat() = 0;
    virtual void setPlotCancelStatus(PlotCancelStatus) = 0;
    virtual void setPlotProgressPos(int) = 0;
    virtual void setPlotProgressRange(int,int) = 0;
    virtual void setSheetCancelStatus(SheetCancelStatus) = 0;
    virtual void setSheetProgressPos(int) = 0;
    virtual void setSheetProgressRange(int,int) = 0;
};
