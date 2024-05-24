// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"
#include "AcRx/AcRxObject.h"

class AcDbEntity;

// abstract base class for all AcDbGeomRef-derived classes

/** _ */
class AcDbGeomRef : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbGeomRef);

    virtual ~AcDbGeomRef()
    {
    };

    virtual bool isEmpty() const = 0;
    virtual bool isValid() const = 0;
    virtual void reset() = 0;

    virtual Acad::ErrorStatus evaluateAndCacheGeometry() = 0;
    virtual AcDbEntity* createEntity() const = 0;
};
