// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbHostApplicationServices.h"

/** _ */
class BRX_IMPORTEXPORT AcDbPasswordedFile
{
protected:
    virtual Acad::ErrorStatus tryPassword(const ACHAR*) = 0;
    virtual const ACHAR* getFullPath() = 0;

public:
    Acad::ErrorStatus open(const ACHAR*,AcDbHostApplicationServices::PasswordOptions);
};
