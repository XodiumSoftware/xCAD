// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
