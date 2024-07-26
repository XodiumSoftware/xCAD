// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Exception.h"


namespace Atil
{;


class ATIL_IMPORTEXPORT ImageContextException : public Exception
{
public:
    enum ExceptionType 
    {
        kTileAlreadyAllocated = 0,
        kNotOpenForWrite = 1,
        kOutOfBounds = 2,
        kInvalidObject = 3,
        kUnSpecified = 4
    };

public:
    ImageContextException(const StringBuffer& msg, ExceptionType type = kUnSpecified)
        : Exception(msg), m_type(type) {}
    ImageContextException(const ImageContextException& rh) : m_type(rh.m_type) {}
    virtual ~ImageContextException() {}
    virtual ExceptionType getExceptionType() { return m_type; }

private:
    ExceptionType m_type;
};


} //namespace Atil
