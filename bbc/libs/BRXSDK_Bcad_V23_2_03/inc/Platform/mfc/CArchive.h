// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// Windows MFC CObject type and functions

#pragma once

#ifndef _BS_CARCHIVE_INCLUDED_
#define _BS_CARCHIVE_INCLUDED_

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

#ifdef _WIN32
namespace Mfc
{
#endif

class CFile;
class CObject;
struct CRuntimeClass;
class CDocument;
class CArchiveException;
class CFileException;
class CMemoryException;
class CString;

class BRXEXPORT CArchive
{
    public:

        CDocument * m_pDoc;

        CArchive( CFile * fileName, UINT mode, int bufSize = 4096, 
                                                     void * pBuf = NULL );
        ~CArchive();
        void Close();
        void Abort();

        void Flush();
        friend CArchive & operator <<( CArchive & archive, const CObject * pCObj 
                                   ) noexcept(false);
        friend CArchive & AFXAPI operator <<( CArchive & archive, 
                                                                 const RECT & rectangle );
        friend CArchive & AFXAPI operator <<( CArchive & archive, POINT pointTo );
        friend CArchive & AFXAPI operator <<( CArchive & archive, SIZE dim );
        //template <typename BaseType, class StringTraits> CArchive & operator <<( 
          //                   const ATL::CStringT<BaseType, StringTraits> & string );
        CArchive & operator <<( BYTE bParam );
        CArchive & operator <<( WORD wParam );
        CArchive & operator <<( LONG lParam );
        CArchive & operator <<( DWORD dwParam );
        CArchive & operator <<( float fParam );
        CArchive & operator <<( double dParam );
        //CArchive & operator <<( int iParam );
        CArchive & operator <<( short shParam );
        CArchive & operator <<( char chParam );
        CArchive & operator <<( wchar_t wcParam );
        //CArchive & operator <<( unsigned uParam );
        CArchive & operator <<( bool bParam );
#ifndef _LINUXMAC64
        CArchive & operator <<( ULONGLONG ullParam );
        CArchive & operator <<( LONGLONG llParam );
#endif

        friend CArchive & operator >>( CArchive & archive, CObject *& pCObj ) noexcept(false);
        friend CArchive & operator >>( CArchive & archive, const CObject *& pCObj) noexcept(false);
        friend CArchive & AFXAPI operator >>( CArchive & archive,
                                                                      const RECT & rect );
        friend CArchive & AFXAPI operator >>( CArchive & archive, POINT point );
        friend CArchive & AFXAPI operator >>( CArchive & archive, SIZE size );
        //template <typename BaseType, class StringTraits> CArchive & operator >>
          //                       ( ATL::CStringT<BaseType, StringTraits> & string );
        CArchive & operator >>( BYTE & bParam );
        CArchive & operator >>( WORD & wParam );
        CArchive & operator >>( int & iParam );
        //CArchive & operator >>( LONG & lParam );
        CArchive & operator >>( DWORD & dwParam );
        CArchive & operator >>( float & fParam );
        CArchive & operator >>( double & dParam );
        CArchive & operator >>( short & shParam );
        CArchive & operator >>( char & chParam );
        CArchive & operator >>( wchar_t & wcParam );
        //CArchive & operator >>( unsigned & uParam );
        CArchive & operator >>( bool & bParam );
        CArchive & operator >>( ULONGLONG & ullParam );
        CArchive & operator >>( LONGLONG & llParam );

        UINT Read( void * pBuf, UINT max );
        BOOL ReadString( CString & string );
        LPTSTR ReadString( LPTSTR buffer, UINT max );
        void Write( const void * pBuf, UINT max );
        void WriteString( LPCTSTR buffer );

        CFile * GetFile() const;
        UINT GetObjectSchema();
        BOOL IsBufferEmpty() const;
        BOOL IsByteSwapping() const;
        BOOL IsLoading() const;
        BOOL IsStoring() const;
        void SetObjectSchema( UINT schema );

        void MapObject( const CObject * pCObj );
        CRuntimeClass * ReadClass( const CRuntimeClass * pClassRefReq = NULL, 
                                      UINT * ptrSchema = NULL, DWORD * ptrObjTag = NULL );
        CObject * ReadObject( const CRuntimeClass * pClassOf );
        void SerializeClass( const CRuntimeClass * pClassRefOf );
        void SetLoadParams( UINT growBy = 1024 );
        void SetStoreParams( UINT hashSize = 2053, UINT blockSize = 128 );
        void WriteClass( const CRuntimeClass * pClassRefOf );
        void WriteObject( const CObject * pCObj );
};

#ifdef _WIN32
} // namespace Mfc
#endif

// ========== Platform specific ==========

#ifdef _WIN32
    typedef Mfc::CArchive   CMfcArchive;
#else
    typedef      CArchive   CMfcArchive;
#endif

#endif // _BS_MFC_CARCHIVE_INCLUDED_
