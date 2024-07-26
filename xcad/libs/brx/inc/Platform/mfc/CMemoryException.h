// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CMemoryException type and functions

#ifndef _BS_MFC_MEMORYEXCEPTION_INCLUDED_
#define _BS_MFC_MEMORYEXCEPTION_INCLUDED_

#include "Platform/mfc/CSimpleException.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

class BRXEXPORT CMfcMemoryException : public CSimpleException
{
    // DECLARE_DYNAMIC(CMfcMemoryException)

public:
    CMfcMemoryException();
    explicit CMfcMemoryException(BOOL autoDelete);
    CMfcMemoryException(BOOL autoDelete, UINT resourceID);
    virtual ~CMfcMemoryException();
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

class BRXEXPORT CMemoryException : public CMfcMemoryException
{
public:
    CMemoryException() : CMfcMemoryException() {};
    CMemoryException(BOOL autoDelete, UINT resourceID) : CMfcMemoryException(autoDelete, resourceID) {}
    explicit CMemoryException(BOOL autoDelete) : CMfcMemoryException(autoDelete) {};
};

#endif // !_WIN32

#endif // _BS_MFC_MEMORYEXCEPTION_INCLUDED_
