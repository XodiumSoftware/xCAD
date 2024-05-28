// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
