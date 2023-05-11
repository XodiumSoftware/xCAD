// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Exception.h"


namespace Atil
{;


class ATIL_IMPORTEXPORT ImageException : public Exception
{
public:
    enum ExceptionType
    {
        kInvalidSubRegion = 0,
        kIncompatibleDataModel = 1,
        kUnableToRegisterReactor = 2,
        kInvalidBlendTarget = 3,
        kInvalidPixelType = 4,
        kNullConstruction = 5,
        kUnSpecified = 6
    };

public:
    ImageException(const StringBuffer& msg, ExceptionType type = kUnSpecified)
        : Exception(msg), m_type(type) {}
    ImageException(const ImageException& rh) : m_type(rh.m_type) {}
    virtual ~ImageException() {}
    virtual ExceptionType getExceptionType() { return m_type; }

private:
    ExceptionType m_type;
};


} //namespace Atil
