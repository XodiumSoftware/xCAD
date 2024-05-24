// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class AcRxProtocolReactorList: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxProtocolReactorList);

    virtual Acad::ErrorStatus addReactor(AcRxProtocolReactor*) = 0;
    virtual AcRxClass* reactorClass() const = 0;
    virtual AcRxProtocolReactorIterator* newIterator() const = 0;
    virtual void removeReactor(AcRxProtocolReactor*) = 0;
};