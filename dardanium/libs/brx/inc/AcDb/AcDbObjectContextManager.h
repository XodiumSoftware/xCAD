// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"
#include "Misc/MiscGlobal.h"
#include "Misc/AcString.h"

class AcDbObjectContextCollection;

/** _ */
class BRX_EXPORT AcDbObjectContextManager : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbObjectContextManager);

public:
    AcDbObjectContextManager();  
    virtual ~AcDbObjectContextManager();

    AcDbObjectContextCollection* const contextCollection(const AcString&) const;

    Acad::ErrorStatus registerContextCollection(const AcString&, AcDbObjectContextCollection*);
    Acad::ErrorStatus unregisterContextCollection(const AcString&);
};
