// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbDictionary.h"

/** _ */
class BRX_EXPORT AcDbDictionaryWithDefault: public AcDbDictionary
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDictionaryWithDefault);

    AcDbDictionaryWithDefault();
    virtual ~AcDbDictionaryWithDefault();

    virtual Acad::ErrorStatus getObjectBirthVersion(AcDb::AcDbDwgVersion&,AcDb::MaintenanceReleaseVersion&);

    Acad::ErrorStatus setDefaultId(const AcDbObjectId&);
    AcDbObjectId defaultId() const;
};
