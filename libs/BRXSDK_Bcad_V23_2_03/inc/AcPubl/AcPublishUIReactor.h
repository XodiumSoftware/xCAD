// Copyright (C) Menhirs NV. All rights reserved.
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