// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// CComObjectThreadModel class and related functionality

#pragma once

#ifndef _BS_COM_CCOMOBJECTTHREADMODEL_INCLUDED_
#define _BS_COM_CCOMOBJECTTHREADMODEL_INCLUDED_

#ifndef _WIN32  // on Linux/Mac

#include "com_defs.h"
#include "CComSingleThreadModel.h"
#include "CComMultiThreadModel.h"


  #if defined(_ATL_SINGLE_THREADED)

    #if defined(_ATL_APARTMENT_THREADED) || defined(_ATL_FREE_THREADED)
      #pragma message ("More than one global threading model defined.")
    #endif

    typedef CComSingleThreadModel CComObjectThreadModel;
    typedef CComSingleThreadModel CComGlobalsThreadModel;

  #elif defined(_ATL_APARTMENT_THREADED)

    #if defined(_ATL_SINGLE_THREADED) || defined(_ATL_FREE_THREADED)
      #pragma message ("More than one global threading model defined.")
    #endif

    typedef CComSingleThreadModel CComObjectThreadModel;
    typedef CComMultiThreadModel  CComGlobalsThreadModel;

  #elif defined(_ATL_FREE_THREADED)

    #if defined(_ATL_SINGLE_THREADED) || defined(_ATL_APARTMENT_THREADED)
      #pragma message ("More than one global threading model defined.")
    #endif

    typedef CComMultiThreadModel CComObjectThreadModel;
    typedef CComMultiThreadModel CComGlobalsThreadModel;

  #else

    // #pragma message ("No global threading model defined")

    typedef CComSingleThreadModel CComObjectThreadModel;
    typedef CComSingleThreadModel CComGlobalsThreadModel;

  #endif


#endif // !_WIN32

#endif // _BS_COM_CCOMOBJECTTHREADMODEL_INCLUDED_
