// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcEd/AcEdCommand.h"

/** _ */
class BRX_IMPORTEXPORT AcEdCommandIterator: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcEdCommandIterator);

    virtual bool done() const = 0;
    virtual bool next() = 0;
    virtual const AcEdCommand* command() const = 0;
    virtual const ACHAR* commandGroup() const = 0;
};