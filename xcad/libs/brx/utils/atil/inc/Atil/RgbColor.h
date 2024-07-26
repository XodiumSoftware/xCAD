// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"
#include "Atil/DataModelAttributes.h"


namespace Atil
{;


namespace RgbColorFactors
{
const double kLuminanceRedFactor = 0.299;
const double kLuminanceGreenFactor = 0.587;
const double kLuminanceBlueFactor = 0.114;
} //namespace RgbColorFactors


#pragma pack(push, 1)


class ATIL_IMPORTEXPORT RgbaColor8i //BRX only
{
public:
    union
    {
        struct { Data8 red; Data8 green; Data8 blue; Data8 alpha; } rgba;
        struct { Data8 blue; Data8 green; Data8 red; Data8 alpha; } bgra;
        Data32 packed;
    };

public:
    RgbaColor8i() : packed(0) {}
    RgbaColor8i(Data32 val) : packed(val) {}
    RgbaColor8i(Data8 r, Data8 g, Data8 b) { rgba.red = r; rgba.green = g; rgba.blue = b; rgba.alpha = 0xFF; }
    RgbaColor8i(Data8 val1, Data8 val2, Data8 val3, Data8 a)  { rgba.red = val1; rgba.green = val2; rgba.blue = val3; rgba.alpha = a; }
    const RgbaColor8i& set(Data8 r, Data8 g, Data8 b)
    {
        rgba.red = r;
        rgba.green = g;
        rgba.blue = b;
        rgba.alpha = 0xFF;
        return *this;
    }
    const RgbaColor8i& set(Data8 r, Data8 g, Data8 b, Data8 a, DataModelAttributes::ChannelOrder co = DataModelAttributes::kRedGreenBlueAlpha)
    {
        switch (co)
        {
        case DataModelAttributes::kBlueGreenRedAlpha:
            bgra.red = r;
            bgra.green = g;
            bgra.blue = b;
            bgra.alpha = a;
            break;
        default:
            rgba.red = r;
            rgba.green = g;
            rgba.blue = b;
            rgba.alpha = a;
            break;
        };
        return *this;
    }
    Data8 asGray(DataModelAttributes::ChannelOrder co = DataModelAttributes::kRedGreenBlueAlpha) const;
    const RgbaColor8i& operator=(const RgbaColor8i& rh) { packed = rh.packed; return *this; }
    const RgbaColor8i& operator=(Data32 rh) { packed = rh; return *this; }
    operator Data32() const { return packed; }
    bool operator==(const RgbaColor8i& rh) const { return (packed == rh.packed); }
    bool operator==(Data32 rh) const { return (packed == rh); }
    bool operator!=(const RgbaColor8i& rh) const { return (packed != rh.packed); }
    bool operator!=(Data32 rh) const { return (packed != rh); }
};
typedef RgbaColor8i RgbColor; //for ARX compatibility


class ATIL_IMPORTEXPORT RgbColor8i //BRX only
{
public:
    union
    {
        struct { Data8 red; Data8 green; Data8 blue; } rgb;
        struct { Data8 blue; Data8 green; Data8 red; } bgr;
        Data8 packed[3];
    };

public:
    RgbColor8i() { set(0, 0, 0); }
    RgbColor8i(Data32 val) { packed[0] = (Data8)val; val >>= 8; packed[1] = (Data8)val; val >>= 8; packed[2] = (Data8)val; }
    RgbColor8i(Data8 r, Data8 g, Data8 b) { rgb.red = r; rgb.green = g; rgb.blue = b; }
    RgbColor8i(Data8 val1, Data8 val2, Data8 val3, Data8 a)  { rgb.red = val1; rgb.green = val2; rgb.blue = val3; }
    const RgbColor8i& set(Data8 r, Data8 g, Data8 b)
    {
        rgb.red = r;
        rgb.green = g;
        rgb.blue = b;
        return *this;
    }
    const RgbColor8i& set(Data8 r, Data8 g, Data8 b, DataModelAttributes::ChannelOrder co)
    {
        switch (co)
        {
        case DataModelAttributes::kBlueGreenRedAlpha:
            bgr.red = r;
            bgr.green = g;
            bgr.blue = b;
            break;
        default:
            rgb.red = r;
            rgb.green = g;
            rgb.blue = b;
            break;
        };
        return *this;
    }
    Data8 asGray(DataModelAttributes::ChannelOrder co = DataModelAttributes::kRedGreenBlueAlpha) const;
    const RgbColor8i& operator=(const RgbColor8i& rh) { rgb.red = rh.rgb.red; rgb.green = rh.rgb.green; rgb.blue = rh.rgb.blue; return *this; }
    const RgbColor8i& operator=(Data32 rh)
    {
        packed[0] = (Data8)rh;
        rh >>= 8;
        packed[1] = (Data8)rh;
        rh >>= 8;
        packed[2] = (Data8)rh;
        return *this;
    }
    operator Data32() const { return (packed[0] | (packed[1] << 8) | (packed[2] << 16) | 0xFF000000); }
    bool operator==(const RgbColor8i& rh) const
    {
        return (packed[0] == rh.packed[0] && packed[1] == rh.packed[1] && packed[2] == rh.packed[2]);
    }
    bool operator==(Data32 rh) const { return ((Data32)*this == rh); }
    bool operator!=(const RgbColor8i& rh) const { return !operator==(rh); }
    bool operator!=(Data32 rh) const { return !operator==(rh); }
};


struct ATIL_IMPORTEXPORT RgbColor5b
{
    enum Fields
    {
        k5551 = 0,
        k565 = 1,
    };
    Data16 packed;

    RgbColor5b();
    RgbColor5b(Data16 val);
    RgbColor5b(Data8 r, Data8 g, Data8 b);
    RgbColor5b(Data8 val1, Data8 val2, Data8 val3, Data8 a, DataModelAttributes::BitFields f = DataModelAttributes::k5551);
    const RgbColor5b& set(Data8 r, Data8 g, Data8 b);
    const RgbColor5b& set(Data8 r, Data8 g, Data8 b, Data8 a, DataModelAttributes::BitFields f = DataModelAttributes::k5551, DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha);
    void getChannelData(Data8& r, Data8& g, Data8& b, Data8& a, DataModelAttributes::BitFields f, DataModelAttributes::ChannelOrder co) const;
    RgbColor asRgbColor(DataModelAttributes::BitFields f, DataModelAttributes::ChannelOrder co) const;
    RgbColor asBgrColor(DataModelAttributes::BitFields f, DataModelAttributes::ChannelOrder co) const;
    Data8 asGray(DataModelAttributes::BitFields f, DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha) const;
    const RgbColor5b& operator=(const RgbColor5b& rh);
    const RgbColor5b& operator=(Data16 rh);
    operator Data16() const;
    bool operator==(const RgbColor5b& rh) const;
    bool operator==(Data16 rh) const;
    bool operator!=(const RgbColor5b& rh) const;
    bool operator!=(Data16 rh) const;
};


struct ATIL_IMPORTEXPORT RgbColor10
{
    Data32 packed;

    RgbColor10();
    RgbColor10(Data32 val);
    RgbColor10(Data16 r, Data16 g, Data16 b);
    RgbColor10(Data16 val1, Data16 val2, Data16 val3, Data16 a);
    const RgbColor10& set(Data16 r, Data16 g, Data16 b);
    const RgbColor10& set(Data16 r, Data16 g, Data16 b, Data16 a, DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha);
    void getChannelData(Data16& r, Data16& g, Data16& b, Data16& a, DataModelAttributes::ChannelOrder co) const;
    RgbColor asRgbColor(DataModelAttributes::ChannelOrder co) const;
    RgbColor asBgrColor(DataModelAttributes::ChannelOrder co) const;
    Data16 asGray(DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha) const;
    const RgbColor10& operator=(const RgbColor10& rh);
    const RgbColor10& operator=(Data32 rh);
    operator Data32() const;
    bool operator==(const RgbColor10& rh) const;
    bool operator==(Data32 rh) const;
    bool operator!=(const RgbColor10& rh) const;
    bool operator!=(Data32 rh) const;
};


struct ATIL_IMPORTEXPORT RgbColor16i
{
    union
    {
        struct { Data16 red; Data16 green; Data16 blue; Data16 alpha; } rgba;
        struct { Data16 blue; Data16 green; Data16 red; Data16 alpha; } bgra;
        Data64 packed;
    };

    RgbColor16i();
    RgbColor16i(Data64 val);
    RgbColor16i(Data16 r, Data16 g, Data16 b);
    RgbColor16i(Data16 val1, Data16 val2, Data16 val3, Data16 a);
    const RgbColor16i& set(Data16 r, Data16 g, Data16 b);
    const RgbColor16i& set(Data16 r, Data16 g, Data16 b, Data16 a, DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha);
    RgbColor asRgbColor(DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha) const;
    RgbColor asBgrColor(DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha) const;
    Data16 asGray(DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha) const;
    const RgbColor16i& operator=(const RgbColor16i& rh);
    const RgbColor16i& operator=(Data64 rh);
    operator Data64() const;
    bool operator==(const RgbColor16i& rh) const;
    bool operator==(Data64 rh) const;
    bool operator!=(const RgbColor16i& rh) const;
    bool operator!=(Data64 rh) const;
};


typedef unsigned short half; //TODO: #include "Half.h"
struct ATIL_IMPORTEXPORT RgbColor16f
{
    typedef struct { half blue; half green; half red; half alpha; } Channels;
    union
    {
        struct { Data16 blue; Data16 green; Data16 red; Data16 alpha; } bgra;
        Data64 packed;
    };

    RgbColor16f();
    RgbColor16f(Data64 val);
    RgbColor16f(half r, half g, half b);
    RgbColor16f(half val1, half val2, half val3, half a);
    const RgbColor16f& set(half r, half g, half b);
    const RgbColor16f& set(half r, half g, half b, half a, DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha);
    RgbColor asRgbColor(DataModelAttributes::ChannelOrder co) const;
    RgbColor asBgrColor(DataModelAttributes::ChannelOrder co) const;
    half asGray(DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha) const;
    Channels getChannelData() const;
    const RgbColor16f& operator=(const RgbColor16f& rh);
    const RgbColor16f& operator=(Data64 rh);
    operator Data64() const;
    bool operator==(const RgbColor16f& rh) const;
    bool operator==(Data64 rh) const;
    bool operator!=(const RgbColor16f& rh) const;
    bool operator!=(Data64 rh) const;
};

struct ATIL_IMPORTEXPORT RgbColor32f
{
    Data128 pixel;

    RgbColor32f();
    RgbColor32f(Data128 val);
    RgbColor32f(float r, float g, float b);
    RgbColor32f(float val1, float val2, float val3, float a);
    const RgbColor32f& set(float r, float g, float b);
    const RgbColor32f& set(float r, float g, float b, float a, DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha);
    RgbColor asRgbColor(DataModelAttributes::ChannelOrder co) const;
    RgbColor asBgrColor(DataModelAttributes::ChannelOrder co) const;
    float asGray(DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha) const;
    const RgbColor32f& operator=(const RgbColor32f& rh);
    const RgbColor32f& operator=(Data128 rh);
    operator Data128() const;
    bool operator==(const RgbColor32f& rh) const;
    bool operator==(Data128 rh) const;
    bool operator!=(const RgbColor32f& rh) const;
    bool operator!=(Data128 rh) const;
};


struct ATIL_IMPORTEXPORT RgbColor32i
{
    Data128 pixel;

    RgbColor32i();
    RgbColor32i(Data128 val);
    RgbColor32i(Data32 r, Data32 g, Data32 b);
    RgbColor32i(Data32 val1, Data32 val2, Data32 val3, Data32 a);
    const RgbColor32i& set(Data32 r, Data32 g, Data32 b);
    const RgbColor32i& set(Data32 r, Data32 g, Data32 b, Data32 a, DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha);
    RgbColor asRgbColor(DataModelAttributes::ChannelOrder co) const;
    RgbColor asBgrColor(DataModelAttributes::ChannelOrder co) const;
    Data32 asGray(DataModelAttributes::ChannelOrder co = DataModelAttributes::kBlueGreenRedAlpha) const;
    const RgbColor32i& operator=(const RgbColor32i& rh);
    const RgbColor32i& operator=(Data128 rh);
    operator Data128() const;
    bool operator==(const RgbColor32i& rh) const;
    bool operator==(Data128 rh) const;
    bool operator!=(const RgbColor32i& rh) const;
    bool operator!=(Data128 rh) const;
};


#pragma pack(pop)


} //namespace Atil
