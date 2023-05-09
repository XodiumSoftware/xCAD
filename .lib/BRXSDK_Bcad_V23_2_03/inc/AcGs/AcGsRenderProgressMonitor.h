// Copyright (C) Menhirs NV. All rights reserved.
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
        kRender
    };

    virtual bool OnProgress(Phase,float) = 0;
    virtual bool ShouldReuseDatabase();
    virtual void OnTile(int,int,int,int,const BYTE*) = 0;
    virtual void SetStatistics(const AcGsRenderStatistics*) = 0;
};