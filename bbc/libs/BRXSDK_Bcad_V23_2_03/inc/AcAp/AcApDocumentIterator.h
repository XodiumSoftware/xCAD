// Copyright (C) Menhirs NV. All rights reserved.
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