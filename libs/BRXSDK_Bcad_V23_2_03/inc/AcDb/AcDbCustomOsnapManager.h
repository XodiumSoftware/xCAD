// Copyright (C) Menhirs NV. All rights reserved.
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
