// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CNotSupportedException type and functions

#ifndef _BS_MFC_NOTSURTEDEXCEPTION_INCLUDED_
#define _BS_MFC_NOTSURTEDEXCEPTION_INCLUDED_

#include "Platform/mfc/CSimpleException.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

class BRXEXPORT CMfcNotSupportedException : public CSimpleException
{
    // DECLARE_DYNAMIC(CMfcNotSupportedException)

public:
    CMfcNotSupportedException();
    explicit CMfcNotSupportedException(BOOL autoDelete);
    CMfcNotSupportedException(BOOL autoDelete, UINT resourceID);
    virtual ~CMfcNotSupportedException();
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

class BRXEXPORT CNotSupportedException : public CMfcNotSupportedException
{
public:
    CNotSupportedException() : CMfcNotSupportedException() {};
    CNotSupportedException(BOOL autoDelete, UINT resourceID)
        : CMfcNotSupportedException(autoDelete, resourceID) {};
    explicit CNotSupportedException(BOOL autoDelete)
        : CMfcNotSupportedException(autoDelete) {};
};

#endif // !_WIN32

#endif // _BS_MFC_NOTSURTEDEXCEPTION_INCLUDED_
