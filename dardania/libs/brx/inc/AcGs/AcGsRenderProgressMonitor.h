// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGs/AcGsRenderStatistics.h"

/** _ */
class BRX_IMPORTEXPORT AcGsRenderProgressMonitor
{
public:
    enum Phase
    {
        kTranslation = 0,
        kPhotonEmission,
        kFinalGather,
        kRender,
        kDraft,
        kInitialize
    };

    enum RenderingStatus
    {
        kRendering,
        kPaused,
        kFinished,
        kAborted,
        kWillNotRender,
        kSoftOutOfMemory,
        kHardOutOfMemory,
        kError
    };

    virtual bool IsAsync();
    virtual bool IsOutputImageFlipped();
    virtual bool IsValid();
    virtual bool OnProgress(Phase, float, int, int, float, int = 0) = 0;
    virtual bool OnProgress(Phase,float) = 0;   //deprecated
    virtual void OnStatusChanged(RenderingStatus) = 0;
    virtual void OnTile(int, int, int, int, const unsigned char*) = 0;
    virtual void OnTile(int,int,int,int,const BYTE*) = 0;   //deprecated
    virtual bool ShouldReuseDatabase();
    virtual void SetStatistics(const AcGsRenderStatistics*) = 0;
};