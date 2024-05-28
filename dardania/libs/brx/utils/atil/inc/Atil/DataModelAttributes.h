// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"


namespace Atil
{;


class ATIL_IMPORTEXPORT DataModelAttributes
{
public:
    enum BitsPerPixel
    {
        k1 = 0,
        k8 = 1,
        k16 = 2,
        k24 = 24, //BRX only
        k32 = 3,
        k64 = 4,
        k128 = 5
    };
    enum DataModelType
    {
        kDataModel = 0,
        kRgbModel = 1,
        kPalettedRgbModel = 2,
        kGrayModel = 3,
        kBitonalModel = 4,
        kRgbModel5b = 5,
        kRgbModel10 = 6,
        kRgbModel16i = 7,
        kRgbModel16f = 8,
        kRgbModel32f = 9,
        kGrayModel16i = 10,
        kGrayModel16f = 11,
        kGrayModel32f = 12,
        kGrayModel32i = 13
    };
    enum PixelType
    {
        kData1 = 0,
        kData8 = 1,
        kData16 = 2,
        kData32 = 3,
        kData64 = 4,
        kData128 = 5,
        kBitonal = 6,
        kGray = 7,
        kPalettedRgb = 8,
        kRgba = 9,
        kBgra = 10,
        kGray16i = 11,
        kGray16f = 12,
        kGray32f = 13,
        kRgba5b = 14,
        kBgra5b = 15,
        kRgba10i = 16,
        kBgra10i = 17,
        kRgba16i = 18,
        kBgra16i = 19,
        kRgba16f = 20,
        kBgra16f = 21,
        kRgba32f = 22,
        kBgra32f = 23,
        kGray32i = 24,
        kRgba32i = 25,
        kBgra32i = 26
    };
    enum DataType
    {
        kUnknown = 0,
        kUnsignedShort = 1,
        kSignedShort = 2,
        kUnsignedInteger = 3,
        kSignedInteger = 4,
        kFloat16 = 5,
        kFloat = 6,
        kBitFields = 7
    };
    enum BitFields
    {
        kFull = 0,
        k5551 = 1,
        k565 = 2
    };
    enum ChannelOrder
    {
        kSingleChannel = 0,
        kRedGreenBlueAlpha = 1,
        kBlueGreenRedAlpha = 2
    };

public:
    virtual BitFields bitFields() const = 0;
    virtual BitsPerPixel bitsPerPixel() const = 0;
    virtual int bitsUsedPerPixel() const = 0;
    virtual DataModelAttributes::ChannelOrder channelOrder() const = 0;
    virtual DataModelType dataModelType() const = 0;
    virtual DataType dataType() const = 0;
    virtual PixelType pixelType() const = 0;

protected:
    virtual ~DataModelAttributes() {}

};

namespace RgbModelAttributes
{
    enum Channels
    {
        k3Channels = 0,
        k4Channels = 1
    };
    enum Masks
    {
        kLowMask =      0x001f,
        kMidMask5551 =  0x03e0,
        kMidMask565 =   0x07e0,
        kHighMask5551 = 0x7c00,
        kHighMask565 =  0xf800,
        kAlphaMask =    0x8000
    };
}


} //namespace Atil
