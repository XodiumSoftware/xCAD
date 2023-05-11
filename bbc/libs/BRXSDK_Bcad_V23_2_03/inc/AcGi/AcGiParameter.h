// Copyright (C) Menhirs NV. All rights reserved.
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
