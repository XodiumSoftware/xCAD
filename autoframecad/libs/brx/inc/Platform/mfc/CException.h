// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CException type and functions

#ifndef _BS_MFC_EXCEPTION_INCLUDED_
#define _BS_MFC_EXCEPTION_INCLUDED_

#include "Platform/mfc/CObject.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

class AFX_NOVTABLE BRXEXPORT CMfcException : public CObject
{
    // DECLARE_DYNAMIC(CException)

public:
    CMfcException();
    explicit CMfcException(BOOL autoDelete);
    virtual ~CMfcException() noexcept = 0;

    // to delete the exception in 'catch' block
    void Delete();

    virtual BOOL GetErrorMessage(LPTSTR szError, UINT maxError, PUINT helpContext = NULL) const;
    virtual BOOL GetErrorMessage(LPTSTR szError, UINT maxError, PUINT helpContext = NULL);
    virtual int ReportError(UINT type = MB_OK, UINT messageID = 0);

public:
    BOOL m_bAutoDelete;

// #ifdef _DEBUG
//     void PASCAL operator delete(void* pData);
//     void PASCAL operator delete(void* pData, LPCSTR szFilename, int lineNr);
// protected:
//     BOOL m_readyForDelete;
// #endif
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

class BRXEXPORT CException : public CMfcException
{
public:
    CException() : CMfcException() {};
    explicit CException(BOOL autoDelete) : CMfcException(autoDelete) {};
    virtual ~CException() noexcept {}
};

#endif // !_WIN32

#endif // _BS_MFC_EXCEPTION_INCLUDED_
