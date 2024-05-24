// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcPl/AcPlPlotProgress.h"
#include "AcRx/AcRxObject.h"

class AcPlPlotInfo;
class AcPlPlotPageInfo;

/** _ */
class AcPlPlotReactor: public AcRxObject
{
public:
    enum PlotType
    {
        kPlot = 0,
        kPreview,
        kBackgroundPackaging,
        kBackgroundPlot
    };

protected:
    AcPlPlotReactor();
public:
    virtual ~AcPlPlotReactor();

    virtual void beginDocument(AcPlPlotInfo&,const ACHAR*,long = 1,bool = false,const ACHAR* = NULL);
    virtual void beginPage(AcPlPlotPageInfo&,AcPlPlotInfo&,bool);
    virtual void beginPlot(AcPlPlotProgress*,PlotType);
    virtual void endDocument(AcPlPlotProgress::PlotCancelStatus);
    virtual void endPage(AcPlPlotProgress::SheetCancelStatus);
    virtual void endPlot(AcPlPlotProgress::PlotCancelStatus);
    virtual void pageCancelled();
    virtual void plotCancelled();

//BRX START
//V12
private:
    friend class AcPlPlotReactorMgr;
    void* m_pBrxImp;
//BRX END

};
