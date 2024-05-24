// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CString type and functions

#ifndef _BS__CSIMPLESTRING_INCLUDED_
#define _BS__CSIMPLESTRING_INCLUDED_

#include "Platform/atl/atlsimpstr.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

#ifdef _WIN32
namespace Mfc
{
#endif

class BRXEXPORT CSimpleString
{
public:
    
    CSimpleString( const CSimpleString& );
    CSimpleString( PCXSTR pszSrc, IAtlStringMgr* );
    CSimpleString( const XCHAR*, int, IAtlStringMgr* );
    explicit CSimpleString( IAtlStringMgr* ) noexcept(false);

    ~CSimpleString() noexcept(false);
    
    void Append( const CSimpleString& );
    void Append( PCXSTR , int );
    void Append( PCXSTR );
    void AppendChar( XCHAR );
    static void CopyChars( XCHAR* , const XCHAR* , int ) noexcept(false);
    static void CopyCharsOverlapped( XCHAR* , const XCHAR* , int ) noexcept(false);
    void Empty( ) noexcept(false);
    void FreeExtra( );
    
    int GetAllocLength( ) const noexcept(false);
    XCHAR GetAt( int ) const;
    PXSTR GetBuffer( int );
    PXSTR GetBuffer( );
    PXSTR GetBufferSetLength( int );
    int GetLength( ) const noexcept(false);
    IAtlStringMgr* GetManager( ) const noexcept(false);
    PCXSTR GetString( ) const noexcept(false);
    
    bool IsEmpty( ) const noexcept(false);
    PXSTR LockBuffer( );
    void Preallocate( int );
    void ReleaseBuffer( int = -1 );
    void ReleaseBufferSetLength( int );
    void SetAt( int , XCHAR );
    void SetManager( IAtlStringMgr* );
    void SetString( PCXSTR , int );
    void SetString( PCXSTR );
    void Truncate( int );
    void UnlockBuffer( ) noexcept(false);
    
    CSimpleString& operator +=( PCXSTR );
    CSimpleString& operator +=( const CSimpleString& );
    CSimpleString& operator +=( char );
    CSimpleString& operator +=( unsigned char );
    CSimpleString& operator +=( wchar_t );
    CSimpleString& operator =( PCXSTR );
    CSimpleString& operator =( const CSimpleString& );

    BRXEXPORT friend CSimpleString operator+( const CSimpleString& , const CSimpleString& );
    BRXEXPORT friend CSimpleString operator+( const CSimpleString& , PCXSTR );
    BRXEXPORT friend CSimpleString operator+( PCXSTR , const CSimpleString& );
    
    XCHAR operator[]( int ) const;
    operator PCXSTR( ) const noexcept(false);
    
    static int StringLength( PCXSTR ) noexcept(false);
    static int StringLength( PCYSTR ) noexcept(false);

    static void ThrowMemoryException();


protected:

    static void Concatenate( CSimpleString& , PCXSTR , int , PCXSTR , int );

private:

    void bind( CStringData* );
    CStringData* getStringData() const noexcept(false);
    void setLength( int );
    void reallocate( int );
    void duplicate( int );
    PXSTR setupWrite( int );
    static CStringData* cloneStringData( CStringData* );
    
    CStringData* m_pStringData;
};

#ifdef _WIN32
} // namespace Mfc
#endif

// ========== Platform specific ==========

#ifdef _WIN32

    #define CMfcSimpleString Mfc::CSimpleString

#else   // on Linux/Mac

    #define CMfcSimpleString CSimpleString
    
#endif

#endif // _BS_MFC_CSTRING_INCLUDED_
