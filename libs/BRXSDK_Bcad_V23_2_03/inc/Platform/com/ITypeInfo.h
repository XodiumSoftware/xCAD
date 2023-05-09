// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// COM ITypeInfo class and related functionality

#pragma once

#ifndef _BS_COM_ITYPEINFO_INCLUDED_
#define _BS_COM_ITYPEINFO_INCLUDED_

#include "com_defs.h"


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


#ifndef _WIN32  // on Linux/Mac

  class BRXEXPORT ITypeInfo : public IUnknown
  {
  public:

      ITypeInfo () {};
      ITypeInfo (const OdDbObjectId & objId, const CadObjectType objectType)
          : IUnknown(objId, objectType)
      {
      };
      ITypeInfo (const void * obj, const CadObjectType objectType)
          : IUnknown(obj, objectType)
      {
      };
      virtual ~ITypeInfo () {};

  };

  typedef ITypeInfo*  LPTYPEINFO;

#endif // !_WIN32

#endif // _BS_COM_ITYPEINFO_INCLUDED_
