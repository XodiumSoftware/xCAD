// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGs/AcGsClientViewInfo.h"
#include "AcGs/AcGsModel.h"

class AcGsModelReactor;

/** _ */
class BRX_IMPORTEXPORT AcGsClassFactory
{
public:
    virtual ~AcGsClassFactory() {}

    virtual AcGsConfig* getConfig() = 0;
    virtual AcGsDevice* createDevice(AcGsWindowingSystemID,GS::DeviceType = GS::kScreenDevice) = 0;
    virtual AcGsDevice* createOffScreenDevice() = 0;
    virtual AcGsModel* createModel(AcGsModel::RenderType,LONG_PTR,AcGsGetInterfaceFunc,AcGsReleaseInterfaceFunc) = 0;
    virtual AcGsView* createView(const AcGsClientViewInfo* = NULL,bool = false) = 0;
    virtual void addReactor(AcGsReactor*) = 0;
    virtual void deleteDevice(AcGsDevice*) = 0;
    virtual void deleteModel(AcGsModel*) = 0;
    virtual void deleteView(AcGsView*) = 0;
    virtual void releaseConfig(AcGsConfig*) = 0;
    virtual void removeReactor(AcGsReactor*) = 0;
    virtual void addModelReactor(AcGsModel*,AcGsModelReactor*) = 0;
    virtual void removeModelReactor(AcGsModel*,AcGsModelReactor*) = 0;
};
