// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"
#include "Misc/MiscGlobal.h"
#include "Misc/AcString.h"

class AcDbObject;
class AcDbObjectContext;

/** _ */
class BRX_EXPORT AcDbObjectContextInterface : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbObjectContextInterface);

public:
    virtual Acad::ErrorStatus addContext(AcDbObject*, const AcDbObjectContext&) const = 0;
    virtual Acad::ErrorStatus removeContext(AcDbObject*, const AcDbObjectContext&) const = 0;

    virtual bool hasContext(const AcDbObject*, const AcDbObjectContext&) const = 0;
    virtual bool supportsCollection(const AcDbObject*, const AcString&) const = 0;
};

BRX_EXPORT const AcString& acdbAnnotationScaleCollectionName();
#define ACDB_ANNOTATIONSCALES_COLLECTION acdbAnnotationScaleCollectionName()
