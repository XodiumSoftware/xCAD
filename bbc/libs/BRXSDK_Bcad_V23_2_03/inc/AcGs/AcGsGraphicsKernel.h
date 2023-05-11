// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiGraphicsKernel.h"
#include "AcGs/AcGsModel.h"

class AcGsKernelDescriptor;
class AcGsModelReactor;


/** _ */
class BRX_IMPORTEXPORT AcGsGraphicsKernel : public AcGiGraphicsKernel
{
public:
    AcGsGraphicsKernel();
    virtual ~AcGsGraphicsKernel();

    void addRef();
    bool delRef();

    virtual void addModelReactor(AcGsModel*, AcGsModelReactor*) = 0;
    virtual void addReactor(AcGsReactor*) = 0;
    virtual AcGsDevice* createDevice(AcGsWindowingSystemID, GS::DeviceType = GS::kScreenDevice) = 0;
    virtual AcGsModel* createModel(AcGsModel::RenderType, LONG_PTR databaseId, AcGsGetInterfaceFunc, AcGsReleaseInterfaceFunc) = 0;
    virtual AcGsDevice* createOffScreenDevice() = 0;
    virtual AcGsView* createView(const AcGsClientViewInfo* = NULL, bool bEnableLayerVisibilityPerView = false) = 0;
    virtual void deleteDevice(AcGsDevice*) = 0;
    virtual void deleteModel(AcGsModel*) = 0;
    virtual void deleteView(AcGsView* view) = 0;
    virtual AcGsConfig* getConfig() const = 0;
    virtual bool isCompatibleWith(const AcGsKernelDescriptor&) const = 0;
    virtual void removeModelReactor(AcGsModel*, AcGsModelReactor*) = 0;
    virtual void removeReactor(AcGsReactor*) = 0;

private:
    long m_refs;
};
