// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGs/AcGsView.h"

/** _ */
class BRX_IMPORTEXPORT AcGsReactor
{
public:
    enum ViewUpdateFlags
    {
        kCameraChanged = 1
    };

public:
    AcGsReactor() {}
    virtual ~AcGsReactor() {}

public:
    virtual void configWasModified() {} //V16 compatibility
    virtual void gsToBeUnloaded(class AcGsClassFactory*) {} //V16 compatibility
    virtual void viewToBeDestroyed(AcGsView*) {}
    virtual void viewWasCreated(AcGsView*) {}
    virtual void viewToBeUpdated(AcGsView*, int) {}
    virtual void viewWasUpdated(AcGsView*, int) {}

    //V17
    virtual void gsToBeUnloaded(AcGsGraphicsKernel*) {}
    virtual void viewInteractivityToBeChanged(const AcGsView*, bool) {}
    virtual void viewInteractivityWasChanged(const AcGsView*, bool) {}
};
