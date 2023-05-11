// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxService.h"

/** _ */
class BRX_IMPORTEXPORT AcRxKernel: public AcRxService
{
public:
    ACRX_DECLARE_MEMBERS(AcRxKernel);

    AcRxKernel();
    virtual ~AcRxKernel();

    virtual AcRxDictionary* newAcRxDictionary(Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kFalse) = 0;
    virtual AcRxDictionary* newAcRxDictionary(const AcRxClass*) = 0;
    virtual AcRxDictionary* newAcRxDictionary(unsigned long,Adesk::Boolean,Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kFalse) = 0;
};

#define acrxKernel AcRxKernel::cast(AcRxDictionary::cast(acrxSysRegistry()->at(ACRX_SERVICE_DICTIONARY))->at(ACRX_KERNEL_SERVICES))
