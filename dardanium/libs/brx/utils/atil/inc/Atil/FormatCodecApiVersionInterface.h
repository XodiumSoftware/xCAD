// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"
#include "AtilVersions.h"


namespace Atil
{;

class ImageFormatCodec;
class FileSpecifier;
class StringBuffer;


class ATIL_IMPORTEXPORT FormatCodecApiVersionInterface
{
public:
    virtual ~FormatCodecApiVersionInterface() {}
    virtual int majorVersion () const;
    virtual int minorVersion () const;
};


} //namespace Atil
