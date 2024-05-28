// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

/** _ */
class BRX_IMPORTEXPORT AcGiColorRGB
{
public:
    AcGiColorRGB(void) : red(0.0), green(0.0), blue(0.0) {}
    AcGiColorRGB(double r, double g, double b) : red(r), green(g), blue(b) {}

public:
    double red;
    double green;
    double blue;
};

inline AcGiColorRGB operator* (const AcGiColorRGB& clr1, const AcGiColorRGB& clr2)
{
    return AcGiColorRGB(clr1.red * clr2.red, clr1.green * clr2.green, clr1.blue * clr2.blue);
}

inline AcGiColorRGB operator* (const AcGiColorRGB& clr, double sh)
{
    return AcGiColorRGB(sh * clr.red, sh * clr.green, sh * clr.blue);
}

inline AcGiColorRGB operator* (double sh, const AcGiColorRGB& clr)
{
    return clr * sh;
}

inline AcGiColorRGB operator+ (const AcGiColorRGB& clr1, const AcGiColorRGB& clr2)
{
    return AcGiColorRGB(clr1.red + clr2.red, clr1.green + clr2.green, clr1.blue + clr2.blue);
}


class BRX_IMPORTEXPORT AcGiColorRGBA
{
public:
    AcGiColorRGBA(void) : red(0.0), green(0.0), blue(0.0), alpha(1.0) {}
    AcGiColorRGBA(double r, double g, double b, double a) : red(r), green(g), blue(b), alpha(a) {}

public:
    double red;
    double green;
    double blue;
    double alpha;
};

inline AcGiColorRGBA operator* (const AcGiColorRGBA& clr1, const AcGiColorRGBA& clr2)
{
    return AcGiColorRGBA(clr1.red * clr2.red, clr1.green * clr2.green, clr1.blue  * clr2.blue, clr1.alpha * clr2.alpha);
}

inline AcGiColorRGBA operator* (const AcGiColorRGBA& clr, double sh)
{
    return AcGiColorRGBA(sh * clr.red, sh * clr.green, sh * clr.blue, sh * clr.alpha);
}

inline AcGiColorRGBA operator* (double sh, const AcGiColorRGBA& clr)
{
    return clr * sh;
}

inline AcGiColorRGBA operator+ (const AcGiColorRGBA& clr1, const AcGiColorRGBA& clr2)
{
    return AcGiColorRGBA(clr1.red + clr2.red, clr1.green + clr2.green, clr1.blue + clr2.blue, clr1.alpha + clr2.alpha);
}
