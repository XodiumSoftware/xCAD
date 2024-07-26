// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
