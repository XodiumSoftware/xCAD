// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcCm/AcCmEntityColor.h"

/** _ */
class BRX_IMPORTEXPORT AcCmColorBase
{
public:
    virtual ~AcCmColorBase() {};

    virtual Acad::ErrorStatus setBlue (Adesk::UInt8) = 0; //deprecated
    virtual Acad::ErrorStatus setColor(Adesk::UInt32) = 0; //deprecated
    virtual Acad::ErrorStatus setColorIndex(Adesk::UInt16) = 0;
    virtual Acad::ErrorStatus setColorMethod(AcCmEntityColor::ColorMethod) = 0; //deprecated
    virtual Acad::ErrorStatus setGreen(Adesk::UInt8) = 0; //deprecated
    virtual Acad::ErrorStatus setNames(const ACHAR*,const ACHAR* = NULL) = 0;
    virtual Acad::ErrorStatus setPenIndex (Adesk::UInt16) = 0;
    virtual Acad::ErrorStatus setRed(Adesk::UInt8) = 0; //deprecated
    virtual Acad::ErrorStatus setRGB(Adesk::UInt8,Adesk::UInt8,Adesk::UInt8) = 0;
    virtual AcCmEntityColor::ColorMethod colorMethod() const = 0;
    virtual Adesk::UInt16 colorIndex() const = 0;
    virtual Adesk::UInt16 penIndex() const = 0;
    virtual Adesk::UInt32 color() const = 0; //deprecated
    virtual Adesk::UInt8 blue() const = 0;
    virtual Adesk::UInt8 green() const = 0;
    virtual Adesk::UInt8 red() const = 0;
    virtual bool hasBookName() const = 0;
    virtual bool hasColorName() const = 0;
    virtual bool isByACI() const = 0;
    virtual bool isByBlock() const = 0;
    virtual bool isByColor() const = 0;
    virtual bool isByLayer() const = 0;
    virtual bool isByPen() const = 0;
    virtual bool isForeground() const = 0;
    virtual const ACHAR* bookName() const = 0;
    virtual const ACHAR* colorName() const = 0;
    virtual const ACHAR* colorNameForDisplay() = 0;

    //ObjectArx 2021
    virtual void setNone() = 0;
    virtual void setByBlock() = 0;
    virtual void setForeground() = 0;
    virtual void setLayerOff() = 0;
    virtual void setByLayer() = 0;

    virtual Acad::ErrorStatus setCOLORREF(Adesk::ColorRef) = 0;
    virtual Adesk::ColorRef getCOLORREF() const = 0;

    virtual Acad::ErrorStatus setRGB(Adesk::RGBQuad) = 0;
    virtual Adesk::RGBQuad getRGB() const = 0;

    virtual Acad::ErrorStatus setRGBM(Adesk::UInt32) = 0;
    virtual Adesk::UInt32 getRGBM() const = 0;
};
