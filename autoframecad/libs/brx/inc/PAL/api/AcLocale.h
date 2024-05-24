// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcLocaleImp;

class BRX_IMPORTEXPORT AcLocale
{
public:
    AcLocale(const wchar_t*, const wchar_t*);
    AcLocale(const AcLocale&);
    AcLocale(AcLocale&&);

    ~AcLocale();

    const wchar_t* iso2LangName() const;
    const wchar_t* iso2CountryName() const;

    bool isValid() const;
    
    AcLocale& operator=(const AcLocale&);
    AcLocale& operator=(AcLocale&&);
    bool operator==(const AcLocale&) const;
    bool operator!=(const AcLocale&) const;

private:
    AcLocaleImp* m_pImp;
    friend class AcLocaleImp;
};
