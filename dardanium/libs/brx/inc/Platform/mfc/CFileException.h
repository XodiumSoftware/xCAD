// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CFileException type and functions

#ifndef _BS_MFC_FILEEXCEPTION_INCLUDED_
#define _BS_MFC_FILEEXCEPTION_INCLUDED_

#include "Platform/mfc/CString.h"
#include "Platform/mfc/CException.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

class BRXEXPORT CMfcFileException : public CException
{
    // DECLARE_DYNAMIC(CFileException)

public:
    enum
    {
        none,
        genericException,
        fileNotFound,
        badPath,
        tooManyOpenFiles,
        accessDenied,
        invalidFile,
        removeCurrentDir,
        directoryFull,
        badSeek,
        hardIO,
        sharingViolation,
        lockViolation,
        diskFull,
        endOfFile
    };

    CMfcFileException(int reason = CMfcFileException::none, LONG nOsErrorCode = -1,
                      LPCTSTR szFilename = NULL);

    virtual ~CMfcFileException() noexcept;

public:
    virtual BOOL GetErrorMessage(LPTSTR szError, UINT maxError, PUINT helpContext = NULL) const;

    static int PASCAL OsErrorToException(LONG nOsErrorCode);
    static int PASCAL ErrnoToException(int errornumber);

    static void PASCAL ThrowOsError(LONG nOsErrorCode, LPCTSTR szFilename = NULL);
    static void PASCAL ThrowErrno(int errornumber, LPCTSTR szFilename = NULL);

// public:
// #ifdef _DEBUG
//     virtual void Dump(CDumpContext&) const;
// #endif

public:
    int      m_cause;
    LONG     m_lOsError;
    CString  m_strFileName;
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

class BRXEXPORT CFileException : public CMfcFileException
{
public:
    CFileException(int reason = CMfcFileException::none, LONG nOsErrorCode = -1,
                   LPCTSTR szFilename = NULL)
        : CMfcFileException(reason, nOsErrorCode, szFilename) {};
};

#endif // !_WIN32

#endif // _BS_MFC_FILEEXCEPTION_INCLUDED_
