// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"

namespace Atil
{;

class ImageFormatCodec;
class FormatCodecApiVersionInterface;
class PropertyStringProviderInterface;

} //namespace Atil


struct ATIL_IMPORTEXPORT AtilFormatCodecLibrary
{
    enum AvailableFormats
    {
        kJfif = 0,
        kPng = 1,
        kTiff = 2,
        kBmp = 3,
        //kCals = 4,
        //kSpot = 5,
        //kIg4 = 6,
        //kPict = 7,
        //kRlc = 8,
        //kTarga = 9,
        //kPcx = 10,
        //kFlic = 11,
        //kGif = 12,
        //kQBTIFF = 13,
        //kAAIGrid = 14,
        //kBAIGrid = 15,
        //kDDS = 16,
        //kDem = 17,
        //kDoq = 18,
        //kDted = 19,
        //kECW = 20,
        //kOpenEXR = 21,
        //kFAST = 22,
        //kHDR = 23,
        //kJp2 = 24,
        //kNITF = 25,
        //kPsd = 26,
        //kSid = 27
    };

    static int numberOfCodecs();
    static int numberOfCodecsDelayedInit();
    static Atil::ImageFormatCodec* createImageFormatCodec(AvailableFormats);
    static const Atil::FormatCodecApiVersionInterface* getFormatCodecApiVersion(int);
    static Atil::ImageFormatCodec* loadFormatCodec(int);
    static void unloadFormatCodec(int);
    static Atil::ImageFormatCodec* getFormatCodec(AvailableFormats);
    static const Atil::FormatCodecApiVersionInterface* findFormatCodecApiVersion(AvailableFormats);
    static int getFormatPosition(AvailableFormats);
    static void setResourceFileName(const Atil::char_t*);
    static void setPatentedEncodingSupportEnabled(bool, bool);
    static void registerPropertyStringProvider(Atil::PropertyStringProviderInterface const*);
};
