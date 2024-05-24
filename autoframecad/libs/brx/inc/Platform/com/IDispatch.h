// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// COM IDispatch class and related functionality

#ifndef _BS_COM_IDISPATCH_INCLUDED_
#define _BS_COM_IDISPATCH_INCLUDED_

#include "com_defs.h"


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


#ifndef _WIN32  // on Linux/Mac

  /* Flags for IDispatch::Invoke */
  #define DISPATCH_METHOD          0x1
  #define DISPATCH_PROPERTYGET     0x2
  #define DISPATCH_PROPERTYPUT     0x4
  #define DISPATCH_PROPERTYPUTREF  0x8

  #define DISPID_VALUE       ( 0)
  #define DISPID_UNKNOWN     (-1)
  #define DISPID_PROPERTYPUT (-3)
  #define DISPID_NEWENUM     (-4)
  #define DISPID_EVALUATE    (-5)
  #define DISPID_CONSTRUCTOR (-6)
  #define DISPID_DESTRUCTOR  (-7)
  #define DISPID_COLLECT     (-8)
  #define MEMBERID_NIL       DISPID_UNKNOWN
  #define ID_DEFAULTINST     (-2)


  typedef struct tagDISPPARAMS
  {
      VARIANTARG * rgvarg;            // Array of arguments.
      DISPID     * rgdispidNamedArgs; // Dispatch IDs of named arguments.
      unsigned int cArgs;             // Number of arguments.
      unsigned int cNamedArgs;        // Number of named arguments.
  } DISPPARAMS;

  typedef enum tagCALLCONV
  {
      CC_FASTCALL = 0,
      CC_CDECL    = 1,
      CC_MSCPASCAL,
      CC_PASCAL,
      CC_MACPASCAL,
      CC_STDCALL,
      CC_FPFASTCALL,
      CC_SYSCALL,
      CC_MPWCDECL,
      CC_MPWPASCAL,
      CC_MAX
  } CALLCONV;

  typedef enum tagFUNCKIND
  {
      FUNC_VIRTUAL = 0,
      FUNC_PUREVIRTUAL,
      FUNC_NONVIRTUAL,
      FUNC_STATIC,
      FUNC_DISPATCH
  } FUNCKIND;

  typedef enum tagINVOKEKIND
  {
      INVOKE_FUNC           = DISPATCH_METHOD,
      INVOKE_PROPERTYGET    = DISPATCH_PROPERTYGET,
      INVOKE_PROPERTYPUT    = DISPATCH_PROPERTYPUT,
      INVOKE_PROPERTYPUTREF = DISPATCH_PROPERTYPUTREF
  } INVOKEKIND;

  typedef enum tagTYPEKIND
  {   TKIND_ENUM  = 0,
      TKIND_RECORD,
      TKIND_MODULE,
      TKIND_INTERFACE,
      TKIND_DISPATCH,
      TKIND_COCLASS,
      TKIND_ALIAS,
      TKIND_UNION,
      TKIND_MAX
  } TYPEKIND;

  typedef enum tagVARKIND
  {
      VAR_PERINSTANCE = 0,
      VAR_STATIC,
      VAR_CONST,
      VAR_DISPATCH,
  } VARKIND;

  typedef struct tagTYPEDESC
  {
      union
      {
          struct tagTYPEDESC *lptdesc;
          struct tagARRAYDESC *lpadesc;
          HREFTYPE hreftype;
      };
      VARTYPE vt;
  } TYPEDESC;

  typedef struct tagPARAMDESC
  {
      LPPARAMDESCEX pparamdescex;
      USHORT wParamFlags;
  } PARAMDESC;

  typedef struct tagPARAMDESCEX
  {
      ULONG cBytes;
      VARIANTARG varDefaultValue;
  } PARAMDESCEX;

  typedef struct tagIDLDESC
  {
      ULONG_PTR dwReserved;
      USHORT wIDLFlags;
  } IDLDESC;

  typedef struct tagELEMDESC
  {
      TYPEDESC tdesc;
      union
      {
          IDLDESC idldesc;
          PARAMDESC paramdesc;
      };
  } ELEMDESC;

  typedef struct tagTYPEATTR
  {
      GUID guid;
      LCID lcid;
      DWORD dwReserved;
      MEMBERID memidConstructor;
      MEMBERID memidDestructor;
      LPOLESTR lpstrSchema;
      ULONG cbSizeInstance;
      TYPEKIND typekind;
      WORD cFuncs;
      WORD cVars;
      WORD cImplTypes;
      WORD cbSizeVft;
      WORD cbAlignment;
      WORD wTypeFlags;
      WORD wMajorVerNum;
      WORD wMinorVerNum;
      TYPEDESC tdescAlias;
      IDLDESC idldescType;
  } TYPEATTR;

  typedef struct tagFUNCDESC
  {
      MEMBERID memid;
      SCODE *lprgscode;
      ELEMDESC *lprgelemdescParam;
      FUNCKIND funckind;
      INVOKEKIND invkind;
      CALLCONV callconv;
      SHORT cParams;
      SHORT cParamsOpt;
      SHORT oVft;
      SHORT cScodes;
      ELEMDESC elemdescFunc;
      WORD wFuncFlags;
  } FUNCDESC;


  typedef struct tagEXCEPINFO
  {
      WORD  wCode;
      WORD  wReserved;
      BSTR  bstrSource;
      BSTR  bstrDescription;
      BSTR  bstrHelpFile;
      DWORD dwHelpContext;
      PVOID pvReserved;
      HRESULT (__stdcall *pfnDeferredFillIn)(struct tagEXCEPINFO *pInfo);
      SCODE scode;
  } EXCEPINFO;


  class ITypeInfo;  // forward

  class BRXEXPORT IDispatch : public IUnknown
  {
  public:
      IDispatch ();
      IDispatch (const DbObjectId & objId, const CadObjectType objectType);
      IDispatch (const void * obj, const CadObjectType objectType);
      virtual ~IDispatch () {};

      virtual HRESULT GetTypeInfoCount (UINT *pctinfo);

      virtual HRESULT GetTypeInfo (UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);

      // 'riid' is ignored, 'lcid' is ignored
      virtual HRESULT GetIDsOfNames (REFIID riid, LPOLESTR * rgszNames, UINT cNames,
                                     LCID lcid, DISPID *rgDispId);

      virtual HRESULT Invoke (DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
                              DISPPARAMS * pDispParams, VARIANT * pVarResult,
                              EXCEPINFO * pExcepInfo, UINT * puArgErr);

      // COM property/method calls (fast Lisp)
      virtual HRESULT lispProperty (CPOINTER lispObject,  LPCTSTR szProperty,
                                    const bool bPutValue, POINTER & lispValue,
                                    const int nArgs = 0, const bool allowErased = false);

      virtual HRESULT lispMethod   (CPOINTER lispObject, LPCTSTR szMethod,
                                    POINTER & lispValue,
                                    const int nArgs = 0, const bool allowErased = false);

      // COM property/method calls (standard)
      virtual HRESULT getProperty  (LPCTSTR szProperty,
                                    const DISPPARAMS * pDispParams, VARIANT * pVarResult);
      virtual HRESULT getProperty  (const CadObjectProperty eProperty,
                                    const DISPPARAMS * pDispParams, VARIANT * pVarResult);

      virtual HRESULT putProperty  (LPCTSTR szProperty,
                                    const DISPPARAMS * pDispParams, VARIANT * pVarResult);
      virtual HRESULT putProperty  (const CadObjectProperty eProperty,
                                    const DISPPARAMS * pDispParams, VARIANT * pVarResult);

      virtual HRESULT invMethod    (LPCTSTR szProperty,
                                    const DISPPARAMS * pDispParams, VARIANT * pVarResult);
      virtual HRESULT invMethod    (const CadObjectMethod eMethod,
                                    const DISPPARAMS * pDispParams, VARIANT * pVarResult);
  };

  typedef IDispatch*  LPIDISPATCH;


  // global COM accessor functions

  HRESULT DispInvoke (void * pIDispatch, ITypeInfo * pTypeInfo, DISPID dispidMember,
                      unsigned short wFlags, DISPPARAMS * pDispParams, VARIANT * pVarResult,
                      EXCEPINFO * pExceptionInfo, unsigned int * puArgErr);

  HRESULT DispGetIDsOfNames (ITypeInfo * ptinfo, OLECHAR ** rgszNames, unsigned int cNames,
                             DISPID * rgdispid);



#endif // !_WIN32

#endif // _BS_COM_IDISPATCH_INCLUDED_
