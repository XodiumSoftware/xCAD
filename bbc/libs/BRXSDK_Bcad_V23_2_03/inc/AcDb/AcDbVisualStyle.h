// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"
#include "AcGi/AcGiVisualStyle.h"

/** _ */
class BRX_EXPORT AcDbVisualStyle: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbVisualStyle);

    AcDbVisualStyle();
    virtual ~AcDbVisualStyle();

    virtual Acad::ErrorStatus copyFrom(const AcGiVisualStyle*);
    virtual Acad::ErrorStatus copyTo(AcGiVisualStyle*) const;
    virtual Acad::ErrorStatus decomposeForSave(AcDb::AcDbDwgVersion,AcDbObject*&,AcDbObjectId&,Adesk::Boolean&);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual AcGiDrawable* drawable();
    virtual AcGsNode* gsNode() const;
    virtual bool isInternalUseOnly() const;
    virtual void setGsNode(AcGsNode*);
    virtual void setInternalUseOnly(bool);

    Acad::ErrorStatus setDescription(const ACHAR*);
    Acad::ErrorStatus setDisplayStyle(const AcGiDisplayStyle&);
    Acad::ErrorStatus setType(AcGiVisualStyle::Type);
    Acad::ErrorStatus setTrait(AcGiVisualStyleProperties::Property, const AcGiVariant*, AcGiVisualStyleOperations::Operation = AcGiVisualStyleOperations::kSet);
    Acad::ErrorStatus setTrait(AcGiVisualStyleProperties::Property, int, AcGiVisualStyleOperations::Operation = AcGiVisualStyleOperations::kSet);
    Acad::ErrorStatus setTrait(AcGiVisualStyleProperties::Property, bool, AcGiVisualStyleOperations::Operation = AcGiVisualStyleOperations::kSet);
    Acad::ErrorStatus setTrait(AcGiVisualStyleProperties::Property, double, AcGiVisualStyleOperations::Operation = AcGiVisualStyleOperations::kSet);
    Acad::ErrorStatus setTrait(AcGiVisualStyleProperties::Property, double, double, double, AcGiVisualStyleOperations::Operation = AcGiVisualStyleOperations::kSet);
    Acad::ErrorStatus setTrait(AcGiVisualStyleProperties::Property, const AcCmColor*, AcGiVisualStyleOperations::Operation = AcGiVisualStyleOperations::kSet);
    AcGiVariant trait(AcGiVisualStyleProperties::Property, AcGiVisualStyleOperations::Operation* = NULL) const;
    Acad::ErrorStatus setTraitFlag(AcGiVisualStyleProperties::Property, Adesk::UInt32, bool = true);
    bool traitFlag(AcGiVisualStyleProperties::Property, Adesk::UInt32) const;
    AcGiVisualStyle::Type type() const;
    const AcGiDisplayStyle& displayStyle() const;
    const AcGiEdgeStyle& edgeStyle() const;
    const AcGiFaceStyle& faceStyle() const;
    const ACHAR* description() const;
    void setEdgeStyle(const AcGiEdgeStyle&);
    void setFaceStyle(const AcGiFaceStyle&);

    Acad::ErrorStatus name(AcString&) const;

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
};
