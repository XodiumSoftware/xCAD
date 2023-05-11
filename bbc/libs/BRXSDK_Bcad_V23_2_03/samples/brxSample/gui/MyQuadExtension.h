// Copyright (C) Menhirs NV. All rights reserved.
//
// This is an example how to use the C++ Quad Extension API,
// a BricsCAD specific interface

#pragma once

#if (__BRXTARGET >= 17) // only available with BRX >= V17
#include "BrxSpecific/AcEdQuad.h"

class MyAcEdQuadReactor : public AcEdQuadReactor
{
public:
    MyAcEdQuadReactor() {};
    virtual ~MyAcEdQuadReactor() {};

private:
    bool collectEntities(AcDbFullSubentPathArray& arrEnts, const AcSelectionData& data,
                         const AcRxClass* entClass, const AcSelectionData::SelectedType etype,
                         bool allowDerived = true);

public:
    // The GUID has to be a globally unique identifier (use VS201x->Tools->CreateGUID, "guidgen.exe")
    // and will be used to internally identify the reactor across sessions, releases and
    // different third party applications, so it should always be the same for this reactor. 
    // Therefore, once a reactor is published by a developer, its GUID should NEVER be changed.
    // Note : any string format from "CreateGUID" / "guidgen.exe" is accepted, suggested format
    //        is like "C2160591-FC06-4A74-A9B8-2E28635279BA" (not brackets)
    virtual const ACHAR* GUID();

    // The display name will be shown to users in the UI for identifying/enabling/disabling/
    // prioritising your reactor.
    virtual const ACHAR* displayName();

    // This function is called whenever BricsCAD needs to know ALL the commands supported by
    // your reactor during, but not limited to loading of your module, adding your reactor
    // to the AcEdQuadReactorManager, displaying the CUI dialog. Your implementation of this
    // interface is expected to call AcEdQuadItemRegistry::append() for each QuadItem your
    // reactor supports / requires. 
    // If a QuadItem has not been registered, AcEdQuadItems::append will not append that
    // QuadItem to the Quad when its shown.
    virtual bool registerQuadItems(AcEdQuadItemRegistry& quadItemRegistry);

    // Implement appendQuadItems to append QuadItems to the Quad. This function will be called
    // when the Quad is about to be shown.
    // Only those QuadItems that have been registered will be successfully appended.
    // Several reactors may be registered, but only those which are active (as per settings)
    // will append their items to the Quad.
    // *
    // This function is called when a Quad is to be shown for a selection.
    // AcEdQuadSelection can be queried further for hovered and pickfirst selection data,
    // to make intelligent decisions of relevant QuadItems to be added to the Quad.
    virtual bool appendQuadItems(const AcEdQuadSelection& quadSelection, AcEdQuadItems& quadItems);

    // This function is called when the no-selection Quad is to be shown.
    // Add selection-independent items in this function.
    virtual bool appendQuadItems(AcEdQuadItems& quadItems);
};

#endif // BRX_APP

bool registerMyQuadExtension();    // dummy implemented for ARX build + BRX < V17
bool unregisterMyQuadExtension();  // dummy implemented for ARX build + BRX < V17
