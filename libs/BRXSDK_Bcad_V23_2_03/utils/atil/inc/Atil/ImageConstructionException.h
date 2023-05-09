// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Exception.h"


namespace Atil
{;


class ATIL_IMPORTEXPORT ImageConstructionException : public Exception
{
public:
    enum ExceptionType
    {
        kIncompatibleTileSize = 0,
        kInvalidClearColor = 1,
        kInvalidSize = 2,
        kNonClonal = 3,
        kUnsafeClone = 4,
        kInsufficentStorage = 5,
        kInvalidRowAlignment = 6,
        kInvalidData = 7,
        kUnSpecified = 8
    };

public:
    ImageConstructionException(const StringBuffer& msg, ExceptionType type = kUnSpecified)
        : Exception(msg), m_type(type) {}
    ImageConstructionException(const ImageConstructionException& rh) : m_type(rh.m_type) {}
    virtual ~ImageConstructionException() {}
    virtual ExceptionType getExceptionType() { return m_type; }

private:
    ExceptionType m_type;
};


} //namespace Atil
