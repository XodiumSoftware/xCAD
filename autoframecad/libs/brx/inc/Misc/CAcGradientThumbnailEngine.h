// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

class AcCmEntityColor;

/** _ */
class BRX_IMPORTEXPORT CAcGradientThumbnailEngine
{
public:
    virtual ~CAcGradientThumbnailEngine() {}

    virtual Acad::ErrorStatus gradientThumbnailsDrawBitmap(int,HDC,int,int) = 0;
    virtual Acad::ErrorStatus gradientThumbnailsRender() = 0;
    virtual Acad::ErrorStatus gradientThumbnailsSetRotation(double) = 0;
    virtual Acad::ErrorStatus gradientThumbnailsSetShift(bool) = 0;
    virtual Acad::ErrorStatus gradientThumbnailsSetStartColor(AcCmEntityColor) = 0;
    virtual Acad::ErrorStatus gradientThumbnailsSetStopColor(AcCmEntityColor) = 0;
};