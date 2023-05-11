// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

typedef wchar_t* PWIDESTR;
typedef const wchar_t* PCWIDESTR;

class BrxDMMWideStringImp;

/** _ */
class BRX_IMPORTEXPORT AcDMMWideString
{
private:
    //BRX START
    BrxDMMWideStringImp* m_pBrxImp;
    //BRX END
public:
    AcDMMWideString();
    AcDMMWideString(PCWIDESTR);
    AcDMMWideString(const AcDMMWideString&);
    virtual ~AcDMMWideString();

    bool IsEmpty() const;
    unsigned GetLength() const;
    void Empty();

    const AcDMMWideString& operator+=(AcDMMWideString);
    const AcDMMWideString& operator=(const AcDMMWideString&);
    const AcDMMWideString& operator=(PCWIDESTR);
    operator PCWIDESTR() const;

    friend AcDMMWideString operator+(const AcDMMWideString&,const AcDMMWideString&);
    friend AcDMMWideString operator+(const AcDMMWideString&,wchar_t);
    friend AcDMMWideString operator+(wchar_t,const AcDMMWideString&);
};

typedef AcArray<AcDMMWideString, AcArrayObjectCopyReallocator<AcDMMWideString> > AcDMMStringVec;

