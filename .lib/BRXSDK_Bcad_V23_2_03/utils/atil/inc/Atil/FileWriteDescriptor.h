// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"
#include "Atil/codec/FormatCodecPropertyInterface.h"


namespace Atil
{;

class Internal;
class DataModel;
class ImageFormatCodec;
class FormatCodecPropertySetIterator;
class DataStreamInterface;
class Size;
class FileReadDescriptor;
class FileSpecifier;
class RowProviderInterface;
class FileWriteDescriptorRep;


class ATIL_IMPORTEXPORT FileWriteDescriptor
{
public:
    static void getCompatibleFormatCodecs(const DataModel*, const Size&, const ImageFormatCodec**&, int&);
    static bool isCompatibleFormatCodec(const ImageFormatCodec*, const DataModel*, Size);

public:
    FileWriteDescriptor(const ImageFormatCodec*);
    virtual ~FileWriteDescriptor();
    virtual void closeFile();
    void createImageFrame(const DataModel&, Size);
    const ImageFormatCodec* formatCodec() const;
    void getFileSpecifier(FileSpecifier&) const;
    FormatCodecPropertyInterface* getProperty(FormatCodecPropertyInterface::PropertyIdentifier) const;
    FormatCodecPropertyInterface* getProperty(StringBuffer) const;
    FormatCodecPropertySetIterator* newPropertySetIterator();
    bool requiredPropertiesSet() const;
    bool setFileSpecifier(const FileSpecifier&);
    void setOutputStream(DataStreamInterface*);
    bool setProperty(const FormatCodecPropertyInterface*);
    bool setProperties(const FileReadDescriptor*);
    int writeImageFrame(RowProviderInterface*);

private:
    friend Internal;
    FileWriteDescriptorRep* m_pImp;
};


} //namespace Atil
