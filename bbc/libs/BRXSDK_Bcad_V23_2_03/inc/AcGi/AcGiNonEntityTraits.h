// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmEntityColor.h"
#include "AcGi/AcGiDrawableTraits.h"

/** _ */
class BRX_IMPORTEXPORT AcGiNonEntityTraits : public AcGiDrawableTraits
{
public:
    ACRX_DECLARE_MEMBERS(AcGiNonEntityTraits);

    virtual AcCmEntityColor trueColor() const;
    virtual AcDb::LineWeight lineWeight() const;
    virtual AcDbObjectId layerId() const;
    virtual AcDbObjectId lineTypeId() const;
    virtual AcDbObjectId materialId() const;
    virtual AcGiFillType fillType() const;
    virtual Adesk::UInt16 color() const;
    virtual bool selectionGeom() const;
    virtual double lineTypeScale() const;
    virtual double thickness() const;
    virtual void addLight(const AcDbObjectId&);
    virtual void setColor(const Adesk::UInt16);
    virtual void setFillType(const AcGiFillType);
    virtual void setLayer(const AcDbObjectId);
    virtual void setLineType(const AcDbObjectId);
    virtual void setLineTypeScale(double);
    virtual void setLineWeight(const AcDb::LineWeight);
    virtual void setMaterial(const AcDbObjectId);
    virtual void setSelectionGeom(bool);
    virtual void setSelectionMarker(const Adesk::LongPtr);
    virtual void setThickness(double);
    virtual void setTrueColor(const AcCmEntityColor&);
    virtual void setupForEntity(AcDbEntity*);

    virtual AcCmTransparency transparency() const;
    virtual void setTransparency(const AcCmTransparency&);
};
