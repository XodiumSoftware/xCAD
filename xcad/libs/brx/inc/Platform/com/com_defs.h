// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// COM types definitions

#ifndef _BS_COM_DEFS_INCLUDED_
#define _BS_COM_DEFS_INCLUDED_

// ========== Platform independent =======

#include "Platform/sys_headers.h"


// ========== Platform specific ==========

#ifdef _WIN32 // on Windows

  #include "OAIdl.h"   // standard Windows COM definitions

#endif // _WIN32

#ifndef _WIN32 // on Linux/Mac

  // COM related declarations + definitions

  // calling conventions and related
  #define  __RPC_API   __stdcall
  #define  __RPC_USER  __stdcall
  #define  __RPC_STUB  __stdcall
  #define  __RPC_FAR   // ignore
  #define  RPC_ENTRY   __stdcall
  #define  interface   class  // we treat COM interfaces like classes

  typedef struct _RPC_MESSAGE  RPC_MESSAGE;
  typedef _RPC_MESSAGE*       PRPC_MESSAGE;
  class IRpcStubBuffer;
  class IRpcChannelBuffer;

  // MIDL related stuff
  typedef void __RPC_FAR* RPC_IF_HANDLE;
  extern "C" void * __RPC_USER MIDL_user_allocate(size_t);
  extern "C" void __RPC_USER MIDL_user_free( void * ); 


  // functions and structures wrappers
  typedef WCHAR           OLECHAR;
  typedef OLECHAR       * LPOLESTR;
  typedef const OLECHAR * LPCOLESTR;
  typedef OLECHAR       * BSTR;
  typedef OLECHAR      ** PBSTR;
  typedef OLECHAR      ** LPBSTR;
  #define OLESTR(str)     L##str
  #define BSTR2TSTR(x)    (x)  // no string conversion in UNICODE nessecary

  typedef double DATE;

  typedef LONG   DISPID;
  typedef ULONG  PROPID;
  typedef DISPID MEMBERID;
  typedef DWORD  HREFTYPE;
  typedef int32_t  SCODE;
  typedef DWORD  OLE_COLOR;

  typedef bool  _VARIANT_BOOL;  // obsolete
  typedef short  VARIANT_BOOL;
  typedef unsigned short VARTYPE;

  // forward declaration

  typedef struct tagVARIANT  VARIANT;
  typedef VARIANT   VARIANTARG;
  typedef VARIANT * LPVARIANT;
  typedef VARIANT * LPVARIANTARG;

  typedef struct tagSAFEARRAY  SAFEARRAY;
  typedef SAFEARRAY * LPSAFEARRAY;

  typedef struct tagDISPPARAMS  DISPPARAMS;
  typedef DISPPARAMS * LPDISPPARAMS;

  typedef struct tagTYPEDESC  TYPEDESC;
  typedef TYPEDESC * LPTYPEDESC;

  typedef struct tagPARAMDESC  PARAMDESC;
  typedef PARAMDESC * LPPARAMDESC;

  typedef struct tagPARAMDESCEX  PARAMDESCEX;
  typedef PARAMDESCEX * LPPARAMDESCEX;

  typedef struct tagELEMDESC  ELEMDESC;
  typedef ELEMDESC * LPELEMDESC;

  typedef struct tagTYPEATTR  TYPEATTR;
  typedef TYPEATTR * LPTYPEATTR;

  typedef struct tagFUNCDESC  FUNCDESC;
  typedef FUNCDESC * LPFUNCDESC;

  typedef struct tagIDLDESC  IDLDESC;
  typedef IDLDESC * LPIDLDESC;

  typedef struct tagEXCEPINFO  EXCEPINFO;
  typedef EXCEPINFO * LPEXCEPINFO;

  // TypeLib related definitions
  #define PARAMFLAG_NONE          (0x00)
  #define PARAMFLAG_FIN           (0x01)
  #define PARAMFLAG_FOUT          (0x02)
  #define PARAMFLAG_FLCID         (0x04)
  #define PARAMFLAG_FRETVAL       (0x08)
  #define PARAMFLAG_FOPT          (0x10)
  #define PARAMFLAG_FHASDEFAULT   (0x20)
  #define PARAMFLAG_FHASCUSTDATA  (0x40)

  #define IDLFLAG_NONE     PARAMFLAG_NONE
  #define IDLFLAG_FIN      PARAMFLAG_FIN
  #define IDLFLAG_FOUT     PARAMFLAG_FOUT
  #define IDLFLAG_FLCID    PARAMFLAG_FLCID
  #define IDLFLAG_FRETVAL  PARAMFLAG_FRETVAL


  class IUnknown;
  class IDispatch;
  class IRecordInfo;
  typedef IUnknown  * LPUNKNOWN;
  typedef IDispatch * LPDISPATCH;


  typedef struct _GUID
  {
      unsigned long  Data1;
      unsigned short Data2;
      unsigned short Data3;
      unsigned char  Data4[8];
  } GUID;

  typedef GUID  IID;
  typedef const GUID& REFGUID;
  typedef const IID&  REFIID;
  typedef const GUID* LPCGUID;
  typedef GUID* LPGUID;
  typedef IID*  LPIID;

  #define __IID_DEFINED__  // indicates existing IID structure & type

  #undef CLSID
  typedef GUID   CLSID;
  typedef CLSID* LPCLSID;
  typedef const CLSID&  REFCLSID;

  static const IID    GUID_NULL = { 0x00000000L, 0x0000, 0x0000, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } };
  #define IID_NULL    GUID_NULL
  #define CLSID_NULL  GUID_NULL

  #define CLSID_DEFINED  // indicates existing CLSID structure & type

  static const IID  IID_IUNKNOWN  = { 0x00000000L, 0x0000, 0x0000, { 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 } };
  static const IID  IID_IUnknown  = { 0x00000000L, 0x0000, 0x0000, { 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 } };
  static const IID  IID_IDISPATCH = { 0x00020400L, 0x0000, 0x0000, { 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 } };
  static const IID  IID_IDispatch = { 0x00020400L, 0x0000, 0x0000, { 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 } };


  typedef struct tagCALPOLESTR
  {
    ULONG         cElems;
    LPOLESTR FAR* pElems;
  } CALPOLESTR;

  typedef struct tagCADWORD
  {
    ULONG      cElems;
    DWORD FAR* pElems;
  } CADWORD;


  // Windows COM uses GUIDs as attributes to classes, interfaces, enums etc.
  // but those GUIDs establish connections to Registry and "out-of-process" COM objects,
  // we we only manage "in-process" communication;
  // thus, those GUIDs are optional only, and connections is made by runtime type
  #define  DECLSPEC_SELECTANY  //  __declspec(selectany)
  #define  DECLSPEC_NOVTABLE   //  __declspec(novtable)
  #define  DECLSPEC_UUID(x)    //  __declspec(uuid(x))
  #define  MIDL_INTERFACE(x)   struct  // struct DECLSPEC_UUID(x) DECLSPEC_NOVTABLE
  #define  uuid(x)             // we ignore GUID attributes for COM objects

  #define  STDAPICALLTYPE           // __stdcall //__attribute__((regparm(3), stdcall))
  #define  STDMETHODCALLTYPE        // __stdcall // __attribute__((regparm(3), stdcall))

  #define  STDAPI                   EXTERN_C HRESULT STDAPICALLTYPE
  #define  STDAPI_(type)            EXTERN_C type STDAPICALLTYPE
  #define  STDMETHOD(method)        virtual HRESULT STDMETHODCALLTYPE method
  #define  STDMETHOD_(type,method)  virtual type STDMETHODCALLTYPE method
  #define  STDMETHODIMP             HRESULT STDMETHODCALLTYPE
  #define  STDMETHODIMP_(type)      type STDMETHODCALLTYPE

  #define  BEGIN_INTERFACE          // originally empty with _cplusplus
  #define  END_INTERFACE            // originally empty with _cplusplus


  #ifdef DEFINE_GUID
  #undef DEFINE_GUID
  #endif

  #ifdef INITGUID
    #define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
                        EXTERN_C const GUID DECLSPEC_SELECTANY name = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
  #else
    #define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
                        EXTERN_C const GUID FAR name
  #endif // INITGUID


  BRXEXPORT HRESULT StringFromCLSID  (REFCLSID clsid, LPOLESTR * outString);
  BRXEXPORT HRESULT StringFromIID    (REFIID   iid,   LPOLESTR * outString);
  BRXEXPORT HRESULT StringFromGUID   (REFGUID  guid,  LPOLESTR outString);
  BRXEXPORT int     StringFromGUID2  (REFGUID  guid,  LPOLESTR outString, int maxChars);

  BRXEXPORT HRESULT CLSIDFromString   (LPOLESTR lpsz, LPCLSID pclsid);
  BRXEXPORT HRESULT CLSIDFromProgID   (LPCOLESTR lpszProgID, LPCLSID lpclsid);
  BRXEXPORT HRESULT CLSIDFromProgIDEx (LPCOLESTR lpszProgID, LPCLSID lpclsid);
  BRXEXPORT HRESULT IIDFromString     (LPOLESTR lpsz, LPIID lpiid);
  BRXEXPORT BOOL    CoIsOle1Class     (REFCLSID rclsid);
  BRXEXPORT HRESULT ProgIDFromCLSID   (REFCLSID clsid, LPOLESTR* lplpszProgID);


  #define _GUIDDEF_H_

  // ----- forwards to internal implementations -----
  typedef  class OdDbObjectId  DbObjectId;

  #define CadObjectType      unsigned int  // enum forward
  #define CadObjectProperty  unsigned int  // enum forward
  #define CadObjectMethod    unsigned int  // enum forward


  struct _tlProperty;
  typedef _tlProperty* LPPROPERTY;

  struct _tlMethod;
  typedef _tlMethod* LPMETHOD;

  struct cadObjectsDesc;
  typedef cadObjectsDesc* LPOBJECTDESC;

  struct OBJECT;
  #define POINTER   OBJECT*
  #define CPOINTER  const OBJECT*

#endif // !_WIN32 - Linux/Mac


#endif // _BS_COM_DEFS_INCLUDED_
