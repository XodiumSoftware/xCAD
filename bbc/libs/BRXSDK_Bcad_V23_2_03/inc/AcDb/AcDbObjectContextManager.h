// Copyright (C) Menhirs NV. All rights reserved.
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
