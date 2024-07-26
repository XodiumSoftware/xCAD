// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CString type and functions

#ifndef _BS__CSTRING_INCLUDED_
#define _BS__CSTRING_INCLUDED_

#include "Platform/mfc/CSimpleString.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

#ifdef _WIN32
namespace Mfc
{
#endif

class BRXEXPORT StringTraits
{
public:
    static IAtlStringMgr* GetDefaultManager() noexcept(false);

private:
    StringTraits();
    static IAtlMemMgr*    s_pDefaultMemMgr;
    static IAtlStringMgr* s_pDefaultStrMgr;
};

class BRXEXPORT CString : public CSimpleString
{
public:
    
    CString( ) noexcept(false);
    CString( const VARIANT& );
    CString( const VARIANT& , IAtlStringMgr* );
    CString( const CString& ) noexcept(false);
    CString( IAtlStringMgr* ) noexcept(false);
    
    CString( const XCHAR* );
    CString( const YCHAR* );

    CString( LPCSTR ,  IAtlStringMgr* );
    CString( LPCWSTR , IAtlStringMgr* );

    CString( wchar_t* );
    CString( const unsigned char* , IAtlStringMgr* );
    CString( char , int = 1 );
    CString( wchar_t , int = 1 );

    CString( const XCHAR* , int );
    CString( const YCHAR* , int );
    CString( const XCHAR* , int , IAtlStringMgr* );
    CString( const YCHAR* , int , IAtlStringMgr* );

    static void Construct( CString* );
    ~CString() noexcept(false);
    
    BSTR AllocSysString() const;
    void AnsiToOem();
    void AppendFormat( PCXSTR, ... );
    void AppendFormat( UINT,... );
    void AppendFormatV( PCXSTR, va_list );

    int Collate( PCXSTR ) const noexcept(false);
    int CollateNoCase( PCXSTR ) const noexcept(false);
    int Compare( PCXSTR ) const;
    int CompareNoCase( PCXSTR ) const noexcept(false);
    int Delete( int , int = 1 );
    int Find( PCXSTR ,int = 0 ) const noexcept(false);
    int Find( XCHAR , int = 0 ) const noexcept(false);
    int FindOneOf( PCXSTR ) const noexcept(false);

    void Format( UINT, ... );
    void Format( PCXSTR, ... );
    void FormatMessage( UINT, ... );
    void FormatMessage( PCXSTR, ... );
    void FormatV( PCXSTR, va_list );
    void FormatMessageV( PCXSTR, va_list* );

    BOOL GetEnvironmentVariable( PCXSTR );
    int Insert( int, PCXSTR );
    int Insert( int, XCHAR );
    CString Left( int ) const;

    BOOL LoadString( HINSTANCE hInstance, UINT nID, WORD wLanguageID );
    BOOL LoadString( HINSTANCE hInstance, UINT nID );
    BOOL LoadString( UINT nID );

    CString& MakeLower();
    CString& MakeReverse();
    CString& MakeUpper();
    CString Mid( int, int ) const;
    CString Mid( int ) const;
    void OemToAnsi();
    int Remove( XCHAR );
    int Replace( PCXSTR, PCXSTR );
    int Replace( XCHAR, XCHAR );
    int ReverseFind( XCHAR ) const noexcept(false);
    CString Right( int ) const;
    BSTR SetSysString( BSTR* ) const;
    CString SpanExcluding( PCXSTR ) const;
    CString SpanIncluding( PCXSTR ) const;
    CString Tokenize( PCXSTR, int& ) const;
    CString& Trim( XCHAR );
    CString& Trim( PCXSTR );
    CString& Trim( );
    CString& TrimLeft( XCHAR );
    CString& TrimLeft( PCXSTR );
    CString& TrimLeft( );
    CString& TrimRight( XCHAR );
    CString& TrimRight( PCXSTR );
    CString& TrimRight( );

    CString& operator=( const VARIANT& );
    CString& operator=( wchar_t );
    CString& operator=( char );
    CString& operator=( const unsigned char* );
    CString& operator=( PCYSTR );
    CString& operator=( PCXSTR );

    CString& operator=( const CString& );
    BRXEXPORT friend CString operator+( const CString&, const CString& );
    BRXEXPORT friend CString operator+( const CString&, PCXSTR );
    BRXEXPORT friend CString operator+( PCXSTR, const CString& );
    BRXEXPORT friend CString operator+( char, const CString& );
    BRXEXPORT friend CString operator+( const CString&, char );
    BRXEXPORT friend CString operator+( const CString&, wchar_t );
    BRXEXPORT friend CString operator+( wchar_t, const CString& );
    CString& operator+=( const CSimpleString& );
    CString& operator+=( PCXSTR );
    CString& operator+=( PCYSTR );
    CString& operator+=( char );
    CString& operator+=( unsigned char );
    CString& operator+=( wchar_t );
    CString& operator+=( const VARIANT& );
    BRXEXPORT friend bool operator==( const CString&, const CString& ) noexcept(false);
    BRXEXPORT friend bool operator==( const CString&, PCXSTR ) noexcept(false);

    BRXEXPORT friend bool operator==( const CString& , PCYSTR ) noexcept(false);
    
    BRXEXPORT friend bool operator==( const CString& , XCHAR ) noexcept(false);
    BRXEXPORT friend bool operator==( PCXSTR , const CString& ) noexcept(false);
    
    BRXEXPORT friend bool operator==( PCYSTR , const CString& ) noexcept(false);
    
    BRXEXPORT friend bool operator==( XCHAR , const CString& ) noexcept(false);
    BRXEXPORT friend bool operator!=( const CString& , const CString& ) noexcept(false);
    BRXEXPORT friend bool operator!=( const CString& , PCXSTR ) noexcept(false);

    BRXEXPORT friend bool operator!=( const CString& , PCYSTR ) noexcept(false);
    
    BRXEXPORT friend bool operator!=( const CString& , XCHAR ) noexcept(false);
    BRXEXPORT friend bool operator!=( PCXSTR , const CString& ) noexcept(false);

    BRXEXPORT friend bool operator!=( PCYSTR psz1, const CString& str2 ) noexcept(false);
    
    BRXEXPORT friend bool operator!=( XCHAR , const CString& ) noexcept(false);
    BRXEXPORT friend bool operator<( const CString& , const CString& ) noexcept(false);
    BRXEXPORT friend bool operator<( const CString& , PCXSTR ) noexcept(false);
    BRXEXPORT friend bool operator<( PCXSTR , const CString& ) noexcept(false);
    BRXEXPORT friend bool operator>( const CString& , const CString& ) noexcept(false);
    BRXEXPORT friend bool operator>( const CString& , PCXSTR ) noexcept(false);
    BRXEXPORT friend bool operator>( PCXSTR , const CString& ) noexcept(false);
    BRXEXPORT friend bool operator<=( const CString& , const CString& ) noexcept(false);
    BRXEXPORT friend bool operator<=( const CString& , PCXSTR ) noexcept(false);
    BRXEXPORT friend bool operator<=( PCXSTR , const CString& ) noexcept(false);
    BRXEXPORT friend bool operator>=( const CString& , const CString& ) noexcept(false);
    BRXEXPORT friend bool operator>=( const CString& , PCXSTR ) noexcept(false);
    BRXEXPORT friend bool operator>=( PCXSTR , const CString& ) noexcept(false);
};

#ifdef _WIN32
} // namespace Mfc
#endif

// ========== Platform specific ==========

#ifdef _WIN32

    typedef Mfc::CString CMfcString;

#else   // on Linux/Mac

    typedef CString CMfcString;
    
#endif

#endif // _BS_MFC_CSTRING_INCLUDED_
