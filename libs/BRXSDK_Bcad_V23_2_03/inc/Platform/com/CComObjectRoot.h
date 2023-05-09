// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// CComObjectRoot class and related functionality

#pragma once

#ifndef _BS_COM_CCOMOBJECTROOT_INCLUDED_
#define _BS_COM_CCOMOBJECTROOT_INCLUDED_

#ifndef _WIN32  // on Linux/Mac

#include "com_defs.h"
#include "CComSingleThreadModel.h"
#include "CComMultiThreadModel.h"
#include "CComObjectRootEx.h"


typedef CComObjectRootEx<CComObjectThreadModel> CComObjectRoot;


#endif // !_WIN32

#endif // _BS_COM_CCOMOBJECTROOT_INCLUDED_
