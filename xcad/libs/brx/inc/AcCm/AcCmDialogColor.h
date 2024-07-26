// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcCm/AcCmColorBase.h"

/** _ */
class BRX_IMPORTEXPORT AcCmDialogColor: public AcCmColorBase
{
public:
    AcCmDialogColor();
    AcCmDialogColor(const AcCmColorBase&);
    AcCmDialogColor(const AcCmDialogColor&);
    virtual ~AcCmDialogColor();

    virtual Acad::ErrorStatus setBlue(Adesk::UInt8);
    virtual Acad::ErrorStatus setColor(Adesk::UInt32);
    virtual Acad::ErrorStatus setColorIndex(Adesk::UInt16);
    virtual Acad::ErrorStatus setColorMethod(AcCmEntityColor::ColorMethod);
    virtual Acad::ErrorStatus setGreen(Adesk::UInt8);
    virtual Acad::ErrorStatus setNames(const ACHAR*,const ACHAR* = NULL);
    virtual Acad::ErrorStatus setPenIndex (Adesk::UInt16);
    virtual Acad::ErrorStatus setRed(Adesk::UInt8);
    virtual Acad::ErrorStatus setRGB(Adesk::UInt8,Adesk::UInt8,Adesk::UInt8);
    virtual AcCmEntityColor::ColorMethod colorMethod() const;
    virtual Adesk::UInt16 colorIndex() const;
    virtual Adesk::UInt16 penIndex() const;
    virtual Adesk::UInt32 color() const;
    virtual Adesk::UInt8 blue() const;
    virtual Adesk::UInt8 green() const;
    virtual Adesk::UInt8 red() const;
    virtual bool hasBookName() const;
    virtual bool hasColorName() const;
    virtual bool isByACI() const;
    virtual bool isByBlock() const;
    virtual bool isByColor() const;
    virtual bool isByLayer() const;
    virtual bool isByPen () const;
    virtual bool isForeground() const;
    virtual const ACHAR* bookName() const;
    virtual const ACHAR* colorName() const;
    virtual const ACHAR* colorNameForDisplay();

    AcCmDialogColor& operator=(const AcCmColorBase&);
    AcCmDialogColor& operator=(const AcCmDialogColor&);
    bool operator!=(const AcCmColorBase&) const;
    bool operator!=(const AcCmDialogColor&) const;
    bool operator==(const AcCmColorBase&) const;
    bool operator==(const AcCmDialogColor&) const;
};
