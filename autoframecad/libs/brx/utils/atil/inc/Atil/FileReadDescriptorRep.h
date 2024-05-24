// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"
#include "Atil/FileReadDescriptor.h"


namespace Atil
{;

class FileSpecifier;
class FindFileInterface;
class DataModel;
class ImageFormatCodec;
class FormatCodecPropertySetIterator;
class FormatCodecPropertyInterface;
class RowProviderInterface;


class FileReadDescriptorRep
{
public:
    virtual ~FileReadDescriptorRep() {}
    virtual void close() const = 0;
    virtual void construct(const FileSpecifier&, FindFileInterface*) = 0;
    virtual void construct(const FileSpecifier&, const ImageFormatCodec*, FindFileInterface*) = 0;
    virtual void construct(DataStreamInterface*, const ImageFormatCodec*) = 0;
    virtual void construct(FileReadDescriptorRep*) = 0;
    virtual const DataModel& dataModel() const = 0;
    virtual Atil::Orientation dataOrientation() const = 0;
    virtual const ImageFormatCodec* formatCodec() const = 0;
    virtual FileSpecifier getClosureSetFilename(int) const = 0;
    virtual void getDataSize(Size&) const = 0;
    virtual void getDataSize(int&, int&, int&) const = 0;
    virtual void getFileSpecifier(FileSpecifier&) const = 0;
    virtual void getOrientedSize(Size&) const = 0;
    virtual FormatCodecPropertyInterface* getProperty(FormatCodecPropertyInterface::PropertyIdentifier) const = 0;
    virtual FormatCodecPropertyInterface* getProperty(StringBuffer) const = 0;
    virtual FileReadDescriptor::MethodType loadMethod() const = 0;
    virtual FormatCodecPropertySetIterator* newPropertySetIterator() const = 0;
    virtual int numClosureSetFiles() const = 0;
    virtual int numFrames() const = 0;
    virtual void open() const = 0;
    virtual RowProviderInterface* read() = 0;
    virtual RowProviderInterface* scaledRead(const double&, Resample::FilterTypes) = 0;
    virtual int selectedFrame() const = 0;
    virtual bool setFrame(int) = 0;
};


} //namespace Atil
