// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
