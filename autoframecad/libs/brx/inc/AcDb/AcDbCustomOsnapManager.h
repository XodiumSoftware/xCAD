// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

class AcDbCustomOsnapMode;

/** _ */
class BRX_IMPORTEXPORT AcDbCustomOsnapManager
{
public:
    virtual Acad::ErrorStatus activateOsnapMode(const ACHAR*) = 0;
    virtual Acad::ErrorStatus addCustomOsnapMode(AcDbCustomOsnapMode*) = 0;
    virtual Acad::ErrorStatus deactivateOsnapMode(const ACHAR*) = 0;
    virtual Acad::ErrorStatus removeCustomOsnapMode(AcDbCustomOsnapMode*) = 0;
    virtual Adesk::Boolean modeIsActive(const ACHAR*) = 0;
    virtual int osnapGlyphSize() const = 0;
};
