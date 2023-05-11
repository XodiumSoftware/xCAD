// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbDeepCloneFiler.h"

/** _ */
class BRX_IMPORTEXPORT AcDbWblockCloneFiler: public AcDbDeepCloneFiler
{
public:
    ACRX_DECLARE_MEMBERS(AcDbWblockCloneFiler);

    AcDbWblockCloneFiler();

    virtual AcDb::FilerType filerType() const;
    virtual bool getNextHardObject(AcDbObjectId&);
    virtual bool moreHardObjects() const;
    virtual bool usesReferences() const;
};
