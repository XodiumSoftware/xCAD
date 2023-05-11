// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeMatrix2d.h"
#include "AcGi/AcGiGlobal.h"

/** _ */
struct AcGiRequestScanLines
{
    enum IEColorSystem
    {
        kBitonal = 0,
        kCMY,
        kCMYK,
        kRGB
    };

    enum IEDitherMethod
    {
        kIEAnyPalette = 0,
        kCustomDithering,
        kCustomDitheringMethod
    };

    enum ImagePaletteType
    {
        kFromDevice = 0,
        kFromIeWholeImage
    };

    union
    {
        Adesk::Int16 mBackgroundIndex;
        Adesk::Int8 mBackgroundRGB[3];
    } mBackgroundColor;
    union
    {
        Adesk::Int16 mEntityIndex;
        Adesk::Int8 mEntityRGB[3];
    } mEntityColor;
    union
    {
        Adesk::Int16 mTransparentIndex;
        Adesk::Int8 mTransparentRGB[3];
    } mTransparentColor;

    AcGeMatrix2d mPixelToDc;
    AcGePoint2d mLowerLeft;
    AcGePoint2d mUpperRight;
    AcGiImageOrg mImageOrg;
    AcGiImageOrient mImageOrient;
    AcGiRotationFilterType mRotationFilterType;
    AcGiScaleFilterType mScaleFilterType;
    AcGiScaleType mScalingType;
    Adesk::Int16 mColorDepth;
    Adesk::Int16 mIsDisplay;
    Adesk::Int16 mWindowId;
    Adesk::Int32 mNumRows;
    Adesk::Int32 mPaletteIncarnation;
    Adesk::Int32 mRowWidth;
    Adesk::Int8* mpPalette;
    Adesk::UInt32 mnContours;
    Adesk::UInt32 mPixelMaxX;
    Adesk::UInt32 mPixelMaxY;
    Adesk::UInt32 mPixelMinX;
    Adesk::UInt32 mPixelMinY;
    const Adesk::Int32* mpBoundaryPoints;
    const Adesk::Int32* mpCounts;
    double mRasterRatio;
    ImagePaletteType mPaletteType;
    short mnThisChunk;
    short mnTotalChunks;
    void* mpDataBuffer;
    void* mpImageId;

    AcGiRequestScanLines();
};
