// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmDialogColor.h"
#include "AcDb/AcDbXObject.h"

/** _ */
class AcCmComplexColor: public AcDbXObject
{
public:
    ACRX_DECLARE_MEMBERS(AcCmComplexColor);

    virtual Acad::ErrorStatus audit(AcDbAuditInfo*);
    virtual Acad::ErrorStatus copyFrom(const AcRxObject*);
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus getDescription(ACHAR*&) const;
    virtual Acad::ErrorStatus getExplanation(ACHAR*&) const;
    virtual Acad::ErrorStatus setBlue(Adesk::UInt8);
    virtual Acad::ErrorStatus setColor(Adesk::UInt32);
    virtual Acad::ErrorStatus setColorIndex(Adesk::UInt16);
    virtual Acad::ErrorStatus setColorMethod(AcCmEntityColor::ColorMethod);
    virtual Acad::ErrorStatus setGreen(Adesk::UInt8);
    virtual Acad::ErrorStatus setPenIndex (Adesk::UInt16);
    virtual Acad::ErrorStatus setRed(Adesk::UInt8);
    virtual Acad::ErrorStatus setRGB(Adesk::UInt8,Adesk::UInt8,Adesk::UInt8);
    virtual AcCmComplexColor* incReference();
    virtual AcCmEntityColor::ColorMethod colorMethod() const;
    virtual Adesk::UInt16 colorIndex() const;
    virtual Adesk::UInt16 penIndex() const;
    virtual Adesk::UInt32 color() const;
    virtual Adesk::UInt8 blue() const;
    virtual Adesk::UInt8 green() const;
    virtual Adesk::UInt8 red() const;
    virtual bool isByACI() const;
    virtual bool isByBlock() const;
    virtual bool isByColor() const;
    virtual bool isByLayer() const;
    virtual bool isByPen() const;
    virtual bool isForeground() const;
    virtual void decReference();
};
