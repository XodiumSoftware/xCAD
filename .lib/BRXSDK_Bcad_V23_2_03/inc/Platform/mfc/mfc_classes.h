// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// all supported Windows MFC types and functions

#pragma once

#ifndef _BS_MFC_CLASSES_INCLUDED_
#define _BS_MFC_CLASSES_INCLUDED_


#include "mfc_defs.h"


// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

  // include all the classes that we support
  #include "CRuntimeClass.h"
  #include "CException.h"
  #include "CArchiveException.h"
  #include "CFileException.h"
  #include "CSimpleException.h"
  #include "CMemoryException.h"
  #include "CNotSupportedException.h"
  #include "CInvalidArgException.h"
  #include "COleException.h"
  #include "CObject.h"
  #include "CArchive.h"
  #include "CFile.h"
  #include "CStdioFile.h"
  #include "CPoint.h"
  #include "CRect.h"
  #include "CSize.h"
  #include "CSimpleString.h"
  #include "CString.h"
  #include "CArray.h"
  #include "CObArray.h"
  #include "CWordArray.h"
  #include "CDWordArray.h"
  #include "CPtrArray.h"
  #include "CTypedPtrArray.h"
  #include "CStringArray.h"
  #include "CList.h"
  #include "CObList.h"
  #include "CStringList.h"


#endif // !_WIN32

#endif // _BS_MFC_CLASSES_INCLUDED_
