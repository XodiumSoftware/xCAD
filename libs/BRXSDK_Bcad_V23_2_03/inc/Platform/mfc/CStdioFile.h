// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// Windows MFC CStdioFile type and functions

#pragma once

#ifndef _BS_MFC_CSTDIOFILE_INCLUDED_
#define _BS_MFC_CSTDIOFILE_INCLUDED_

#include "Platform/mfc/CFile.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

class CMfcFileException;

class BRXEXPORT CMfcStdioFile : public CFile
{
    // DECLARE_DYNAMIC( CMfcStdioFile );

public:
    FILE * m_pStream;  // stdio FILE
                       // m_fileHandle / m_hFile from base class is _fileno(m_pStream)

public:
    CMfcStdioFile();
    CMfcStdioFile(FILE * srcFile);
    CMfcStdioFile(LPCTSTR szFileName, UINT openFlags);
    virtual ~CMfcStdioFile();

public:
    // read / write strings
    virtual void WriteString(LPCTSTR szString);
    virtual LPTSTR ReadString(LPTSTR szString, UINT nMax);
    virtual BOOL ReadString(CString& rdString);

    virtual ULONGLONG GetPosition() const;
    virtual ULONGLONG GetLength() const;
    virtual BOOL Open(LPCTSTR szFileName, UINT openFlags, CMfcFileException * error = NULL);
    virtual UINT Read(void* buffer, UINT nCount);
    virtual void Write(const void* buffer, UINT count);
    virtual ULONGLONG Seek(LONGLONG offset, UINT from);
    virtual void Abort();
    virtual void Flush();
    virtual void Close();

    // unsupported
    virtual CFile* Duplicate() const;
    virtual void LockRange(ULONGLONG position, ULONGLONG count);
    virtual void UnlockRange(ULONGLONG position, ULONGLONG count);
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

class BRXEXPORT CStdioFile : public CMfcStdioFile
{
public:
    CStdioFile() : CMfcStdioFile() {};
    CStdioFile(FILE * srcFile) : CMfcStdioFile(srcFile) {};
    CStdioFile(LPCTSTR szFileName, UINT openFlags) : CMfcStdioFile(szFileName, openFlags) {};
};

#endif // !_WIN32

#endif // _BS_MFC_CSTDIOFILE_INCLUDED_
