// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/AcArray.h"
#include "Misc/AcHeapOperators.h"

class AcDbHandle;
struct AcStringData;

/** _ */
class BRX_IMPORTEXPORT AcString: public AcHeapOperators
{
private:
    //BRX START
    friend AcStringData;
    AcStringData* m_pData;
    //BRX END

public:

    enum
    {
        kAppRes = 1,
        kSigned,
        kUnSigned,
        kHex
    };

    enum
    {
        kParseZero = 0,
        kParseMinus1 = 1,
        kParseAssert = 2,
        kParseDefault = 2,
        kParseExcept = 4,
        kParseNoEmpty = 8
    };

    enum Encoding
    {
        Utf8
    };

    AcString();
    AcString(char);
    AcString(const AcDbHandle&);
    AcString(const AcString&);
    AcString(const char*);
    AcString(const wchar_t*);
    AcString(HINSTANCE,unsigned);
    AcString(int,unsigned);
    AcString(wchar_t);
    ~AcString();

    AcDbHandle asAcDbHandle(int=kParseDefault) const;
    AcString concat(char) const;
    AcString concat(const AcString&) const;
    AcString concat(const char*) const;
    AcString concat(const wchar_t*) const;
    AcString concat(wchar_t) const;
    AcString mid(int,int) const;
    AcString precat(ACHAR) const;
    AcString precat(const ACHAR*) const;
    AcString substr(int) const;
    AcString substr(int,int) const;
    AcString substrRev(int) const;
    AcString& append(const AcString&);
    AcString& append(const char*);
    AcString& append(const wchar_t*);
    AcString& append(wchar_t);
    AcString& assign(char);
    AcString& assign(const AcDbHandle&);
    AcString& assign(const AcString&);
    AcString& assign(const char*);
    AcString& assign(const wchar_t*);
    AcString& assign(wchar_t);
    AcString& setEmpty();
    bool isAscii() const;
    bool isEmpty() const;
    bool loadString(HINSTANCE,unsigned);
    bool loadString(unsigned);
    const ACHAR* kACharPtr() const;
    const char* kszPtr() const;
    const char* utf8Ptr() const;
    const wchar_t* constPtr() const;
    const wchar_t* kTCharPtr() const;
    const wchar_t* kwszPtr() const;
    int asDeci(int=kParseDefault) const;
    int asHex(int=kParseDefault) const;
    int compare(const AcString&) const;
    int compare(const char*) const;
    int compare(const wchar_t*) const;
    int compare(wchar_t) const;
    int compareNoCase(const AcString&) const;
    int compareNoCase(const char*) const;
    int compareNoCase(const wchar_t*) const;
    int compareNoCase(wchar_t) const;
    int find(ACHAR) const;
    int find(const ACHAR*) const;
    int find(const AcString&) const;
    int findOneOf(const ACHAR*) const;
    int findOneOfRev(const ACHAR*) const;
    int findRev(ACHAR) const;
    int findRev(const ACHAR*) const;
    int findRev(const AcString&) const;
    int match(const AcString&) const;
    int match(const char*, Encoding) const;
    int match(const wchar_t*) const;
    int matchNoCase(const AcString&) const;
    int matchNoCase(const char*, Encoding) const;
    int matchNoCase(const wchar_t*) const;
    unsigned int asUDeci(int=kParseDefault) const;
    unsigned int asUHex(int=kParseDefault) const;
    unsigned length() const;
    unsigned tcharLength() const;
    UINT64 asUDeci64(int=kParseDefault) const;
    UINT64 asUHex64(int=kParseDefault) const;
    AcString& format(const ACHAR*,...);
    AcString& formatV(const ACHAR*,va_list);
    AcString& appendFormat(const ACHAR*, ...);
    INT64 asDeci64(int=kParseDefault) const;
    INT64 asHex64(int=kParseDefault) const;
    AcString left(int) const;
    AcString right(int) const;
    ACHAR* getBuffer(int = 0);
    bool releaseBuffer(int = -1);

    AcString& makeUpper();
    AcString& makeLower();
    AcString& makeReverse();

    wchar_t getAt(int) const;
    AcString& setAt(int, ACHAR);
    int replace(const wchar_t*, const wchar_t*);
    int replace(wchar_t, wchar_t);
    AcString& insert(int, wchar_t);
    AcString& insert(int, const wchar_t*);
    int deleteAtIndex(int, int = 1);
    AcString tokenize(const wchar_t*, int&) const;

    AcString operator+(char) const;
    AcString operator+(const AcString&) const;
    AcString operator+(const char*) const;
    AcString operator+(const wchar_t*) const;
    AcString operator+(wchar_t) const;
    AcString& operator+=(const AcString&);
    AcString& operator+=(const char*);
    AcString& operator+=(const wchar_t*);
    AcString& operator+=(wchar_t);
    AcString& operator=(char);
    AcString& operator=(const AcDbHandle&);
    AcString& operator=(const AcString&);
    AcString& operator=(const char*);
    AcString& operator=(const wchar_t*);
    AcString& operator=(wchar_t);
    bool operator!=(const AcString&) const;
    bool operator!=(const char*) const;
    bool operator!=(const wchar_t*) const;
    bool operator!=(wchar_t) const;
    bool operator<(const AcString&) const;
    bool operator<(const char*) const;
    bool operator<(const wchar_t*) const;
    bool operator<(wchar_t) const;
    bool operator<=(const AcString&) const;
    bool operator<=(const char) const;
    bool operator<=(const char*) const;
    bool operator<=(const wchar_t) const;
    bool operator<=(const wchar_t*) const;
    bool operator==(const AcString&) const;
    bool operator==(const char*) const;
    bool operator==(const wchar_t*) const;
    bool operator==(wchar_t) const;
    bool operator>(const AcString&) const;
    bool operator>(const char*) const;
    bool operator>(const wchar_t*) const;
    bool operator>(wchar_t) const;
    bool operator>=(const AcString&) const;
    bool operator>=(const char*) const;
    bool operator>=(const wchar_t*) const;
    bool operator>=(wchar_t) const;
    operator const wchar_t*() const;

#ifdef _AFX
    AcString(const CStringW&);
    int compare(const CStringW&) const;
    int compareNoCase(const CStringW&) const;
    int match(const CStringW&) const;
    int matchNoCase(const CStringW&) const;

    AcString& operator+=(const CStringW&);
    AcString& operator=(const CStringW&);
    bool operator!=(const CStringW&) const;
    bool operator<(const CStringW&) const;
    bool operator<=(const CStringW&) const;
    bool operator==(const CStringW&) const;
    bool operator>(const CStringW&) const;
    bool operator>=(const CStringW&) const;
#endif
};

typedef AcArray< AcString, AcArrayObjectCopyReallocator<AcString> > AcStringArray;

AcString operator+(const char*,const AcString&);
AcString operator+(const wchar_t*,const AcString&);
AcString operator+(wchar_t,const AcString&);
bool operator!=(const char*,const AcString&);
bool operator!=(const wchar_t*,const AcString&);
bool operator!=(wchar_t,const AcString&);
bool operator<(const char*,const AcString&);
bool operator<(const wchar_t*,const AcString&);
bool operator<(wchar_t,const AcString&);
bool operator<=(const char*,const AcString&);
bool operator<=(const wchar_t*,const AcString&);
bool operator<=(wchar_t,const AcString&);
bool operator==(const char*,const AcString&);
bool operator==(const wchar_t*,const AcString&);
bool operator==(wchar_t,const AcString&);
bool operator>(const char*,const AcString&);
bool operator>(const wchar_t*,const AcString&);
bool operator>(wchar_t,const AcString&);
bool operator>=(const char*,const AcString&);
bool operator>=(const wchar_t*,const AcString&);
bool operator>=(wchar_t,const AcString&);

#ifdef _AFX
bool operator!=(const CStringW&,const AcString&);
bool operator<(const CStringW&,const AcString&);
bool operator<=(const CStringW&,const AcString&);
bool operator==(const CStringW&,const AcString&);
bool operator>(const CStringW&,const AcString&);
bool operator>=(const CStringW&,const AcString&);
#endif
