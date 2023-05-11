// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
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
