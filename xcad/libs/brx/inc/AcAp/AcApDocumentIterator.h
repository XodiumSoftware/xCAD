// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcAp/AcApDocument.h"

/** _ */
class BRX_IMPORTEXPORT AcApDocumentIterator: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcApDocumentIterator);

    virtual AcApDocument* document() = 0;
    virtual bool done() const = 0;
    virtual void step() = 0;
};