// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Exception.h"


namespace Atil
{;


class ATIL_IMPORTEXPORT ImageFilterException : public Exception
{
public:
    enum ExceptionType
    {
        kNotInitialized = 0,
        kNoValidInput = 1,
        kInvalidClearColor = 2,
        kOverConnected = 3,
        kAlreadyInitialized = 4,
        kUnSpecified = 5
    };

public:
    ImageFilterException(const StringBuffer& msg, ExceptionType type = kUnSpecified)
        : Exception(msg), m_type(type) {}
    ImageFilterException(const ImageFilterException& rh) : m_type(rh.m_type) {}
    virtual ~ImageFilterException() {}
    virtual ExceptionType getExceptionType() { return m_type; }

private:
    ExceptionType m_type;
};


} //namespace Atil
