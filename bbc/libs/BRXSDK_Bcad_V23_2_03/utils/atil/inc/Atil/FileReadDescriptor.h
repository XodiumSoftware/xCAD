// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"
#include "Atil/ImageFormatCodec.h"
#include "Atil/codec/FormatCodecPropertyInterface.h"
#include "Atil/Transforms.h"


namespace Atil
{;

class DataModel;
class ImageFormatCodec;
class FileSpecifier;
class FileReadDescriptorRep;
class FormatCodecPropertySetIterator;
class Size;
class RowProviderInterface;
class FileReadDescriptor;
class FindFileInterface;
class FindFileInterface;
class DataStreamInterface;
class Internal;


class ATIL_IMPORTEXPORT FileReadDescriptor
{
public:
    enum MethodType
    {
        kFullRead = 0,
        kDirectRead = 1,
        kMultipleResolution = 2,
        kPartialLoad = 3,
        kThumbnail = 4,
        kStream = 5
    };

public:
    static ImageFormatCodec::FormatDecodability findImageFileCodec(const FileSpecifier&, const ImageFormatCodec*&);
    static ImageFormatCodec::FormatDecodability isDecodableFile(const FileSpecifier&, const ImageFormatCodec*);

public:
    FileReadDescriptor(const FileSpecifier&);
    FileReadDescriptor(const FileSpecifier&, FindFileInterface*);
    FileReadDescriptor(const FileSpecifier&, const ImageFormatCodec*);
    FileReadDescriptor(const FileSpecifier&, const ImageFormatCodec*, FindFileInterface*);
    FileReadDescriptor(DataStreamInterface*, const ImageFormatCodec*);
    FileReadDescriptor(const FileReadDescriptor&);
    ~FileReadDescriptor();
    void close() const;
    const DataModel& dataModel() const;
    Atil::Orientation dataOrientation() const;
    const ImageFormatCodec* formatCodec() const;
    FileSpecifier getClosureSetFilename(int) const;
    void getDataSize(Size&) const;
    void getDataSize(int&, int&, int&) const;
    void getFileSpecifier(FileSpecifier&) const;
    void getOrientedSize(Size&) const;
    FormatCodecPropertyInterface* getProperty(FormatCodecPropertyInterface::PropertyIdentifier) const;
    FormatCodecPropertyInterface* getProperty(StringBuffer) const;
    FileReadDescriptor::MethodType loadMethod() const;
    FormatCodecPropertySetIterator* newPropertySetIterator() const;
    int numClosureSetFiles() const;
    int numFrames() const;
    void open() const;
    RowProviderInterface* read();
    RowProviderInterface* scaledRead(const double&, Resample::FilterTypes);
    int selectedFrame() const;
    bool setFrame(int);

private:
    friend Internal;
    FileReadDescriptorRep* m_pImp;
};


} //namespace Atil
