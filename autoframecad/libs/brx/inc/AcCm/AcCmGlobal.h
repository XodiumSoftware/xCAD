// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

#ifdef __cplusplus

#include "AcCm/AcCmEntityColor.h"

//common forward declarations
class AcCmColor;
class AcCmComplexColor;
class AcCmTransparency;

namespace AcCm
{
    enum ACIColors
    {
        kACIByBlock = 0,
        kACIRed,
        kACIYellow,
        kACIGreen,
        kACICyan,
        kACIBlue,
        kACIMagenta,
        kACIForeground,
        kACIByLayer = 256
    };

    enum DialogTabs
    {
        kACITab = 1,
        kTrueColorTab = 2,
        kColorBookTab = 4
    };
}

Acad::ErrorStatus accmGetColorFromACIName(AcCmColor&,const ACHAR*);
Acad::ErrorStatus accmGetColorFromColorBookName(AcCmColor&,const ACHAR*,const ACHAR*);
Acad::ErrorStatus accmGetColorFromRGBName(AcCmColor&,const ACHAR*);

AcCmEntityColor accmResolveEffectiveColorToRGB(const AcCmEntityColor&, AcDbObjectId);
AcCmEntityColor accmAttenuateRGB(const AcCmEntityColor&);

#endif //__cplusplus

void accmGetLocalizedColorNames(const ACHAR*[9]);
