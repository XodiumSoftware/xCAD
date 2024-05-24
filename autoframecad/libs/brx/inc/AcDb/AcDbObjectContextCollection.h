// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"
#include "Misc/MiscGlobal.h"
#include "Misc/AcString.h"

class AcDbObject;
class AcDbObjectContext;
class AcDbObjectContextCollectionIterator;

/** _ */
class BRX_EXPORT AcDbObjectContextCollection : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbObjectContextCollection);

    virtual AcString name() const = 0;

    virtual Acad::ErrorStatus addContext(const AcDbObjectContext*) = 0;
    virtual Acad::ErrorStatus removeContext(const AcString&) = 0;

    virtual bool hasContext(const AcString&) const = 0;
    virtual AcDbObjectContext* getContext(const AcString&) const = 0;

    virtual Acad::ErrorStatus  setCurrentContext(const AcDbObjectContext*) = 0;
    virtual AcDbObjectContext* currentContext(const AcDbObject*) const = 0;

    virtual bool locked() const = 0;
    virtual Acad::ErrorStatus unlockContext() = 0;
    virtual Acad::ErrorStatus lockContext(const AcDbObjectContext*) = 0;

    virtual AcDbObjectContextCollectionIterator* newIterator() const = 0;
};
