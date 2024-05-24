// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CSimpleException type and functions

#ifndef _BS_MFC_CSIMPLEEXCEPTION_INCLUDED_
#define _BS_MFC_CSIMPLEEXCEPTION_INCLUDED_

#include "Platform/mfc/CException.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

class AFX_NOVTABLE BRXEXPORT CMfcSimpleException : public CException
{
public:
    CMfcSimpleException();
    explicit CMfcSimpleException(BOOL autoDelete);

    virtual ~CMfcSimpleException() = 0;

    virtual BOOL GetErrorMessage(LPTSTR szError, UINT maxError,
                                 PUINT helpContext = NULL) const;

    // used during MFC initialization
    void InitString();

protected:
    BOOL   m_bInitialized;
    BOOL   m_bLoaded;
    TCHAR  m_szMessage[2048];
    UINT   m_nResourceID;

public:
    BOOL   m_bAutoDelete;
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

class BRXEXPORT CSimpleException : public CMfcSimpleException
{
public:
    CSimpleException() : CMfcSimpleException() {};
    explicit CSimpleException(BOOL autoDelete) : CMfcSimpleException(autoDelete) {};
};

#endif // !_WIN32

#endif // _BS_MFC_CSIMPLEEXCEPTION_INCLUDED_
