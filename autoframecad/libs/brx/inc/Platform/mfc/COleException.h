// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC COleException type and functions

#ifndef _BS_MFC_COLEEXCEPTION_INCLUDED_
#define _BS_MFC_COLEEXCEPTION_INCLUDED_

#include "Platform/mfc/CException.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

class BRXEXPORT CMfcOleException : public CException
{
    // DECLARE_DYNAMIC(CMfcOleException)
public:
    CMfcOleException();
    virtual ~CMfcOleException();

    virtual BOOL GetErrorMessage(LPTSTR szError, UINT maxError, PUINT helpContext = NULL) const;

    static SCODE PASCAL Process(const CException* pException);

public:
    SCODE  m_sc;
};

class CMfcOleDispatchException : public CException
{
    //DECLARE_DYNAMIC(CMfcOleDispatchException)
public:
    CMfcOleDispatchException(LPCTSTR szDescription, UINT helpID, WORD wCode);
    virtual ~CMfcOleDispatchException() noexcept;

    virtual BOOL GetErrorMessage(LPTSTR szError, UINT maxError, PUINT helpContext = NULL) const;

    static void PASCAL Process(EXCEPINFO* pInfo, const CException* pException);

public:
    SCODE   m_scError;          // SCODE describing the error

    WORD    m_wCode;            // error code (specific to IDispatch implementation)
    CString m_strDescription;   // human readable description of the error
    DWORD   m_dwHelpContext;    // help context for error

    CString m_strHelpFile;      // help file to use with m_dwHelpContext
    CString m_strSource;        // source of the error (name of server)
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

class BRXEXPORT COleException : public CMfcOleException
{
public:
    COleException() : CMfcOleException() {};
};


class BRXEXPORT COleDispatchException : public CMfcOleDispatchException
{
public:
    COleDispatchException(LPCTSTR szDescription, UINT helpID, WORD wCode)
        : CMfcOleDispatchException(szDescription, helpID, wCode) {};

};

#endif // !_WIN32

#endif // _BS_MFC_COLEEXCEPTION_INCLUDED_
