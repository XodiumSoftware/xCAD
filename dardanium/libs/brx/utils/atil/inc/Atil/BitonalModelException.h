// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Exception.h"


namespace Atil
{;


class ATIL_IMPORTEXPORT BitonalModelException : public Exception
{
public:
    enum ExceptionType
    {
        kInvalidPaletteIndex = 0
    };

public:
    BitonalModelException(const StringBuffer& msg, ExceptionType type = kInvalidPaletteIndex)
        : Exception(msg), m_type(type) {}
    BitonalModelException(const BitonalModelException& rh) : m_type(rh.m_type) {}
    virtual ~BitonalModelException() {}
    virtual ExceptionType getExceptionType() { return m_type; }

private:
    ExceptionType m_type;
};


} //namespace Atil
