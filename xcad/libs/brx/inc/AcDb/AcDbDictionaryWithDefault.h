// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
