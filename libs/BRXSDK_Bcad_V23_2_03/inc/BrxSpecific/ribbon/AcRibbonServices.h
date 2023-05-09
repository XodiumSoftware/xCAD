// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcRibbonBase.h"

class AcRibbonPaletteSet;

class BRX_EXPORT AcRibbonServices
{
    friend class AcRibbonInternal;
public:
    static AcRibbonPaletteSet* createRibbonPaletteSet();
    static AcRibbonPaletteSet* ribbonPaletteSet();

private:
    AcRibbonServices();
    AcRibbonServices(const AcRibbonServices&) = default;
    AcRibbonServices& operator= (const AcRibbonServices&) = default;
    ~AcRibbonServices();
    static void destroyRibbonPaletteSet();

private:
    static AcRibbonPaletteSet* s_pRibbonPaletteSet;
};

class AcRibbonReactorMgr;

AcRibbonReactorMgr* __stdcall acRibbonReactorMgrPtr();
