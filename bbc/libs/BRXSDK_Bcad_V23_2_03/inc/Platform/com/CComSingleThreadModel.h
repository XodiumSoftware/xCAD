// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// CComSingleThreadModel class and related functionality

#pragma once

#ifndef _BS_COM_CCOMSINGLETHREADMODEL_INCLUDED_
#define _BS_COM_CCOMSINGLETHREADMODEL_INCLUDED_

#ifndef _WIN32  // on Linux/Mac

#include "com_defs.h"

class CComSingleThreadModel
{
public:
    // typedef CComFakeCriticalSection AutoCriticalSection;
    // typedef CComFakeCriticalSection AutoDeleteCriticalSection;
    // typedef CComFakeCriticalSection CriticalSection;
    // typedef CComSingleThreadModel ThreadModelNoCS;

    static ULONG WINAPI Increment(LPLONG refcnt) noexcept(false) { return ++(*refcnt); };
    static ULONG WINAPI Decrement(LPLONG refcnt) noexcept(false) { return --(*refcnt); };
};

#endif // !_WIN32

#endif // _BS_COM_CCOMSINGLETHREADMODEL_INCLUDED_
