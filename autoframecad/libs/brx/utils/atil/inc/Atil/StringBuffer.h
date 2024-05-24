// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"


namespace Atil
{;


class ATIL_IMPORTEXPORT StringBuffer
{
public:
    enum CharacterType
    {
        kASCII = 0,
        kUTF_8 = 1,
        kUTF_16 = 2,
        kUTF_32 = 3,
        kMBCS = 4
    };

    static int bytesInString(const Byte*, CharacterType);
    static void convertString(const StringBuffer&, StringBuffer&, CharacterType);
    static CharacterType defaultCharacterType();

public:
    StringBuffer() : m_size(0), m_pData(nullptr), m_type(kASCII) {}
    StringBuffer(int size, CharacterType type = kASCII) : m_size(size), m_pData(nullptr), m_type(type) {}
    StringBuffer(int, const Byte*, CharacterType = kASCII);
    StringBuffer(const StringBuffer&);
    virtual ~StringBuffer();

    virtual const Byte* data() const;
    virtual bool isZero() const;
    virtual int numDataBytes() const;
    virtual StringBuffer& set(const StringBuffer&);
    virtual StringBuffer& set(int, const Byte*, CharacterType = kASCII);
    virtual CharacterType type() const;

    operator const char_t*() const;
    StringBuffer& operator=(const StringBuffer&);
    bool operator==(const StringBuffer&) const;
    bool operator!=(const StringBuffer&) const;

private:
    int m_size;
    Byte* m_pData;
    CharacterType  m_type;
};


} //namespace Atil
