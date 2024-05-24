// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"
#include "Atil/FileWriteDescriptor.h"
#include "Atil/codec/FormatCodecPropertyInterface.h"


namespace Atil
{;

class FileSpecifier;
class RowProviderInterface;
class StringBuffer;


class FileWriteDescriptorRep
{
public:
    virtual ~FileWriteDescriptorRep() {}
    virtual void closeFile() = 0;
    virtual void createImageFrame(const DataModel&, Size) = 0;
    virtual void construct(const ImageFormatCodec*) = 0;
    virtual const ImageFormatCodec* formatCodec() const = 0;
    virtual void getFileSpecifier(FileSpecifier&) const = 0;
    virtual FormatCodecPropertyInterface* getProperty(FormatCodecPropertyInterface::PropertyIdentifier) const = 0;
    virtual FormatCodecPropertyInterface* getProperty(StringBuffer) const = 0;
    virtual FormatCodecPropertySetIterator* newPropertySetIterator() = 0;
    virtual bool requiredPropertiesSet() const = 0;
    virtual bool setFileSpecifier(const FileSpecifier&) = 0;
    virtual void setOutputStream(DataStreamInterface*) = 0;
    virtual bool setProperty(const FormatCodecPropertyInterface*) = 0;
    virtual bool setProperties(const FileReadDescriptor*) = 0;
    virtual int writeImageFrame(RowProviderInterface*) = 0;
};


} //namespace Atil
