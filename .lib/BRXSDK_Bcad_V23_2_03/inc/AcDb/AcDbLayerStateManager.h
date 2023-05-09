// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

class AcDbLayerStateManagerReactor;

/** _ */
class BRX_IMPORTEXPORT AcDbLayerStateManager: public AcRxObject
{
public:
    enum
    {
        kUndefDoNothing = 0,
        kUndefTurnOff,
        kUndefFreeze
    };

    enum LayerStateMask
    {
        kNone = 0,
        kOn = 1,
        kFrozen = 2,
        kLocked = 4,
        kPlot = 8,
        kNewViewport = 16,
        kColor = 32,
        kLineType = 64,
        kLineWeight = 128,
        kPlotStyle = 256,
        kCurrentViewport = 512,
        kAll = 1023,
        kStateIsHidden = 32768
    };

    ACRX_DECLARE_MEMBERS(AcDbLayerStateManager);

    AcDbLayerStateManager();
    AcDbLayerStateManager(AcDbDatabase*);
    virtual ~AcDbLayerStateManager();

    Acad::ErrorStatus addLayerStateLayers(const ACHAR*,const AcDbObjectIdArray&);
    bool addReactor(AcDbLayerStateManagerReactor*);
    bool compareLayerStateToDb(const ACHAR*,const AcDbObjectId&);
    Acad::ErrorStatus deleteLayerState(const ACHAR*);
    Acad::ErrorStatus exportLayerState(const ACHAR*,const ACHAR*);
    AcDbDatabase* getDatabase() const;
    Acad::ErrorStatus getLastRestoredLayerState(AcString&, AcDbObjectId&);
    Acad::ErrorStatus getLayerStateDescription(const ACHAR*,ACHAR*&);
    Acad::ErrorStatus getLayerStateLayers(AcStringArray&,const ACHAR*,bool = false);
    Acad::ErrorStatus getLayerStateMask(const ACHAR*,LayerStateMask&);
    Acad::ErrorStatus getLayerStateNames(AcStringArray&,bool = true,bool = true);
    bool hasLayerState(const ACHAR*);
    Acad::ErrorStatus importLayerState(const ACHAR*);
    Acad::ErrorStatus importLayerState(const ACHAR*,AcString&);
    Acad::ErrorStatus importLayerStateFromDb(const ACHAR*,AcDbDatabase*);
    bool isDependentLayerState(const ACHAR*);
    bool layerStateHasViewportData(const ACHAR*);
    AcDbObjectId layerStatesDictionaryId(bool = false);
    Acad::ErrorStatus removeLayerStateLayers(const ACHAR*,const AcStringArray&);
    bool removeReactor(AcDbLayerStateManagerReactor*);
    Acad::ErrorStatus renameLayerState(const ACHAR*,const ACHAR*);
    Acad::ErrorStatus restoreLayerState(const ACHAR*);
    Acad::ErrorStatus restoreLayerState(const ACHAR*,const AcDbObjectId&,int = 0,const LayerStateMask* = NULL);
    Acad::ErrorStatus saveLayerState(const ACHAR*,LayerStateMask);
    Acad::ErrorStatus saveLayerState(const ACHAR*,LayerStateMask,const AcDbObjectId&);
    Acad::ErrorStatus setLayerStateDescription(const ACHAR*,const ACHAR*);
    Acad::ErrorStatus setLayerStateMask(const ACHAR*,LayerStateMask);
};
