// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

#ifdef __cplusplus

/** _ */
class BRX_IMPORTEXPORT AcDbHandle
{
public:
    enum
    {
        kMaxValueBytes = 8,
        kStrSiz = 17
    };

private:
    Adesk::UInt32 m_low;
    Adesk::UInt32 m_high;
    Adesk::UInt64& asInt64();
    const Adesk::UInt64& asInt64() const;

public:
    AcDbHandle();
    AcDbHandle(const ACHAR*);
    AcDbHandle(const Adesk::UInt64&);
    AcDbHandle(int,int);

    Adesk::UInt32 high() const;
    Adesk::UInt32 low() const;
    bool isNull() const;
    bool isOne() const;
    int compare(const AcDbHandle&) const;
    void setHigh(Adesk::UInt32);
    void setLow(Adesk::UInt32);
    void setNull();
    void increment();
    void decrement();
    AcDbHandle slowOperatorPlus(const AcDbHandle&) const;
    void copyToOldType(Adesk::UInt8[8]) const;
    void copyFromOldType(const Adesk::UInt8[8]);
    void getValueBytes(Adesk::UInt8*, Adesk::UInt8*) const;
    void setValueBytes(Adesk::UInt8, const Adesk::UInt8*);
    void print() const;
    int byte(Adesk::UInt32) const;
    bool restZeros(int) const;

    bool getIntoAsciiBuffer(ACHAR*, size_t) const;
    // Templatized helper to deduce buffer size argument
    template<size_t cch> inline bool getIntoAsciiBuffer(ACHAR(&sbuf)[cch]) const { return getIntoAsciiBuffer(sbuf, cch); }

    AcDbHandle operator+(const AcDbHandle&) const;
    AcDbHandle operator+(Adesk::ULongPtr) const;
#ifdef __SYS_64_BIT__
    AcDbHandle operator+(Adesk::UInt32) const;
#else
    AcDbHandle operator+(Adesk::UInt64) const;
#endif // __SYS_64_BIT__
    AcDbHandle operator++(int);
    AcDbHandle operator-(const AcDbHandle&) const;
    AcDbHandle& operator++();
    AcDbHandle& operator+=(const AcDbHandle&);
    AcDbHandle& operator-=(const AcDbHandle&);
    AcDbHandle& operator=(Adesk::UInt32);
    AcDbHandle& operator=(Adesk::UInt64);
    AcDbHandle& operator=(const AcDbHandle&);
    AcDbHandle& operator=(const ACHAR*);
    bool operator!=(const AcDbHandle&) const;
    bool operator<(const AcDbHandle&) const;
    bool operator<=(const AcDbHandle&) const;
    bool operator==(const AcDbHandle&) const;
    bool operator>(const AcDbHandle&) const;
    bool operator>=(const AcDbHandle&) const;
    operator Adesk::UInt32() const;
    operator Adesk::UInt64() const;
};

const Adesk::UInt32 kBadUInt32Handle = 0xFFFFFFFF;

#endif //__cplusplus
