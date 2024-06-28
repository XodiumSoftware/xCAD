// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"


namespace Atil
{;


class FileSpecifier
{
public:
    enum Type
    {
        kFilePath = 0,
        kOther = 1,
        kStorageProtocol = 2
    };

public:
    FileSpecifier() : m_type(kOther) {}
    FileSpecifier(const StringBuffer& s, Type t) : m_string(s), m_type(t) {}
    FileSpecifier(const FileSpecifier& rh) : m_string(rh.m_string), m_type(rh.m_type) {}
    virtual ~FileSpecifier() {}
    virtual const FileSpecifier& operator= (const FileSpecifier& rh) { m_string = rh.m_string; m_type = rh.m_type; return *this; }
    virtual bool operator== (const FileSpecifier& rh) { return (m_type == rh.m_type && m_string == rh.m_string); }
    virtual bool operator!= (const FileSpecifier& rh) { return (m_type != rh.m_type || m_string != rh.m_string); }
    virtual void set(const StringBuffer& s, Type t) { m_string = s; m_type = t; }
    virtual const StringBuffer& string() const { return m_string; }
    virtual FileSpecifier::Type type() const { return m_type; }

private:
    StringBuffer m_string;
    FileSpecifier::Type m_type;
};


} //namespace Atil
