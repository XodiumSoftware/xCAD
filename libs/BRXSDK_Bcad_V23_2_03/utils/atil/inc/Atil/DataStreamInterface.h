// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"


namespace Atil
{;


class DataStreamInterface
{
public:
    enum StreamMode
    {
        kClosed = 0,
        kForRead = 1,
        kForWrite = 2
    };

public:
    virtual ~DataStreamInterface() {}
    virtual void close() = 0;
    virtual bool open(StreamMode) = 0;
    virtual void read(int, unsigned char*, int&) = 0;
    virtual bool reset() = 0;
    virtual bool write(int, const unsigned char*) = 0;
};

class SeekableDataStreamInterface : public DataStreamInterface
{
public:
    enum SeekBase
    {
        kFromStart = 0,
        kFromEnd = 1,
        kFromCurrent = 2
    };

public:
    virtual ~SeekableDataStreamInterface() {}
    virtual Int32 seek(Int32, SeekBase) = 0;
};


} //namespace Atil
