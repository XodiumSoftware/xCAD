// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectContext.h"
#include "Misc/AcHeapOperators.h"
#include "Misc/MiscGlobal.h"
#include "Misc/AcString.h"

class AcRxObject;

/** _ */
class BRX_EXPORT AcDbAnnotationScale : public AcDbObjectContext, public AcHeapOperators
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAnnotationScale);

protected:
    AcDbAnnotationScale(bool);

public:
    AcDbAnnotationScale();
    virtual ~AcDbAnnotationScale();

public:
    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);

    virtual AcString collectionName() const;
    virtual Adesk::LongPtr uniqueIdentifier() const;

    virtual Acad::ErrorStatus getName(AcString&) const;
    virtual Acad::ErrorStatus getPaperUnits(double&) const;
    virtual Acad::ErrorStatus getDrawingUnits(double&) const;
    virtual Acad::ErrorStatus getScale(double&) const;
    virtual Acad::ErrorStatus getIsTemporaryScale(bool&) const;

    virtual Acad::ErrorStatus setName(const AcString&);
    virtual Acad::ErrorStatus setPaperUnits(double);
    virtual Acad::ErrorStatus setDrawingUnits(const double);

    virtual bool matchScaleId(Adesk::LongPtr) const;
};
