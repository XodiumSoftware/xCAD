// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// Windows MFC CFile type and functions

#pragma once

#ifndef _BS_MFC_CFILE_INCLUDED_
#define _BS_MFC_CFILE_INCLUDED_

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

#ifdef _WIN32
namespace Mfc
{
#endif

class CFileException;
struct CFileStatus;
class CString;

class BRXEXPORT CFile : public CObject
{
    // DECLARE_DYNAMIC( CFile );

public:
    enum SeekPosition
    {
        begin   = 0x0,
        current = 0x1,
        end     = 0x2
    };

    enum Attribute
    {
        normal =    0x00,
        readOnly =  0x01,
        hidden =    0x02,
        system =    0x04,
        volume =    0x08,
        directory = 0x10,
        archive =   0x20
    };

    enum OpenFlags
    {
        modeRead =         (int) 0x00000,
        modeWrite =        (int) 0x00001,
        modeReadWrite =    (int) 0x00002,
        shareCompat =      (int) 0x00000,
        shareExclusive =   (int) 0x00010,
        shareDenyWrite =   (int) 0x00020,
        shareDenyRead =    (int) 0x00030,
        shareDenyNone =    (int) 0x00040,
        modeNoInherit =    (int) 0x00080,
        modeCreate =       (int) 0x01000,
        modeNoTruncate =   (int) 0x02000,
        typeText =         (int) 0x04000,
        typeBinary =       (int) 0x08000,
        osNoBuffer =       (int) 0x10000,
        osWriteThrough =   (int) 0x20000,
        osRandomAccess =   (int) 0x40000,
        osSequentialScan = (int) 0x80000,
    };

public:
    HANDLE m_hFile;
    static AFX_DATA const HANDLE hFileNull;

public:
    CFile();
    CFile( HANDLE fileHandle );
    CFile( LPCTSTR fileName, UINT openFlags );
    virtual ~CFile();

    virtual CFile * Duplicate() const;
    virtual BOOL Open( LPCTSTR fileName, UINT openFlags,
                                         CFileException* ptrError = NULL );
    virtual void Close();
    virtual void Abort();

    virtual void Flush();
    virtual UINT Read( void * pBuffer, UINT count );
    virtual void Write( const void* pBuffer, UINT count ); 

    virtual ULONGLONG GetLength() const;
    virtual ULONGLONG Seek( LONGLONG bytes, UINT from );
    void SeekToBegin();
    ULONGLONG SeekToEnd();
    virtual void SetLength( ULONGLONG newLength );

    virtual void LockRange( ULONGLONG startFrom, ULONGLONG count );
    virtual void UnlockRange( ULONGLONG startFrom, ULONGLONG count );

    virtual CString GetFileName() const;
    virtual CString GetFilePath() const;
    virtual CString GetFileTitle() const;
    virtual ULONGLONG GetPosition() const;
    BOOL GetStatus( CFileStatus & status ) const;
    static BOOL PASCAL GetStatus( LPCTSTR fileName, CFileStatus & status );
    virtual void SetFilePath( LPCTSTR newPathName );
    static void PASCAL Remove( LPCTSTR fileName );
    static void PASCAL Rename( LPCTSTR fileOldName, LPCTSTR fileNewName );
    static void PASCAL SetStatus( LPCTSTR fileName,
                                  const CFileStatus & statusInfo );
};

#ifdef _WIN32
}   // namespace Mfc
#endif

// ========== Platform specific ==========

#endif // _BS_MFC_CFILE_INCLUDED_
