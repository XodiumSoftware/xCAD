// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcPubl/AcPublishUIReactorInfo.h"

/** _ */
class BRX_IMPORTEXPORT AcPublishUIReactor: public AcRxObject
{
protected:
    AcPublishUIReactor() {};
public:
    virtual ~AcPublishUIReactor() {};

    virtual void OnInitPublishOptionsDialog(IUnknown**,AcPublishUIReactorInfo*) {};

    virtual void PersistenceRegistryForExportOptionsDialog(const ACHAR*, bool = true) {};
    virtual void PersistenceRegistryForAutoPublishDialog(const ACHAR*, bool = true) {};
    virtual void OnInitAutoPublishSettingsDialog(IUnknown**, AcPublishUIReactorInfo*) {};
    virtual void OnInitExportOptionsDialog(IUnknown**, AcPublishUIReactorInfo*) {};
};