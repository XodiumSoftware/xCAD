// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// COM ITypeInfo class and related functionality

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
