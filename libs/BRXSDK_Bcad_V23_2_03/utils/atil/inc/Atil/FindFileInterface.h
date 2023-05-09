// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"


namespace Atil
{;

class ImageFormatCodec;
class FileSpecifier;
class StringBuffer;


class FindFileInterface
{
public:
    virtual ~FindFileInterface() {}
    virtual bool findFile(const ImageFormatCodec&, const FileSpecifier&, const FileSpecifier&, FileSpecifier&) = 0;
    virtual bool findFile(const ImageFormatCodec&, const FileSpecifier&, const StringBuffer&, FileSpecifier&) = 0;
};


} //namespace Atil
