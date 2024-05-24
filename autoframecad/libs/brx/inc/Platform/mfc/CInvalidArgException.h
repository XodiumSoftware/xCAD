// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CException type and functions

#ifndef _BS_MFC_INVAIDARGEXCEPTION_INCLUDED_
#define _BS_MFC_INVAIDARGEXCEPTION_INCLUDED_

#include "Platform/mfc/CSimpleException.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

class BRXEXPORT CMfcInvalidArgException : public CSimpleException
{
    // DECLARE_DYNAMIC(CMfcInvalidArgException)

public:
    CMfcInvalidArgException();
    CMfcInvalidArgException(BOOL autoDelete);
    CMfcInvalidArgException(BOOL autoDelete, UINT resourceID);
    virtual ~CMfcInvalidArgException();
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

class BRXEXPORT CInvalidArgException : public CMfcInvalidArgException
{
public:
    CInvalidArgException() : CMfcInvalidArgException() {};
    CInvalidArgException(BOOL autoDelete) : CMfcInvalidArgException(autoDelete) {};
    CInvalidArgException(BOOL autoDelete, UINT resourceID)
        : CMfcInvalidArgException(autoDelete, resourceID) {};
};

#endif // !_WIN32

#endif // _BS_MFC_INVAIDARGEXCEPTION_INCLUDED_
