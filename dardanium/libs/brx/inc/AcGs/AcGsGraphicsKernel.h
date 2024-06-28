// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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

    virtual void associate(Adesk::LongPtr, AcGsModel*, AcGsModel::RenderType) = 0;
    virtual AcGsModel* find(Adesk::LongPtr, AcGsModel::RenderType) = 0;

private:
    long m_refs;
};
