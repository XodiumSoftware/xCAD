// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectId.h"

/** _ */
class BRX_IMPORTEXPORT AcDbIndexUpdateData
{
public:
    enum UpdateFlags
    {
        kModified = 1,
        kDeleted = 2,
        kProcessed = 4,
        kUnknownKey = 8
    };

private:
    AcDbIndexUpdateData();
    AcDbIndexUpdateData(const AcDbIndexUpdateData&);
    ~AcDbIndexUpdateData();

public:
    Acad::ErrorStatus addId(AcDbObjectId);
    Acad::ErrorStatus getFlagsAndData(AcDbObjectId,Adesk::UInt8&,Adesk::UInt32&) const;
    Acad::ErrorStatus getIdData(AcDbObjectId,Adesk::UInt32&) const;
    Acad::ErrorStatus getIdFlags(AcDbObjectId,Adesk::UInt8&) const;
    Acad::ErrorStatus setIdData(AcDbObjectId,Adesk::UInt32);
    Acad::ErrorStatus setIdFlags(AcDbObjectId,Adesk::UInt8);
};
