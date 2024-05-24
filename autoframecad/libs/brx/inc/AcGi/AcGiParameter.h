// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxCopyOnWriteObject.h"

class AcGiParameterImp;

/** _ */
class BRX_IMPORTEXPORT AcGiParameter: public AcRxCopyOnWriteObject
{
    friend class AcGiParameterImp;
public:
    ACRX_DECLARE_MEMBERS_READWRITE(AcGiParameter, AcGiParameterImp);

    AcGiParameter(AcGiParameterImp* imp);
    AcGiParameter(const AcGiParameter& rhs);
    const AcGiParameter& operator=(const AcGiParameter& rhs);
};
