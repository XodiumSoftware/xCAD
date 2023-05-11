// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

class AcGiGlyph;
class AcRxClass;

/** _ */
class BRX_IMPORTEXPORT AcDbCustomOsnapMode
{
public:
    virtual ~AcDbCustomOsnapMode() {}

    virtual AcGiGlyph* glyph() const = 0;
    virtual const ACHAR* globalModeString() const = 0;
    virtual const ACHAR* localModeString() const = 0;
    virtual const ACHAR* tooltipString() const = 0;
    virtual const AcRxClass* entityOsnapClass() const = 0;
};
