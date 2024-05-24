// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"
#include "Misc/MiscGlobal.h"
#include "Misc/AcString.h"


/** _ */
class BRX_EXPORT AcDbObjectContext : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbObjectContext);

public:
    AcDbObjectContext();
    virtual ~AcDbObjectContext();

public:
    virtual AcString collectionName() const = 0;
    virtual Adesk::LongPtr uniqueIdentifier() const = 0;

    virtual Acad::ErrorStatus setName(const AcString&) = 0;
    virtual Acad::ErrorStatus getName(AcString&) const = 0;
};
