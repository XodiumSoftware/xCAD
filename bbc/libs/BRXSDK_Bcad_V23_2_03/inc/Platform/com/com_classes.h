// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// all supported Windows COM classes and functions

#pragma once

#ifndef _BS_COM_CLASSES_INCLUDED_
#define _BS_COM_CLASSES_INCLUDED_


#include "com_defs.h"
#include "com_errors.h"
#include "com_utils.h"


// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

  // include all the classes that we support
  #include "com_bstr.h"
  #include "Decimal.h"
  #include "Date.h"
  #include "Currency.h"
  #include "Variant.h"
  #include "SafeArray.h"
  #include "IUnknown.h"
  #include "IDispatch.h"
  #include "ITypeInfo.h"
  #include "CComVariant.h"
  #include "CComBSTR.h"
  #include "COleVariant.h"
  #include "COleSafeArray.h"
  #include "COleDispatchDriver.h"
  #include "CComSingleThreadModel.h"
  #include "CComMultiThreadModel.h"
  #include "CComObjectThreadModel.h"
  #include "CComObjectRootEx.h"
  #include "CComObjectRoot.h"
  #include "CComModule.h"
  #include "CComObject.h"


#endif // !_WIN32

#endif // _BS_COM_CLASSES_INCLUDED_
