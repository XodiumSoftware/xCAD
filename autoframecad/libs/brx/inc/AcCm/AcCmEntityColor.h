// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcCmEntityColor
{
public:
    enum ACIcolorMethod
    {
        kACIfrozenLayer = -32700,
        kACIminimum = -255,
        kACIclear = 0,
        kACIbyBlock = 0,
        kACIstandard = 7,
        kACIforeground = 7,
        kACImaximum = 255,
        kACIbyLayer = 256,
        kACInone = 257
    };

    enum Color
    {
        kRed = 0,
        kGreen,
        kBlue
    };

    enum ColorMethod
    {
        kByLayer = 192,
        kByBlock,
        kByColor,
        kByACI,
        kByPen,
        kForeground,
        kLayerOff,
        kLayerFrozen,
        kNone
    };

    union RGBM
    {
        Adesk::Int16 indirect;
        Adesk::UInt32 whole;
        struct
        {
            Adesk::UInt8 blue;
            Adesk::UInt8 green;
            Adesk::UInt8 red;
            Adesk::UInt8 colorMethod;
        };
    };

    static const Adesk::UInt8 mLUT[256][3];

    static Acad::ErrorStatus setBlue(RGBM*,const Adesk::UInt8);
    static Acad::ErrorStatus setColor(RGBM*,const Adesk::UInt32);
    static Acad::ErrorStatus setColorIndex(RGBM*,const Adesk::Int16);
    static Acad::ErrorStatus setColorMethod(RGBM*,const ColorMethod);
    static Acad::ErrorStatus setGreen(RGBM*,const Adesk::UInt8);
    static Acad::ErrorStatus setLayerIndex(RGBM*,const Adesk::Int16);
    static Acad::ErrorStatus setPenIndex(RGBM*,const Adesk::UInt16);
    static Acad::ErrorStatus setRed(RGBM*,const Adesk::UInt8);
    static Acad::ErrorStatus setRGB(RGBM*,const Adesk::UInt8,const Adesk::UInt8,const Adesk::UInt8);
    static Acad::ErrorStatus setTrueColor(RGBM*);
    static Acad::ErrorStatus setTrueColorMethod(RGBM*);
    static Adesk::Int16 colorIndex(const RGBM*);
    static Adesk::Int16 layerIndex(const RGBM*);
    static Adesk::UInt16 penIndex(const RGBM*);
    static Adesk::UInt32 color(const RGBM*);
    static Adesk::UInt32 lookUpRGB(const Adesk::UInt8); //deprecated
    static Adesk::UInt32 trueColor(const RGBM*);
    static Adesk::UInt8 blue(const RGBM*);
    static Adesk::UInt8 green(const RGBM*);
    static Adesk::UInt8 lookUpACI(const Adesk::UInt8,const Adesk::UInt8,const Adesk::UInt8); //deprecated
    static Adesk::UInt8 red(const RGBM*);
    static Adesk::UInt8 trueColorMethod(const Adesk::Int16);
    static bool isByACI(const RGBM*);
    static bool isByBlock(const RGBM*);
    static bool isByColor(const RGBM*);
    static bool isByLayer(const RGBM*);
    static bool isByPen(const RGBM*);
    static bool isForeground(const RGBM*);
    static bool isLayerFrozen(const RGBM*);
    static bool isLayerOff(const RGBM*);
    static bool isNone(const RGBM*);
    static ColorMethod colorMethod(const RGBM*);

    //ObjectArx 2021
    static AcCmEntityColor None();
    static AcCmEntityColor ByBlock();
    static AcCmEntityColor ByLayer();
    static AcCmEntityColor Foreground();
    static AcCmEntityColor white();
    static AcCmEntityColor black();

protected:
    RGBM mRGBM;

    Acad::ErrorStatus setIndirect(const Adesk::Int16);
    Adesk::Int16 indirect() const;

public:
    AcCmEntityColor();
    AcCmEntityColor(const Adesk::UInt8,const Adesk::UInt8,const Adesk::UInt8);
    AcCmEntityColor(const ColorMethod); //deprecated
    AcCmEntityColor(const AcCmEntityColor&);

    Acad::ErrorStatus setBlue(const Adesk::UInt8); //deprecated
    Acad::ErrorStatus setColor(const Adesk::UInt32); //deprecated
    Acad::ErrorStatus setColorIndex(const Adesk::Int16);
    Acad::ErrorStatus setColorMethod(const ColorMethod); //deprecated
    Acad::ErrorStatus setGreen(const Adesk::UInt8); //deprecated
    Acad::ErrorStatus setLayerIndex(const Adesk::Int16);
    Acad::ErrorStatus setPenIndex(const Adesk::UInt16);
    Acad::ErrorStatus setRed(const Adesk::UInt8); //deprecated
    Acad::ErrorStatus setRGB(const Adesk::UInt8,const Adesk::UInt8,const Adesk::UInt8);
    Acad::ErrorStatus setTrueColor(); //deprecated
    Acad::ErrorStatus setTrueColorMethod(); //deprecated
    Adesk::Int16 colorIndex() const;
    Adesk::Int16 layerIndex() const;
    Adesk::UInt16 penIndex() const;
    Adesk::UInt32 color() const; //deprecated
    Adesk::UInt32 trueColor() const; //deprecated
    Adesk::UInt8 blue() const;
    Adesk::UInt8 green() const;
    Adesk::UInt8 red() const;
    Adesk::UInt8 trueColorMethod() const; //deprecated
    bool isByACI() const;
    bool isByBlock() const;
    bool isByColor() const;
    bool isByLayer() const;
    bool isByPen() const;
    bool isForeground() const;
    bool isLayerFrozen() const;
    bool isLayerFrozenOrOff() const;
    bool isLayerOff() const;
    bool isNone() const;
    ColorMethod colorMethod() const;

    AcCmEntityColor& operator=(const AcCmEntityColor&);
    bool operator!=(const AcCmEntityColor&) const;
    bool operator==(const AcCmEntityColor&) const;

    //ObjectArx 2021

    void setNone();
    void setByBlock();
    void setForeground();
    void setByLayer();
    void setLayerOff();

    Acad::ErrorStatus setCOLORREF(Adesk::ColorRef);
    Adesk::ColorRef getCOLORREF() const;

    Acad::ErrorStatus setRGB(Adesk::RGBQuad);
    Adesk::RGBQuad getRGB() const;

    Acad::ErrorStatus setRGBM(Adesk::UInt32);
    Adesk::UInt32 getRGBM() const;

    bool canResolveRGB() const;

    AcCmEntityColor makeRGB(Adesk::ColorRef = 0) const;
    AcCmEntityColor forceRGB(Adesk::ColorRef = 0) const;
    AcCmEntityColor makeTrueColor() const;

};
