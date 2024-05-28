// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifdef PAL
#undef PAL
#endif

#define Autodesk Bricsys
#define AutoCAD BRX

namespace Bricsys { namespace BRX {

namespace PAL
{

namespace FontUtils
{

enum class FontPitch
{
    kDefault = 0,
    kFixed = 1,
    kVariable = 2
};

enum class FontFamily
{
    kDoNotCare = 0 << 4,
    kRoman = 1 << 4,
    kSwiss = 2 << 4,
    kModern = 3 << 4,
    kScript = 4 << 4,
    kDecorative = 5 << 4
};

} //namespace FontUtils

} //namespace PAL

}};
