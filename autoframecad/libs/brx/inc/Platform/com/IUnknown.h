// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// COM IUnknown class and related functionality

#ifndef _BS_COM_IUNKNOWN_INCLUDED_
#define _BS_COM_IUNKNOWN_INCLUDED_

#include "com_defs.h"


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


#ifndef _WIN32  // on Linux/Mac

  class BRXEXPORT IUnknown
  {
  public:

      IUnknown ();
      IUnknown (const DbObjectId & objId, const CadObjectType objectType);
      IUnknown (const void * obj);      
      IUnknown (const void * obj, const CadObjectType objectType);
      virtual ~IUnknown () {};

      virtual ULONG AddRef  ();
      virtual ULONG Release ();
      virtual HRESULT QueryInterface (REFIID iid, void **ppvObject);

      virtual const LPOBJECTDESC   objDesc ();
      virtual REFGUID              objGUID ();
      virtual const DbObjectId     objectId ();
      virtual const void *         object ();
      virtual const CadObjectType  type ();
      virtual const LPCTSTR        desc ();
      virtual const LPCTSTR        docs ();
      virtual const bool           isCollection ();
      virtual const bool           isDBRO ();
      virtual const LPPROPERTY *   properties ();
      virtual const LPMETHOD   *   methods ();

      virtual const LPPROPERTY     findProperty  (const CadObjectProperty eProperty);
      virtual const LPPROPERTY     findProperty  (LPCTSTR szProperty);
      virtual const LPMETHOD       findMethod    (const CadObjectMethod eMethod);
      virtual const LPMETHOD       findMethod    (LPCTSTR szMethod);

  private:
      const void*    m_object;
      LPOBJECTDESC   m_objectDesc;

  private:
      ULONG  m_refCount;
  };

  typedef IUnknown*  LPUNKNOWN;


#endif // !_WIN32

#endif // _BS_COM_IUNKNOWN_INCLUDED_
