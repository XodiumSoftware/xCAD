// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

namespace Atil
{
    class ImageFormatCodec;
    class ProgressCallbackInterface;
};

/** _ */
class AdHostImageAppServices
{
public:
    virtual Atil::ProgressCallbackInterface* registerProgressCallback(Atil::ProgressCallbackInterface*) = 0;
    virtual bool formatCodecRegistered(Atil::ImageFormatCodec&) = 0;
    virtual bool registerFormatCodec(Atil::ImageFormatCodec&) = 0;
    virtual bool reRegisterFormatCodec(Atil::ImageFormatCodec&) = 0;
    virtual bool unRegisterFormatCodec(Atil::ImageFormatCodec&) = 0;
    virtual const ACHAR* imageFileExtensions (bool = false) = 0;
    virtual const ACHAR* imageFilterString (bool = false) = 0;
};