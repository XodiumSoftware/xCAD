// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"
#include "Atil/codec/FormatCodecPropertyInterface.h"


namespace Atil
{;

class WriteImageFileInterface;
class ReadImageFileInterface;
class FileSpecifier;
class FindFileInterface;
class DataModelAttributes;
class DataStreamInterface;
class Size;


class ImageFormatCodec
{
public:
    enum CodecCapability
    {
        kCanRead = 0x1,
        kCanWrite = 0x2,
        kCanReadAndWrite = 0x3
    };

    enum FormatDecodability
    {
        kReadable = 0,
        kNonSupported = 1,
        kNonReadable = 2,
        kCorrupted = 3
    };

    enum FormatFeature
    {
        kLosslessCompression = 0,
        kLossyCompression = 1,
        kDirectLoadable = 2,
        kDelayLoadable = 3,
        kMultipleFrames = 4,
        kThumbnailFrames = 5,
        kStreamable = 6
    };

    enum FormatFrameType
    {
        kImage = 0,
        kBand = 1,
        kMipMap = 2
    };

    enum FormatOrganization
    {
        kSingleFile = 0,
        kMultipleFiles = 1
    };

    enum FormatType
    {
        kStronglyTyped = 0,
        kLooselyTyped = 1
    };

public:
    virtual ~ImageFormatCodec() {}
    virtual void getLibVersionInfo(unsigned int&, unsigned int&, unsigned int&, unsigned int&, unsigned int&) const = 0;
    virtual void getApiVersionInfo(unsigned int&, unsigned int&) const = 0;
    virtual CodecCapability codecCapability() const = 0;
    virtual bool isValidFileName(const FileSpecifier&) const = 0;
    virtual FormatType getFormatDecodabilityType() const = 0;
    virtual FormatOrganization getFormatOrganization() const = 0;
    virtual FormatFrameType getFormatFrameType() const = 0;
    virtual bool isFormatFeature(FormatFeature) const = 0;
    virtual bool isSupportedProperty(FormatCodecPropertyInterface::PropertyIdentifier, StringBuffer* = (StringBuffer*)NULL) const = 0;
    virtual int getNumExtensions() const = 0;
    virtual void getExtensionText(int, StringBuffer&) const = 0;
    virtual void getFormatName(StringBuffer&) const = 0;
    virtual void getDescriptionText(StringBuffer&) const = 0;
    virtual void getCopyrightText(StringBuffer&) const = 0;
    virtual FormatDecodability isDecodableFile(const FileSpecifier&, FindFileInterface* = (FindFileInterface*)NULL) const = 0;
    virtual bool isEncodableImage(const DataModelAttributes&, Size) const = 0;
    virtual ReadImageFileInterface* openImage(const FileSpecifier*) const = 0;
    virtual ReadImageFileInterface* openImage(const FileSpecifier*, FindFileInterface&) const = 0;
    virtual WriteImageFileInterface* writeImage() const = 0;
    virtual ReadImageFileInterface* cloneOpenImage(const ReadImageFileInterface*, FindFileInterface&) const = 0;
    virtual bool isExtensionMatch(const char*) const = 0;
};

class ImageFormatCodecStreamingInterface
{
public:
    virtual ~ImageFormatCodecStreamingInterface() {}
    virtual ReadImageFileInterface* openImage(DataStreamInterface*) const = 0;
    virtual WriteImageFileInterface* writeImage(DataStreamInterface*) const = 0;
};


} //namespace Atil
