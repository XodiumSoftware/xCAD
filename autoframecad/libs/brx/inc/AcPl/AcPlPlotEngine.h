// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

class AcPlPlotInfo;
class AcPlPlotPageInfo;
class AcPlPlotProgress;

/** _ */
class AcPlPlotEngine
{
public:
    virtual Acad::ErrorStatus beginDocument(AcPlPlotInfo&,const ACHAR*,void* = NULL,long = 1L,bool = false,const ACHAR* = NULL);
    virtual Acad::ErrorStatus beginGenerateGraphics(void* = NULL);
    virtual Acad::ErrorStatus beginPage(AcPlPlotPageInfo&,AcPlPlotInfo&,bool,void* = NULL);
    virtual Acad::ErrorStatus beginPlot(AcPlPlotProgress*,void* = NULL);
    virtual Acad::ErrorStatus endDocument(void* = NULL);
    virtual Acad::ErrorStatus endGenerateGraphics(void* = NULL);
    virtual Acad::ErrorStatus endPage(void* = NULL);
    virtual Acad::ErrorStatus endPlot(void* = NULL);
    virtual bool isBackgroundPackaging() const;
    virtual void destroy();
};
